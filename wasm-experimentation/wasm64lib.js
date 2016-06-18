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

function StringAt(heap, offset, length)
{
    var ret = '';

    for (var i0 = offset; i0 - offset < length; i0++) {
        ret += String.fromCharCode(heap[i0] || 0x20);
        //ret += heap[i0].toString(16);
    }

    return ret;
}

function hex64(x)
{
    if (x.high == 0)
        return x.low.toString(16);
    else {
        low = x.low.toString(16);
        while (low.length < 8)
            low = "0" + low;
        return x.high.toString(16) + low;
    }
}

function dump(addr)
{
    console.log('starting at ' + addr);

    var diff;

    for (diff = 0; diff < 512; diff += 4) {
        console.log(diff.toString(16) + ": " + HEAPU32[addr+diff>>2].toString(16));
    }
}

imprts.console = {};
imprts.console.print = function (x) { console.log(hex64(x)); };

var counter = 0;

imprts.thinthin = {};
imprts.thinthin.extcall = function (r0, r1, a0, a1) {
    logi64(r0);
    logi64(r1);
    logi64(a0);
    logi64(a1);
    dump(a1.low);
    console.log(CStringAt(new Uint8Array(w.exports.memory), r0.low));
    console.log(CStringAt(new Uint8Array(w.exports.memory), r1.low));
    console.log(HEAPU32[a1.low + 0x20 >> 2]);
    console.log(HEAPU32[a1.low + 0x28 >> 2]);
    console.log(HEAPU32[a1.low + 0x30 >> 2]);
    var name = CStringAt(new Uint8Array(w.exports.memory), r1.low);

    HEAPU32[4096>>2] = -1;
    HEAPU32[4100>>2] = -1;

    console.log(CStringAt(HEAPU8, 0x161ec));
    if (name == "write") {
        console.log(CStringAt(HEAPU8, HEAPU32[a1.low + 0x28 >> 2]));
        console.log(StringAt(HEAPU8, HEAPU32[a1.low + 0x28 >> 2], HEAPU32[a1.low+0x30>>2]));
        console.log(CStringAt(HEAPU8, HEAPU32[a1.low + 0x28 >> 2] + 23));
        HEAPU32[4096>>2] = HEAPU32[a1.low + 0x30 >> 2];
        HEAPU32[4100>>2] = 0;
    } else if (name == "fcntl_v") {
        HEAPU32[4096>>2] = 2;
        HEAPU32[4100>>2] = 0;
    } else
        HEAPU32[4096>>2] = -1;
    if (name == "exit")
        throw 0;
    console.log(counter);
    if (counter++ & 1)
        return {low: 0, high: 0}; //3;
    else
        return {low: 0, high: 0};
};

imprts.thinthin.indcall = function (dpc, sp, r0, r1, rpc, pc0) {
    console.log("indcall " + rpc.high.toString(16) + " " + rpc.low.toString(16));
    console.log("indcall " + pc0.high.toString(16) + " " + pc0.low.toString(16));
    HEAPU32[4096>>2] = 0;
    HEAPU32[4100>>2] = 0;

    if (pc0.low == 0 && pc0.high == 0)
        return { low: 0, high: 0 };

    return w.exports["f_0x" + hex64(pc0) + "0"](dpc, sp, r0, r1, rpc, pc0);
};

imprts.thinthin.eh_return = function (a0, a1, a2) {
    return 0;
};

function ddouble(lo, hi) {
    hi = hi | 0;
    lo = lo >>> 0;
    return [(hi*0x100000000+lo),(lo-((hi*0x100000000+lo)&0xffffffff))|0];
}

function logi64(x)
{
    console.log(hex64(x));
}

var stage = 0;
var data;
if (typeof window === "undefined") {
    var ab = os.file.readFile("wasm.data", "binary");
    var i;

    data = new Uint8Array(ab);

    w = Wasm.instantiateModule(os.file.readFile("wasm.wasm", "binary"), imprts);

    var oh = HEAPU8 = new Uint8Array(w.exports.memory);
    HEAPU32 = new Uint32Array(w.exports.memory);
    for (i = 0; i < data.byteLength; i++)
        oh[16384 + 0x40 + i] = data[i];

    logi64(w.exports.f_0x4000000000025000({ low: 0, high: 0}, {low: 2*1024*1024, high: 0 }, { low: 0, high: 0 }, { low: 0, high: 0 }, {low: 0, high: 0 }, {low: 0x2500, high: 0x4000000 }));
} else {
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
            console.log(w.exports.f_0x4000000000025000({ low: 0, high: 0}, {low: 2*1024*1024, high: 0 }, { low: 0, high: 0 }, { low: 0, high: 0 }, {low: 0, high: 0 }, {low: 0x2500, high: 0x4000000 }));
        }
    }, 5000);
}
