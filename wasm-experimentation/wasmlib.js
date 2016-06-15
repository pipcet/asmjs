var w;
var imprts = {};
var HEAPU8;
var HEAPU32;

function CStringAt(heap, offset)
{
    var ret = '';

    for (var i0 = offset; heap[i0]; i0++) {
        ret += String.fromCharCode(heap[i0]);
    }

    return ret;
}

imprts.console = {};
imprts.console.print = function (x) { console.log(x); };

var counter = 0;

imprts.thinthin = {};
imprts.thinthin.extcall = function (r0, r1, a0, a1) {
    console.log(r0);
    console.log(r1);
    console.log(a0);
    console.log(a1);
    console.log(CStringAt(new Uint8Array(w.exports.memory), r0));
    console.log(CStringAt(new Uint8Array(w.exports.memory), r1));
    console.log(CStringAt(HEAPU8, HEAPU32[a1 + 28 >> 2]));

    console.log(counter);
    if (counter++ & 1)
        return 3;
    else
        return 0;
};

imprts.thinthin.indcall = function (r0, r1, a0, a1, x0, x1) {
    return 0;
};

var stage = 0;
var data;
fetch("file:///home/pip/git/asmjs/wasm-experimentation/wasm.data").then(p => p.arrayBuffer()).then(ab => {
    var i;
    var heap = new Uint8Array(ab);

    data = heap;
})


window.setInterval(function () {
    if (stage == 0) {
        if (data) {
            fetch("file:///home/pip/git/asmjs/wasm-experimentation/wasm.wasm").then(p => p.arrayBuffer()).then(b => b).then(ab => w = Wasm.instantiateModule(new Uint8Array(q = ab), imprts));
            stage = 1;
        }
    } else if (stage == 1) {
        if (w) {
            var i;
            var oh = HEAPU8 = new Uint8Array(w.exports.memory);
            HEAPU32 = new Uint32Array(w.exports.memory);
            for (i = 0; i < data.byteLength; i++)
                oh[16384 + 0x40 + i] = data[i];
            stage = 2;
        }
    } else if (stage == 2) {
        console.log(w.exports.f_0x40011000(0, 1024, 0, 0, 0, 0));
    }
}, 5000);
