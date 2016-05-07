function VT100Cell()
{
    this.dom_ = document.createElement("span");
    this.dom_.innerHTML = " ";

    this.dom_.style.color = "black";
    this.dom_.style.background = "white";
    this.dom_.style.weight = "normal";
}

VT100Cell.prototype.invert = function ()
{
    [this.dom_.style.color, this.dom_.style.background] =
        [this.dom_.style.background, this.dom_.style.color];
};

VT100Cell.prototype.css = function ()
{
    return "color: " + this.color + "; background: " + this.background + "; weight: " + this.weight;
};

VT100Cell.prototype.html = function ()
{
    return "<span style=\"" + this.css() + "\">" + this.text + "</span>";
};

VT100Cell.prototype.dom = function ()
{
    return this.dom_;
};

VT100Cell.prototype.write = function (text, opts)
{
    var style_changed = false;
    this.dom_.innerHTML = text;
    this.dom_.style.color = opts.color;
    this.dom_.style.background = opts.background;
    this.dom_.style.weight = opts.weight;
};

function VT100Matrix(context)
{
    this.context = context;

    this.cells = [];
    for (var y = 0; y < context.height; y++) {
        var line = [];
        for (var x = 0; x < context.width; x++)
            line.push(new VT100Cell());
        this.cells.push(line);
    }
}

VT100Matrix.prototype.dom = function ()
{
    var ret = document.createElement("div");

    for (var y = 0; y < this.cells.length; y++) {
        var cellline = this.cells[y];
        var line = document.createElement("div");
        for (var x = 0; x < cellline.length; x++) {
            var cell = cellline[x];

            line.appendChild(cell.dom());
        }
        ret.appendChild(line);
    }

    return ret;
};

VT100Matrix.prototype.html = function ()
{
    var str = "";

    for (var y = 0; y < this.cells.length; y++) {
        var line = this.cells[y];
        for (var x = 0; x < line.length; x++) {
            var cell = line[x];

            if (x == this.context.x &&
                y == this.context.y)
                cell.invert();

            str += cell.html();

            if (x == this.context.x &&
                y == this.context.y)
                cell.invert();
        }
        str += "\n";
    }

    return str;
};

function VT100Context()
{
    this.x = 0;
    this.y = 0;
    this.height = 25;
    this.width = 80;

    this.color = "black";
    this.background = "white";
    this.weight = "normal";

    this.matrix = new VT100Matrix(this);
    this.showCursor();
}

VT100Context.prototype.write = function (c, x = undefined, y = undefined)
{
    if (x === undefined)
        x = this.x;
    if (y === undefined)
        y = this.y;
    var cell = this.matrix.cells[y][x];

    cell.write(c, {
        color: this.color,
        background: this.background,
        weight: this.weight
    });
};

VT100Context.prototype.hideCursor = function ()
{
    var cell = this.matrix.cells[this.y][this.x];
    cell.invert();
};

VT100Context.prototype.showCursor = function ()
{
    var cell = this.matrix.cells[this.y][this.x];
    cell.invert();
};

function VT100FD(process, domparent, fdno = undefined, outfdno = undefined)
{
    ThinThinFD.call(this, process, fdno);
    this.domparent = domparent;
    this.lines = [];

    this.dom = document.createElement("pre");
    this.domparent.appendChild(this.dom);

    this.context = new VT100Context();
    this.dom.appendChild(this.context.matrix.dom());

    this.state = "initial";

    if (outfdno !== undefined) {
        this.outfd = new ThinThinFD(process, outfdno);

        if (0) document.addEventListener("keypress", e => {
            if (this.domparent.contains(e.target) ||
                e.target.contains(this.domparent)) {
                var str = e.key;
                switch (e.key) {
                case "Enter":
                    str = "\r"; break;
                case "Escape":
                    str = "\u001b"; break;
                case "Backspace":
                    str = "\u0008"; break;
                default:
                    break;
                }
                if (str.length == 1 && e.ctrlKey)
                    str = String.fromCharCode(str.charCodeAt(0) & 0x1f);
                this.outfd.stuff(str);
                e.preventDefault();
                e.stopPropagation();
            }
        });
    }
}
VT100FD.prototype = Object.create(ThinThinFD.prototype);

VT100FD.prototype.refresh = function ()
{
    return;
};

VT100FD.prototype.triggerRefresh = function ()
{
    if (this.refreshTriggered)
        return;

    this.refreshTriggered = true;
    window.setTimeout(this.refresh.bind(this), 1000.0);
};

VT100FD.prototype.outputPromise = function (heap, ptr, len)
{
    var m, i;

    if (len <= 0)
        return Promise.resolve(len);

    this.context.hideCursor();
    for (i=0; i<len; i++) {
        var data = String.fromCharCode(heap[ptr+i]);

        //this.domparent.appendChild(document.createTextNode(data.charCodeAt(0) < 0x20 ? ("\n" + data.charCodeAt(0)) : data));

        switch (this.state) {
        case "initial":
            if (data == "\u001b") {
                this.state = "escape";
                this.escapeSequence = "";
            } else if (data == "\u0007") {
                /* BEL */
            } else if (data == "\u0008") {
                this.context.x--;
            } else if (data == "\n") {
                this.context.y++;
            } else if (data == "\r") {
                this.context.x = 0;
            } else if (data == "\t") {
                this.context.x += 8;
                this.context.x &= -8;
            } else {
                this.context.write(data);
                this.context.x++;
                this.triggerRefresh();
            }
            while (this.context.x < 0) {
                this.context.x += 80;
                //this.y--;
            }
            while (this.context.y < 0)
                this.context.y = 0;
            if (this.context.x >= 80) {
                this.context.x = 0;
                //this.y++;
            }
            break;
        case "escape":
            this.escapeSequence += data;
            if (m = this.escapeSequence.match(/^\[(\d*);(\d*)[fH]$/)) {
                if (m[1] !== "")
                    this.context.y = m[1] - 1;
                if (m[2] !== "")
                    this.context.x = m[2] - 1;
            } else if (m = this.escapeSequence.match(/^\[[fH]$/)) {
                this.context.x = 0;
                this.context.y = 0;
            } else if (m = this.escapeSequence.match(/^\[(\d*)A$/)) {
                if (m[1] !== "")
                    this.context.y -= m[1];
                else
                    this.context.y -= 1;
            } else if (m = this.escapeSequence.match(/^\[(\d*)B$/)) {
                if (m[1] !== "")
                    this.context.y += m[1];
                else
                    this.context.y += 1;
            } else if (m = this.escapeSequence.match(/^\[(\d*)C$/)) {
                if (m[1] !== "")
                    this.context.x += m[1];
                else
                    this.context.x += 1;
            } else if (m = this.escapeSequence.match(/^\[(\d*)D$/)) {
                if (m[1] !== "")
                    this.context.x -= m[1];
                else
                    this.context.x -= 1;
            } else if (m = this.escapeSequence.match(/^\[K$/)) {
                for (var x = this.context.x; x < 80; x++)
                    this.context.write(" ", x, this.context.y);
            } else if (m = this.escapeSequence.match(/^\[J$/)) {
                var x, y;
                for (y = this.y; y < 25; y++) {
                    for (x = 0; x < 80; x++)
                        this.context.write(" ", x, y);
                }
            } else if (m = this.escapeSequence.match(/^\[\?1h$/)) {
                /* set cursor keys to application */
            } else if (m = this.escapeSequence.match(/^=$/)) {
                /* set keypad mode */
            } else if (m = this.escapeSequence.match(/^\($/)) {
            } else if (m = this.escapeSequence.match(/^\)$/)) {
            } else if (m = this.escapeSequence.match(/^\[\?7h$/)) {
            } else if (m = this.escapeSequence.match(/^\[\?7l[01]$/)) {
            } else if (m = this.escapeSequence.match(/^\[(\d*;)*(\d*)m$/)) {
            } else if (m = this.escapeSequence.match(/^\[(\d*);(\d*)r$/)) {
                this.scrollY0 = m[1] - 1;
                this.scrollY1 = m[2];
            } else if (m = this.escapeSequence.match(/^M$/)) {
                // var y;
                // for (y = this.scrollY1; y >= this.scrollY0-1 && y; y--) {
                //     this.lines[y] = "";
                //     while (this.lines[y].length < 80)
                //         this.lines[y] += " ";
                //     this.lines[y] += "\n";
                // }
            } else if (m = this.escapeSequence.match(/^D$/)) {
                // var y;
                // for (y = this.scrollY0; y < this.scrollY1 - 1; y++)
                //     this.lines[y] = this.lines[y+1];
            } else if (this.escapeSequence.length >= 10) {
                console.log("unknown escape sequence " + this.escapeSequence);
            } else {
                break;
            }

            this.state = "initial";
            this.escapeSequence = "";
            this.triggerRefresh();
        }
    }
    this.context.showCursor();

    return Promise.resolve(len);
};
