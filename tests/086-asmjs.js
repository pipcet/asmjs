function AsmModule(stdlib, foreign, heap)
{
    "use asm";

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

        return +f3;
    }
    
    return {
        f0: f0,
    };
}

mod = AsmModule(this, {}, new ArrayBuffer(65536));

print(mod.f0(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4));
