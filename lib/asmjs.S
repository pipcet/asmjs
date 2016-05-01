#NO_APP
    .macro .hex label
    .reloc .+2,R_ASMJS_HEX16,\label
    .ascii "0x0000000000000000"
    .endm
    .section .special.100
var ret = new AsmJSModule();

ret.top_of_memory = $
    .hex __top_of_memory
;

ret.top_of_stack = ret.top_of_memory;
ret.bottom_of_stack = ret.top_of_stack - 2 * 1024 * 1024;

ret.add_section(new AsmJSDataSection("data", $
    .hex __start_of_data
- 8, [
    .section .special.200
]));

ret.add_section(new AsmJSCodeSection("code",
                                     function (stdlib, foreign, heap) {
    "use asm";

    var HEAP8 = new stdlib.Int8Array(heap);
    var HEAP16 = new stdlib.Int16Array(heap);
    var HEAP32 = new stdlib.Int32Array(heap);
    var HEAPU8 = new stdlib.Uint8Array(heap);
    var HEAPU16 = new stdlib.Uint16Array(heap);
    var HEAPU32 = new stdlib.Uint32Array(heap);
    var HEAPF32 = new stdlib.Float32Array(heap);
    var HEAPF64 = new stdlib.Float64Array(heap);

    var global_data = foreign.global_data|0;
    var bp_addr = foreign.bp_addr|0;
    var bogotics = foreign.bogotics|0;
    var single_stepping = foreign.single_stepping|0;
    var steps = foreign.steps|0;
    var bp_hit = foreign.bp_hit|0;
    var foreign_print = foreign.print;
    var foreign_now = foreign.now;
    var foreign_extcall = foreign.extcall;
    var foreign_indcall2 = foreign.indcall;
    var foreign_abort = foreign.abort;

    var imul = stdlib.Math.imul;
    var fround = foreign.fround;

    //var atomic_store = stdlib.Atomics.store;
    var QNaN = +foreign.QNaN;

    var tp = foreign.tp|0;
    var stop_reason = 0;
    var in_bp = 0;
    var rv = 0;
    var a0 = 0;
    var a1 = 0;
    var a2 = 0;
    var a3 = 0;

    function save_state(threadpage)
    {
        threadpage = threadpage|0;
        HEAP32[threadpage + 0x48>>2] = rv;
        HEAP32[threadpage + 0x50>>2] = a0;
        HEAP32[threadpage + 0x58>>2] = a1;
        HEAP32[threadpage + 0x60>>2] = a2;
        HEAP32[threadpage + 0x68>>2] = a3;
        HEAP32[threadpage + 0x70>>2] = tp;
    }

    function restore_state(threadpage)
    {
        threadpage = threadpage|0;
        rv = HEAP32[threadpage + 0x48>>2]|0;
        a0 = HEAP32[threadpage + 0x50>>2]|0;
        a1 = HEAP32[threadpage + 0x58>>2]|0;
        a2 = HEAP32[threadpage + 0x60>>2]|0;
        a3 = HEAP32[threadpage + 0x68>>2]|0;
        tp = HEAP32[threadpage + 0x70>>2]|0;
    }

    function inAsmJS()
    {
        var ret = 0;

        HEAPF64[0>>3] = 0.0/0.0;
        HEAP32[4>>2] = ((HEAP32[4>>2]|0) + 0x80000000)|0;
        HEAPF64[0>>3] = HEAPF64[0>>3];
        ret = (HEAP32[4>>2] & 0x80000000);
        HEAPF64[0>>3] = +0.0;

        return ret|0;
    }

    function get_arg(i)
    {
        i = i|0;

        if ((i|0) == 0) return a0|0;
        if ((i|0) == 1) return a1|0;
        if ((i|0) == 2) return a2|0;
        if ((i|0) == 3) return a3|0;

        return 0;
    }

    function set_arg(i, v)
    {
        i = i|0;
        v = v|0;

        if ((i|0) == 0) a0 = v|0;
        if ((i|0) == 1) a1 = v|0;
        if ((i|0) == 2) a2 = v|0;
        if ((i|0) == 3) a3 = v|0;
    }

    function get_rv()
    {
        return rv|0;
    }

    function set_rv(v)
    {
        v = v|0;

        rv = v|0;
    }

    function get_bogotics()
    {
        return bogotics|0;
    }

    function set_bogotics(tics)
    {
        tics = tics|0;
        bogotics = tics|0;
    }

    function get_bp_addr()
    {
        return bp_addr|0;
    }

    function set_bp_addr(addr)
    {
        addr = addr|0;
        bp_addr = addr|0;
    }

    function get_single_stepping()
    {
        return single_stepping|0;
    }

    function set_single_stepping(ss)
    {
        ss = ss|0;
        single_stepping = ss|0;
    }

    function get_steps()
    {
        return steps|0;
    }

    function set_steps(s)
    {
        s = s|0;
        steps = s|0;
    }

    function get_bp_hit()
    {
        return bp_hit|0;
    }

    function set_bp_hit(bh)
    {
        bh = bh|0;
        bp_hit = bh|0;
    }

    function call_frame(fp)
    {
        fp = fp|0;

        var pc = 0;
        var sp = 0;

        pc = HEAP32[fp+4>>2]|0;
        sp = HEAP32[fp+8>>2]|0;
        sp = sp-16|0;

        HEAP32[sp>>2] = fp|0;
        HEAP32[sp+4>>2] = fp|0;

        return sp|0;
    }

    function set_in_bp(v)
    {
        v = v|0;

        in_bp = v;
    }

    function get_in_bp()
    {
        return in_bp|0;
    }

    function f_0x0(dpc, sp, r0, r1, rpc, pc0) {
        dpc = dpc|0;
        sp = sp|0;
        r0 = r0|0;
        r1 = r1|0;
        rpc = rpc|0;
        pc0 = pc0|0;

        foreign_abort(1, sp|0, 0, 0, 0);

        rv = 0;

        return sp|0;
    }

    function foreign_indcall(dpc, sp, r0, r1, rpc, pc0) {
        dpc = dpc|0;
        sp = sp|0;
        r0 = r0|0;
        r1 = r1|0;
        rpc = rpc|0;
        pc0 = pc0|0;

        var pc = 0;

        pc = dpc+pc0|0;

        switch (pc>>8) {
   .section .special.300
        default:
            return foreign_indcall2(dpc|0, sp|0, r0|0, r1|0, rpc|0, pc0|0)|0;
        }
        return 0;
    }

    function indcall(dpc, sp, r0, r1, rpc, pc0) {
        dpc = dpc|0;
        sp = sp|0;
        r0 = r0|0;
        r1 = r1|0;
        rpc = rpc|0;
        pc0 = pc0|0;

        return foreign_indcall(dpc|0, sp|0, r0|0, r1|0, rpc|0, pc0|0)|0;
    }

    function rrds(pc, sp, initsp) {
        pc = pc|0;
        sp = sp|0;
        initsp = initsp|0;

        var r0 = 0;
        var r1 = 0;
        var cpc = 0;
        var ppc = 0;
        var rp = 0;

        do {
            if ((pc|0) == 0) {
                cpc = HEAP32[sp+4>>2]>>4;
            } else {
                cpc = pc|0;
            }

            rp = foreign_indcall(pc|0, sp|0, r0|0, r1|0, pc|0, 0)|0;

            sp = HEAP32[rp+4>>2]|0;
            pc = 0;

            if ((rp|3) >= (initsp|3))
                return initsp|0;

            if ((rp&3) == 2)
                return sp|0;
        } while(0);

        return sp|0;
    }

    function set_stopped(reason)
    {
        reason = reason|0;

        stop_reason = reason|0;
    }

    function get_stopped()
    {
        return stop_reason|0;
    }

    .section .special.400
    return {
        inAsmJS: inAsmJS,
        get_arg: get_arg,
        set_arg: set_arg,
        get_rv: get_rv,
        set_rv: set_rv,
        get_bogotics: get_bogotics,
        set_bogotics: set_bogotics,
        get_single_stepping: get_single_stepping,
        set_single_stepping: set_single_stepping,
        get_bp_hit: get_bp_hit,
        set_bp_hit: set_bp_hit,
        get_bp_addr: get_bp_addr,
        set_bp_addr: set_bp_addr,
        get_steps: get_steps,
        set_steps: set_steps,
        call_frame: call_frame,
        rrds: rrds,
        get_stopped: get_stopped,
        set_stopped: set_stopped,
        get_in_bp: get_in_bp,
        set_in_bp: set_in_bp,

    .section .special.500
    };
                                     }));

(function (section) {
    function deffun(o) {
        var name = o.name;
        var symbol = o.symbol;
        var pc0 = o.pc0>>4;
        var pc1 = o.pc1>>4;
        var regsize = o.regsize|0;
        var regmask = o.regmask|0;

        name = name.replace(/ */g, "");
        var page;

        var fo = {
            name: symbol,
            address: name,
            regsize: regsize,
            regmask: regmask,
            pc0: pc0,
        };

        for (page = (pc0 & -256); page < pc1; page += 256) {
            section.functions[page] = fo;
        }
    }

    .section .special.600
})(ret.sections.code);

newAsmJSModule(ret);
