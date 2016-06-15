var w;
var imprts = {};

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

imprts.thinthin = {};
imprts.thinthin.extcall = function (r0, r1, a0, a1) {
    console.log(r0);
    console.log(CStringAt(new Uint8Array(w.exports.memory), r0));

    return 0;
};

imprts.thinthin.indcall = function (r0, r1, a0, a1, x0, x1) {
    return 0;
};

fetch("file:///home/pip/git/asmjs/wasm-experimentation/wasm.wasm").then(p => p.arrayBuffer()).then(b => b).then(ab => w = Wasm.instantiateModule(new Uint8Array(q = ab), imprts));

window.setInterval(function () {
    if (w)
        w.exports.f_0x40010000(0, 1024, 0, 0, 0, 0);
}, 5000);
