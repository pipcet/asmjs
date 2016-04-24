function AsmModule(stdlib, foreign, heap)
{
    "use asm";

    var HEAP8 = new stdlib.Int8Array(heap);
    var HEAP16 = new stdlib.Int16Array(heap);
    var HEAP32 = new stdlib.Int32Array(heap);
    var HEAPU8 = new stdlib.Uint8Array(heap);
    var HEAPU16 = new stdlib.Uint16Array(heap);
    var HEAPU32 = new stdlib.Uint32Array(heap);
    var HEAPF32 = new stdlib.Float32Array(heap);
    var HEAPF64 = new stdlib.Float64Array(heap);

    function f0(pc, sp, fp, ap, r0, r1, r2, r3, i0, i1, i2, i3, f0, f1, f2, f3) {
	pc = pc|0;
	sp = sp|0;
	fp = fp|0;
	ap = ap|0;
	r0 = r0|0;
	r1 = r1|0;
	r2 = r2|0;
	r3 = r3|0;
	i0 = i0|0;
	i1 = i1|0;
	i2 = i2|0;
	i3 = i3|0;
	f0 = +f0;
	f1 = +f1;
	f2 = +f2;
	f3 = +f3;

        mainloop:
        while(1|0) { switch (pc|0) {
            default:
            sp = (sp-80)|0;
            HEAP32[(sp+0)>>2] = pc|0;
            HEAP32[(sp+4)>>2] = (sp+80)|0;
            HEAP32[(sp+8)>>2] = fp|0;
            HEAP32[(sp+12)>>2] = ap|0;
            HEAP32[(sp+16)>>2] = r0|0;
            HEAP32[(sp+20)>>2] = r1|0;
            HEAP32[(sp+24)>>2] = r2|0;
            HEAP32[(sp+28)>>2] = r3|0;
            HEAP32[(sp+32)>>2] = i0|0;
            HEAP32[(sp+36)>>2] = i1|0;
            HEAP32[(sp+40)>>2] = i2|0;
            HEAP32[(sp+44)>>2] = i3|0;
            HEAPF64[(sp+48)>>3] = +f0;
            HEAPF64[(sp+56)>>3] = +f1;
            HEAPF64[(sp+64)>>3] = +f2;
            HEAPF64[(sp+72)>>3] = +f3;
            break mainloop;
        } }

        return sp|0;
    }

    return {
        f0: f0,
    };
}

mod = AsmModule(this, {}, new ArrayBuffer(65536));

print(mod.f0(0, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4));
