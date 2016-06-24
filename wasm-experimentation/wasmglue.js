var HEAP8, HEAPU32;

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

function buildInstance(ab, imports, path)
{
    var HEAPU32, HEAP8;
    var start;

    function importCall()
    {
        var n = HEAPU32[12288>>2];
        var i;
        var args = [];


        console.log('nargs: ' + n);
        for (i = 0; i < n; i++) {
            args.push({
                low:  HEAPU32[12288+(i+1)*8>>2],
                high: HEAPU32[12288+(i+1)*8+4>>2],
            });
        }

        var namep = args.shift().low;
        var name = CStringAt(HEAP8, namep);
        console.log(namep + ': ' + name);

        var ret = imports[name].apply(undefined, args);

        HEAPU32[12288>>2] = ret.low;
        HEAPU32[12292>>2] = ret.high;
    }

    function exportCall()
    {
        start();
    }

    var impobj = {
        console: { print: importCall },
        thinthin: { extcall: importCall, indcall: importCall, eh_return: importCall},
    }

    var instance = Wasm.instantiateModule(ab, impobj, path);

    HEAPU32 = new Uint32Array(instance.exports.memory);
    HEAP8 = new Int8Array(instance.exports.memory);
    start = instance.exports.start;
    return {
        instance: instance,
        exportCall: exportCall,
        HEAP8: HEAP8,
        HEAPU32: HEAPU32,
    };
}

function extcall(a0, a1, a2, a3)
{
    console.log('extcall');
    var mod = CStringAt(HEAP8, a0.low);
    var fun = CStringAt(HEAP8, a1.low);
    var sp = a3.low;

    if (fun == "write") {
        console.log(CStringAt(HEAP8, HEAPU32[sp + 0x28 >> 2]));
        return { low: HEAPU32[sp+0x30 >> 2], high: 0 };
    }

    return { low: 0, high: 0 };
}

w = buildInstance(os.file.readFile("../wasm-experimentation/wasm.wasm", "binary"),
                  {extcall: extcall, log:x =>{ console.log(x); return {low:0, high: 0}}}, "../wasm-experimentation/wasm.so");

HEAP8 = w.HEAP8;
HEAPU32 = w.HEAPU32;

w.instance.exports.start();
