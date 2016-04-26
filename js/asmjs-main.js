function SuccessException()
{
}

function CStringAt(heap, offset)
{
    var ret = '';

    for (var i0 = offset; heap[i0]; i0++) {
        ret += String.fromCharCode(heap[i0]);
    }

    return ret;
}

function CStringsAt(heap, ptr)
{
    var HEAP32 = new Int32Array(heap);
    var HEAP8 = new Int8Array(heap);
    var res = [];

    while (HEAP32[ptr>>2]) {
        res.push(HEAP8, HEAP32[ptr>>2]);
        ptr += 4;
    }

    return res;
}

function CStringTo(str, heap, offset)
{
    var i0;

    for (i0 = 0; i0 < str.length; i0++) {
        heap[offset + i0] = str.charCodeAt(i0);
    }

    heap[i0] = 0;
}

function AsmJSCodeSection(name, constructor)
{
    this.name = name;
    this.constructor = constructor;
    this.functions = {};
}

var global = this;

AsmJSCodeSection.prototype.instantiate = function (thread)
{
    var mod;

    mod = this.constructor(global, {
        global_data: 0,
        print: print,
        now: function () { return +(new Date())/1000.0 },
        bp_addr: 0,
        extcall: thread.extcall.bind(thread),
        indcall: thread.indcall.bind(thread),
        tp: 0,
        abort: thread.abort.bind(thread),
        fround: Math.fround,
        bogotics: 0x7fffffff,
        single_stepping: 0,
        steps: 0,
        bp_hit: 0,
        QNaN: 0.0/0.0,
        tp: 0,
        fround: Math.fround,
    }, thread.process.heap);

    thread.module = mod;

    if (!mod.inAsmJS())
        throw "no asm.js!";

    for (var page in this.functions) {
        var fo = this.functions[page];

        fo.code = mod[fo.address];
        thread.process.deffun(page, fo);
    }
};

function AsmJSDataSection(name, offset, data)
{
    this.name = name;
    this.offset = offset;
    this.data = data;
}

AsmJSDataSection.prototype.instantiate = function (thread)
{
    var heap = thread.process.heap;
    var HEAP8 = new Int8Array(heap);

    for (var i = 0; i < this.data.length; i++)
        HEAP8[this.offset + i] = this.data[i];
};

function AsmJSSection()
{
}

function AsmJSModule()
{
    this.sections = {};
    this.functions = {};
}

AsmJSModule.prototype.add_section = function (section)
{
    this.sections[section.name] = section;
};

AsmJSModule.prototype.instantiate = function (thread)
{
    for (var name in this.sections) {
        this.sections[name].instantiate(thread);
    }
};

function AsmJSThread(process, module, threadpage)
{
    this.process = process;
    process.threads.push(this);
    var system = process.system;

    this.fds = process.fds;

    this.system = system;
    system.threads.push(this);

    this.HEAP8 = process.HEAP8;
    this.HEAP16 = process.HEAP16;
    this.HEAP32 = process.HEAP32;
    this.HEAPU8 = process.HEAPU8;
    this.HEAPU16 = process.HEAPU16;
    this.HEAPU32 = process.HEAPU32;
    this.HEAPF32 = process.HEAPF32;
    this.HEAPF64 = process.HEAPF64;

    this.threadpage = threadpage;

    this.module = module;

    this.extcallRet = {};
}

/* thread page layout
 * u64 next;               0x00
 * u64 prev;               0x08
 * u64 id;                 0x10
 * u64 bottom_of_stack;    0x18
 * u64 top_of_stack;       0x20
 * u64 stop_reason;        0x28
 * u64 pc;                 0x30
 * u64 sp;                 0x38
 * u64 initsp;             0x40
 * u64 rv;                 0x48
 * u64 a0;                 0x50
 * u64 a1;                 0x58
 * u64 a2;                 0x60
 * u64 a3;                 0x68
 * u64 tp;                 0x70
 */

AsmJSThread.prototype.stopped = function ()
{
    return this.HEAP32[this.threadpage + 0x28>>2];
};

AsmJSThread.prototype.pc = function ()
{
    return this.HEAP32[this.threadpage + 0x30>>2];
};

AsmJSThread.prototype.sp = function ()
{
    return this.HEAP32[this.threadpage + 0x38>>2];
};

AsmJSThread.prototype.initsp = function ()
{
    return this.HEAP32[this.threadpage + 0x40>>2];
};

var run;

AsmJSThread.prototype.stop = function (reason)
{
    var stopped = this.stopped();

    this.HEAP32[this.threadpage + 0x28>>2] = reason;

    if (stopped && reason == 0) {
        this.system.runqueue.push(this);
        if (run)
            run();
    }
};

AsmJSThread.prototype.set_pc = function (pc)
{
    this.HEAP32[this.threadpage + 0x30>>2] = pc;
};

AsmJSThread.prototype.set_sp = function (sp)
{
    this.HEAP32[this.threadpage + 0x38>>2] = sp;
};

AsmJSThread.prototype.set_initsp = function (initsp)
{
    this.HEAP32[this.threadpage + 0x40>>2] = initsp;
};

AsmJSThread.prototype.extcall = function (modstr, funstr, pc, sp)
{
    var mod = CStringAt(this.HEAPU8, modstr);
    var fun = CStringAt(this.HEAPU8, funstr);

    if (mod == "emscripten" && fun == "malloc") {
        mod = "thinthin";
        fun = "sbrk";
    }

    if (sp in this.extcallRet) {
        var ret = this.extcallRet[sp];

        if (ret !== undefined) {
            if (typeof Promise !== undefined &&
                ret instanceof Promise) {
                this.stop(1);
                return sp|1;
            }

            this.module.set_rv(ret);

            delete this.extcallRet[sp];

            return sp;
        }
    }

    var nargs = this.HEAP32[(sp+12)>>2];
    var is_void = ((nargs & 0x40000000) != 0) !=
        ((nargs & 0x80000000) != 0);
    var is_void_2 = this.HEAP32[sp+4>>2] != 0;

    if (is_void)
        nargs ^= 0x40000000;

    var args = [];
    if (nargs >= 0) {
        for (var ai = 0; ai < nargs; ai++) {
            args[ai] = this.HEAP32[sp+16+4*ai>>2];
        }
    }

    switch (mod) {
    case "thinthin":
        if (ThinThin[fun]) {
            try {
                retv = ThinThin[fun].apply(this, args);
                break;
            } catch (e) {
                throw "died while executing " + fun + ' arg0 ' + args[0] + " e " + e;
            }
        }
        throw "couldn't find " + fun;
    default:
        throw("giving up, pc " + pc.toString(16) + " fun " + funstr.toString(16) + " " + fun + " mod " + modstr.toString(16) + " " + mod);
    }

    if (typeof Promise !== "undefined" &&
        retv instanceof Promise) {
        this.extcallRet[sp] = retv;
        this.stop(1);

        retv.then(r => {
            this.extcallRet[sp] = r;
            this.stop(0);
        });

        return sp|1;
    }

    if (retv !== undefined && retv == retv) {
        this.module.set_rv(retv);
    } else if (retv != retv) {
        return initsp;
    } else {
        throw "cannot resolve " + mod + ":" + fun;
    }

    /*
    console.log('extcall ' + fun + ' returned ' + retv);

    if (fun == "stat" || fun == "fstat") {
        console.log('stat buffer 0 '+this.HEAP32[args[1]+0>>2].toString(16));
        console.log('stat buffer 1 '+this.HEAP32[args[1]+4>>2].toString(16));
        console.log('stat buffer 2 '+this.HEAP32[args[1]+8>>2].toString(16));
        console.log('stat buffer 3 '+this.HEAP32[args[1]+12>>2].toString(16));
        console.log('stat buffer 4 '+this.HEAP32[args[1]+16>>2].toString(16));
        console.log('stat buffer 5 '+this.HEAP32[args[1]+20>>2].toString(16));
        console.log('stat buffer 6 '+this.HEAP32[args[1]+24>>2].toString(16));
        console.log('stat buffer 7 '+this.HEAP32[args[1]+28>>2].toString(16));
        console.log('stat buffer 8 '+this.HEAP32[args[1]+32>>2].toString(16));
        console.log('stat buffer 9 '+this.HEAP32[args[1]+36>>2].toString(16));
        console.log('stat buffer a '+this.HEAP32[args[1]+40>>2].toString(16));
        console.log('stat buffer b '+this.HEAP32[args[1]+44>>2].toString(16));
        console.log('stat buffer c '+this.HEAP32[args[1]+48>>2].toString(16));
        console.log('stat buffer d '+this.HEAP32[args[1]+52>>2].toString(16));
        console.log('stat buffer e '+this.HEAP32[args[1]+56>>2].toString(16));
        console.log('stat buffer f '+this.HEAP32[args[1]+60>>2].toString(16));
    }
    */

    return sp;
};

AsmJSThread.prototype.restart = function (dst, src, len, entry)
{
    var initsp = this.initsp();

    this.restartCode = () => {
        if (len) {
            var i;

            for (i = 0; i < len; i++)
                this.HEAP8[dst+i] = this.HEAP8[src+i];
        } else {
            //datainit();
        }

        this.set_pc(entry>>4);
        this.set_sp(initsp);
        this.set_initsp(initsp);

        delete this.restartCode;
    };

    this.stop(0);

    return 0;
};

AsmJSThread.prototype.functionByPC = function (pc)
{
    var page = pc & -256;

    return this.process.functions[page];
};

AsmJSThread.prototype.step = function ()
{
    var pc = this.pc();
    var sp = this.sp();
    var rp = 0;

    while (true) {
        var cpc = pc;
        var rfp = 0;
        var rpc = 0;

        this.module.set_bogotics(0x7fffffff);
        this.HEAP32[4096+2048>>2] = -1;
        this.HEAP32[4096+2048+4>>2] = -1;
        this.HEAP32[4096+2048+8>>2] = -1;
        this.HEAP32[4096+2048+12>>2] = -1;
        this.HEAP32[4096+2048+16>>2] = -1;
        this.HEAP32[4096+2048+20>>2] = -1;
        this.HEAP32[4096+2048+24>>2] = -1;
        this.HEAP32[4096+2048+28>>2] = -1;
        this.HEAP32[4096+2048+32>>2] = -1;
        this.HEAP32[4096+2048+36>>2] = -1;
        this.HEAP32[4096+2048+40>>2] = -1;
        this.HEAP32[4096+2048+44>>2] = -1;
        this.HEAP32[4096+2048+48>>2] = -1;
        this.HEAP32[4096+2048+48>>2] = -1;
        this.HEAP32[4096+2048+52>>2] = -1;
        this.HEAP32[4096+2048+56>>2] = -1;
        this.HEAP32[4096+2048+60>>2] = -1;
        this.HEAP32[4096+2048+64>>2] = -1;
        this.module.set_bp_addr(4096+2048);

        if (pc == 0) {
            cpc = this.HEAP32[sp+4>>2]>>4;
            var regsize = this.HEAP32[sp+12>>2];
            var top_of_frame = this.HEAP32[sp+regsize>>2];
            rfp = this.HEAP32[top_of_frame>>2];
            rpc = this.HEAP32[rfp+4>>2];
        }

        var f = this.functionByPC(cpc);

        if (!f)
            throw "no f for " + cpc.toString(16);

        rp = f.code(pc, sp, 0, 0, rpc, rfp);

        if (rp&3) {
            /* the function has saved its JS stack to the VM stack,
             * or it has aborted. */
            pc = 0;
            sp = rp&-4;
            break;
        }

        if ((rp|3) >= (this.initsp()|3)) {
            /* the function has returned to top level */
            if (this.restartCode) {
                this.restartCode();
                return rp&-4;
            }
            this.stop(0xffffffff);
            break;
        }

        /* The function has returned to a function on the VM stack */
        sp = this.HEAP32[rp+4>>2];
        pc = 0;
    }

    this.set_pc(pc);
    this.set_sp(sp);

    return rp&-4;
};

AsmJSThread.prototype.pre_call = function (pc, fp, a0, a1)
{
    var sp = this.module.call_frame(fp);
    var f = this.functionByPC(pc>>4);

    var regsize = f.regsize|16;
    var regmask = f.regmask|0xf;

    sp -= regsize;

    HEAP32[sp>>2] = regmask;
    HEAP32[sp+4>>2] = pc|0;
    HEAP32[sp+8>>2] = sp+regsize|0;
    HEAP32[sp+12>>2] = regsize;

    for (var off = 16; off < regsize; off += 4)
        HEAP32[sp+off>>2] = 0;

    if ((regmask & 0xf0) == 0xf0) {
        HEAP32[sp+16>>2] = this.module.get_arg(0);
        HEAP32[sp+20>>2] = this.module.get_arg(1);
        HEAP32[sp+24>>2] = this.module.get_arg(2);
        HEAP32[sp+28>>2] = this.module.get_arg(3);
    }

    if (a0 !== undefined)
        HEAP32[sp+32>>2] = a0;
    if (a1 !== undefined)
        HEAP32[sp+36>>2] = a1;

    sp -= 16;
    HEAP32[sp>>2] = sp+16|0;
    HEAP32[sp+4>>2] = pc|0;

    return sp;
};

AsmJSThread.prototype.indcall = function (pc, sp, r0, r1, rpc, rfp)
{
    pc = pc << 4;

    this.module.set_rv(this.HEAP32[pc+8>>2]);
    pc = this.HEAP32[pc+4>>2];

    pc = pc >> 4;
    if (pc)
        return gFunctions[pc].code(pc, sp, r0, r1, rpc, rfp);
    this.module.set_rv(0);

    return sp;
};

AsmJSThread.prototype.abort = function (code, arg)
{
    code = code|0;
    arg = arg|0;

    switch (code) {
    case 0:
        throw("bad PC " + arg + "!");

    case 1:
        //("NULL pointer called at " + arg + "!");
        return 0|0;

    default:
        throw("unknown exception " + code);
    }
}

AsmJSThread.prototype.freeze = function ()
{
    return new FrozenAsmJSThread(this);
};

function FrozenAsmJSThread(thread)
{
    this.threadpage = thread.threadpage;
}

FrozenAsmJSThread.prototype.thaw = function (process, module)
{
    var n = new AsmJSThread(process, module, this.threadpage);

    return n;
};

function AsmJSProcess(system, heap)
{
    this.system = system;
    system.processes.push(this);

    this.fds = [];

    this.heap = heap;
    this.HEAP8 = new Int8Array(this.heap);
    this.HEAP16 = new Int16Array(this.heap);
    this.HEAP32 = new Int32Array(this.heap);
    this.HEAPU8 = new Uint8Array(this.heap);
    this.HEAPU16 = new Uint16Array(this.heap);
    this.HEAPU32 = new Uint32Array(this.heap);
    this.HEAPF32 = new Float32Array(this.heap);
    this.HEAPF64 = new Float64Array(this.heap);

    this.functions = {};
    this.threads = [];
}

AsmJSProcess.prototype.deffun = function(page, fo)
{
    this.functions[page] = fo;

    if (fo.name == "__pre_main") {
        this.entry = fo.pc0;
        premain_pc = fo.pc0;
    } else if (fo.name == "_start") {
        if (this.entry === undefined)
            this.entry = fo.pc0;
        main_pc = fo.pc0;
    } else if (fo.name == "gdbstub_entry") {
        gdbstub_pc = fo.pc0;
    }
};

AsmJSProcess.prototype.initData = function (sections)
{
    var global_data = 5402632;
    if (global_data != 5402632)
        throw "unhardcode global_data!";

    global_data -= 8;

    var i,j;
    var o = 0;
    for (i = 0; i < sections.length; i++) {
        var data_section = data[sections[i]];
        for (j = 0; j < data_section.length; j++) {
            this.HEAPU8[global_data + o++] = data_section[j];
        }
        o += 4095;
        o &= -4096;
    }
};

AsmJSProcess.prototype.freeze = function ()
{
    return new FrozenAsmJSProcess(this);
};

function FrozenAsmJSProcess(process)
{
    this.fds = process.fds;
    this.threads = process.threads;
    this.system = process.system;
    this.functions = process.functions;
    this.heap = process.heap;

    for (var i = 0; i < this.threads.length; i++)
        this.threads[i] = this.threads[i].freeze();

    var fds = [];
    for (var i = 0; i < this.fds.length; i++)
        fds[i] = this.fds[i].freeze();

    this.fds = fds;

    delete this.system;
    delete this.functions;
}

FrozenAsmJSProcess.prototype.thaw = function (system)
{
    var n = new AsmJSProcess(system, this.heap);

    var fds = [];
    for (var i = 0; i < this.fds.length; i++) {
        var fd = this.fds[i];
        fds[i] = FrozenThinThinFD.prototype.thaw.call(fd,
                                                      n,
                                                      function (x) { return global.postMessage(x) });
    }
    n.fds = fds;

    n.threads = [];
    n.system = system;
    n.functions = {};
    n.heap = new ArrayBuffer(this.heap.byteLength);
    var newHEAP8 = new Int8Array(n.heap);
    var oldHEAP8 = new Int8Array(this.heap);
    for (var i = 0; i < this.heap.byteLength; i++)
        newHEAP8[i] = oldHEAP8[i];

    n.newHEAP8 = newHEAP8;
    n.oldHEAP8 = oldHEAP8;

    n.HEAP8 = new Int8Array(n.heap);
    n.HEAP16 = new Int16Array(n.heap);
    n.HEAP32 = new Int32Array(n.heap);
    n.HEAPU8 = new Uint8Array(n.heap);
    n.HEAPU16 = new Uint16Array(n.heap);
    n.HEAPU32 = new Uint32Array(n.heap);
    n.HEAPF32 = new Float32Array(n.heap);
    n.HEAPF64 = new Float64Array(n.heap);

    for (var i = 0; i < this.threads.length; i++)
        n.threads[i] = FrozenAsmJSThread.prototype.thaw.call(this.threads[i],
                                                             n,
                                                             gMod);

    return n;
};

function AsmJSSystem()
{
    this.processes = [];
    this.threads = [];
    this.runqueue = [];
}

AsmJSSystem.prototype.init_sp = function (heap, off, args, env)
{
    var HEAP8 = new Int8Array(heap);
    var HEAP32 = new Int32Array(heap);
    var i;
    var eo = [];
    var ao = [];
    for (i = env.length-1; i >= 0; i--) {
        var str = env[i];
        off -= str.length+1;
        CStringTo(str, HEAP8, off);
        eo.push(off);
    }
    for (i = args.length-1; i >= 0; i--) {
        var str = args[i];
        off -= str.length+1;
        CStringTo(str, HEAP8, off);
        ao.push(off);
    }
    off &= -4;

    HEAP32[(off-=4)>>2] = 0;

    for (i = 0; i < eo.length; i++) {
        HEAP32[(off-=4)>>2] = eo[i];
    }

    var envp = off;

    HEAP32[(off-=4)>>2] = 0;

    for (i = 0; i < ao.length; i++) {
        HEAP32[(off-=4)>>2] = ao[i];
    }

    var argv = off;
    var argc = ao.length;

    off &= -16;

    HEAP32[(off-=4)>>2] = 0; /* padding */
    HEAP32[(off-=4)>>2] = envp;
    HEAP32[(off-=4)>>2] = argv;
    HEAP32[(off-=4)>>2] = argc;

    HEAP32[(off-=4)>>2] = 3; /* argument count */
    off -= 4;
    HEAP32[off>>2] = off+24; /* argument something */
    HEAP32[(off-=4)>>2] = 0; /* return FP */
    HEAP32[(off-=4)>>2] = 0; /* return PC */

    if (off & 4) {
        throw "unaligned off";
    }

    return off;
};

AsmJSSystem.prototype.instantiate = function (module, args, env)
{
    var size = module.top_of_memory;
    var heap = new ArrayBuffer(size);
    var HEAP32 = new Int32Array(heap);

    HEAP32[4096>>2] = size; // top of available memory
    HEAP32[4104>>2] =   32 * 1024 * 1024; // top of sbrk'd memory
    HEAP32[4112>>2] = 8192;               // first thread page
    HEAP32[4120>>2] =   32 * 1024 * 1024; // bottom of sbrk'd memory

    HEAP32[8192 + 0x00>>2] = 8192; // next thread page
    HEAP32[8192 + 0x08>>2] = 8192; // prev thread page
    HEAP32[8192 + 0x10>>2] = 1;    // thread id
    HEAP32[8192 + 0x18>>2] = module.bottom_of_stack;
    HEAP32[8192 + 0x20>>2] = module.top_of_stack;

    var sp = this.init_sp(heap, module.top_of_stack, args, env);
    HEAP32[8192 + 0x38>>2] = sp;
    HEAP32[8192 + 0x40>>2] = sp;

    var process = new AsmJSProcess(this, heap);
    var thread = new AsmJSThread(process, module, 8192);
    thread.module.instantiate(thread);
    HEAP32[8192 + 0x30>>2] = process.entry;
    if (typeof document !== "undefined") {
        new ThinThinFD(process, 0);
        new VT100FD(process, document.getElementById("output2"), 1, 0);
        new ThinThinFD(process, 2);
    } else {
        new ThinThinFD(process, 0);
        new ThinThinFD(process, 1);
        new ThinThinFD(process, 2);
    }
    this.runqueue.push(thread);
};

AsmJSSystem.prototype.step = function ()
{
    if (this.runqueue.length == 0)
        return;

    var thread = this.runqueue.shift();

    thread.step();

    if (!thread.stopped())
        this.runqueue.push(thread);
};

var ThinThin = {};

ThinThin.sbrk = function (size)
{
    size = (size + 4095) & -4096;
    var ret = this.HEAP32[4104>>2];

    this.HEAP32[4104>>2] += size;

    if (this.HEAP32[4104>>2] > this.HEAP32[4096>>2]) {
        throw "OOM";
    }

    return ret;
};

ThinThin.brk = function (addr)
{
    return 0;
};

var data = {};
var offsets = {};

var data_sections = [];
var gFunctions = {};
var main_pc;
var premain_pc;
var gdbstub_pc;
var initsp;

var MyCode;

var debug_queued_data = [];
var debug_queued_writedata = [];
var gServer;
var gSocket;
var gReqs = [];
var debug_log = "";
var args;

if (typeof print === "function") {
}
else {
    print = function (str) {
        console.log(str);
    }
}

if (args) {
}
else if (typeof process !== "undefined") {
    args = process.argv.slice(1);
}
else if (typeof scriptArgs !== "undefined") {
    args = scriptArgs.slice(0);
} else {
    args = ["<this program>"];
}

function checkQueuedData(force)
{
    if (gReqs.length == 0 &&
        (force || debug_queued_writedata.length != 0)) {
        var str = "";
        for (var i in debug_queued_writedata) {
            str += String.fromCharCode(debug_queued_writedata[i]);
        }

        debug_queued_writedata = [];

        var req = new XMLHttpRequest();

        req.onreadystatechange = function () {
            if (req.readyState !== XMLHttpRequest.DONE) {
                return;
            }
            gReqs.shift();
            var data = req.responseText;
            if (req.status !== 200) {
                return;
            }

            if (data != "") {
                for (var i = 0; i < data.length; i++) {
                    debug_queued_data.push(data.charCodeAt(i));
                }
            }

            checkQueuedData();
        }

        req.open("POST", "http://127.0.0.1/cgi-bin/debug.cgi");

        gReqs.push(req);
        req.send(str);
    }
}

function Syscall(number, argspec0, argspec1, argspec2, argspec3, argspec4)
{
    var argspecs = [];
    if (argspec0 !== undefined) argspecs.push(argspec0);
    if (argspec1 !== undefined) argspecs.push(argspec1);
    if (argspec2 !== undefined) argspecs.push(argspec2);
    if (argspec3 !== undefined) argspecs.push(argspec3);
    if (argspec4 !== undefined) argspecs.push(argspec4);
    return function(arg0, arg1, arg2, arg3, arg4, arg5) {
        var args = [arg0, arg1, arg2, arg3, arg4, arg5];
        var rargs = [number];
        var i;
        var ret;
        for (i = 0; i < argspecs.length; i++) {
            var spec = argspecs[i];
            if (spec == "ptr") {
                rargs.push(this.HEAPU8);
                //console.log('string arg ' + CStringAt(this.HEAPU8, args[i]));
            } else {
                //console.log('integer arg ' + args[i].toString(16));
            }
            rargs.push(args[i]);
        }
        ret = os.sys.call.apply(undefined, rargs);
        //print("syscall " + number + " ret " + ret);
        return ret;
    };
}

var Syscalls = {
    read:         new Syscall(  0, "fd", "ptr", "u64"),
    write:        new Syscall(  1, "fd", "ptr", "u64"),
    open:         new Syscall(  2, "ptr", "u64", "u64"),
    close:        new Syscall(  3, "fd"),
    stat:         new Syscall(  4, "ptr", "ptr"),
    fstat:        new Syscall(  5, "u64", "ptr"),
    lseek:        new Syscall(  8, "u64", "u64", "u64"),
    ioctl_p:      new Syscall( 16, "u64", "u64", "ptr"),
    access:       new Syscall( 21, "ptr", "u64"),
    pipe2:        new Syscall(293, "ptr", "u64"),
    select:       new Syscall( 23, "u64", "ptr", "ptr", "ptr", "ptr"),
    sched_yield:  new Syscall( 24),
    dup:          new Syscall( 32, "u64"),
    dup2:         new Syscall( 33, "u64", "u64"),
    getpid:       new Syscall( 39),
    clone:        new Syscall( 56, "u64", "ptr", "ptr", "ptr", "ptr"),
    execve:       new Syscall( 59, "ptr", "aptr", "aptr"),
    exit:         new Syscall( 60, "u64"),
    wait4:        new Syscall( 61, "u64", "ptr", "u64", "ptr"),
    kill:         new Syscall( 62, "u64", "u64"),
    fcntl_v:      new Syscall( 72, "u64", "u64"),
    fcntl_i:      new Syscall( 72, "u64", "u64", "u64"),
    getcwd:       new Syscall( 79, "ptr", "u64"),
    chdir:        new Syscall( 80, "ptr"),
    fchdir:       new Syscall( 81, "u64"),
    rename:       new Syscall( 82, "ptr", "ptr"),
    mkdir:        new Syscall( 83, "ptr", "u64"),
    rmdir:        new Syscall( 84, "ptr"),
    unlink:       new Syscall( 87, "ptr"),
    rename:       new Syscall( 82, "ptr", "ptr"),
    chdir:        new Syscall( 80, "ptr"),
    gettimeofday: new Syscall( 96, "ptr", "u64"),
    getdents:     new Syscall(217, "fd", "ptr", "u64"),
    openat:       new Syscall(257, "fd", "ptr", "u64", "u64"),
    faccessat:    new Syscall(269, "fd", "ptr", "u64", "u64"),
    ppoll:        new Syscall(271, "ptr", "u64", "ptr", "ptr"),
    execveat:     new Syscall(333, "fd", "ptr", "aptr", "aptr", "u64"),
};

function InputPromise(fd, output = undefined)
{
    var done = false;
    output = undefined;

    if (done)
        return Promise.resolve("");

    done = true;

    if (output === undefined)
        output = document.getElementById("output");

    output = new ImmediatePromise(output);

    return output.then(o => {
        return new Promise((resolve, reject) => {
            var node = document.createElement("div");
            var node_ta = document.createElement("textarea");
            var node_b = document.createElement("button");
            node_b.innerHTML = "EOF";

            var node_send = document.createElement("button");
            node_send.innerHTML = "Send";

            node.appendChild(node_ta);
            node.appendChild(node_send);
            node.appendChild(node_b);

            var forget;
            var destroy;

            destroy = function () {
                if (node.parentNode)
                    node.parentNode.removeChild(node);

                fd.forgetInputPromises.delete(forget);
                reject();
            };

            forget = function () {
                if (node_ta.value === "")
                    destroy();
            };

            fd.forgetInputPromises.add(forget);

            if (0) node_ta.onchange = function (e) {
                var value = node_ta.value;
                if (value == "")
                    fd.EOF = true;
                resolve(value == "" ? "" : (value + "\n"));

                if (node.parentNode)
                    node.parentNode.removeChild(node);

                e.stopPropagation();
                e.preventDefault();
            };

            node_b.onclick = function (e) {
                var value = node_ta.value;
                fd.EOF = true;
                resolve(value == "" ? "" : (value + "\n"));

                destroy();

                e.stopPropagation();
                e.preventDefault();
            };

            node_send.onclick = function (e) {
                var value = node_ta.value;
                resolve(value == "" ? "" : (value + "\n"));

                destroy();

                e.stopPropagation();
                e.preventDefault();
            };

            o.appendChild(node);

            node.focus();
        });
    });
}

function TimeoutPromise(timeout)
{
    return new Promise((resolve, reject) => {
        window.setTimeout(resolve, timeout);
    });
}

function SplitPromise(n, promise)
{
    var resolve_lhs, resolve_rhs;
    var reject_lhs, reject_rhs;

    var promise_lhs = new Promise((resolve, reject) => {
        resolve_lhs = resolve;
        reject_lhs = reject;
    });

    var promise_rhs = new Promise((resolve, reject) => {
        resolve_rhs = resolve;
        reject_rhs = reject;
    });

    promise.then(value => {
        var lhs = value.substr(0, n);
        var rhs = value.substr(n);

        resolve_rhs(rhs);
        resolve_lhs(lhs);
    });

    return [promise_lhs, promise_rhs];
}

function DissectedPromise()
{
    this.promise = new Promise((resolve, reject) => {
        this.resolve = resolve;
        this.reject = reject;
    });
}

DissectedPromise.prototype.then = function (consequence)
{
    return this.promise.then(consequence);
};

function ImmediatePromise(v)
{
    if (v instanceof Promise)
        return v;

    this.value = v;
}

ImmediatePromise.prototype.then = function (consequence)
{
    return consequence(this.value);
};

var Linux = {
    AT_FDCWD: -100,
    EBADF: 9,
    ENOMEM: 12,
    EINVAL: 22,
    ERANGE: 34,
    FIONREAD: 0x541b,
    POLLIN: 1,
    POLLPRI: 2,
    POLLOUT: 4,
    POLLERR: 8,
    POLLHUP: 16,
    POLLNVAL: 32,
    SEEK_SET: 0,
    SEEK_CUR: 1,
    SEEK_END: 2,
};

function ThinThinFD(process, fdno = undefined)
{
    if (fdno === undefined)
        for (fdno = 0; process.fds[fdno]; fdno++)
            ;
    this.fdno = fdno;
    this.readData = [];
    this.readPosition = 0;
    this.forgetInputPromises = new Set();
    process.fds[fdno] = this;
    this.process = process;
}

ThinThinFD.prototype.open = function ()
{
    return this.fdno;
};

ThinThinFD.prototype.close = function ()
{
    delete this.process.fds[this.fdno];

    return Promise.resolve(0);
};

ThinThinFD.prototype.consume = function (i)
{
    this.readData = this.readData.substr(i);
};

ThinThinFD.prototype.stuff = function (data)
{
    this.readData += data;

    if (this.activeInputPromise) {
        var activeInputPromise = this.activeInputPromise;
        delete this.activeInputPromise;
        activeInputPromise.resolve(data);
    }

    var forgetInputPromises = this.forgetInputPromises;
    this.forgetInputPromises = new Set();

    for (var forget of forgetInputPromises)
        forget();
};

ThinThinFD.prototype.makeSeekable = function ()
{
    this.consume = i => {
        this.readPosition += i;
    };
};

/* .read(undefined, 0, 0) returns a promise that resolves to 0 when
 * data is available to read. */
ThinThinFD.prototype.read = function(heap = undefined, ptr = 0, len = 0)
{
    if (this.readData.length > this.readPosition ||
        this.EOF) {
        var i;

        for (i=0; i<len && i<this.readData.length - this.readPosition; i++) {
            var cc = this.readData.charCodeAt(this.readPosition+i);
            if (cc >= 0x80 || cc <= 0 || cc != cc) {
                //console.log("UTF-8 char in " + this.readData.substr(this.readPosition+i, 32));
            }
            heap[ptr+i] = cc;
        }
        this.consume(i);

        if (i == 0 || i == len)
            return i;

        return Promise.resolve(this.read(heap, ptr+i, len-i)).then(j => i+j);
    }

    return this.wrappedInputPromise().then(data => {
        if (data === undefined)
            return -2;

        if (data === "" && !this.EOF)
            return 0;

        return this.read(heap, ptr, len);
    });
};

ThinThinFD.prototype.available = function ()
{
    if (this.readData.length > this.readPosition)
        return Promise.resolve(this.readData.length - this.readPosition);

    this.wrappedInputPromise();

    return Promise.resolve(0);
};

ThinThinFD.prototype.wrappedInputPromise = function ()
{
    if (!this.activeInputPromise) {
        this.activeInputPromise = new DissectedPromise();

        this.inputPromise().then((data) => {
            this.stuff(data);
        });
    }

    return this.activeInputPromise;
};

ThinThinFD.prototype.inputPromise = function ()
{
    return new InputPromise(this, this.domPromise());
};

ThinThinFD.prototype.write = function (heap = undefined, ptr = 0, len = 0)
{
    if (len == 0)
        return Promise.resolve(0);

    return this.outputPromise(heap, ptr, len).then(i =>
        this.write(heap, ptr+i, len-i).then(j => i+j));
};

ThinThinFD.prototype.outputPromise = function (heap, ptr, len)
{
    var data = "";

    for (i=0; i<len; i++)
        data += String.fromCharCode(heap[ptr+i]);

    putstr(data);

    return Promise.resolve(len);
};

ThinThinFD.prototype.domPromise = function ()
{
    return document.getElementById("output");
};

ThinThinFD.prototype.clone = function ()
{
    return this;
};

ThinThinFD.prototype.freeze = function ()
{
    return new FrozenThinThinFD(this);
};

var gRemoteFDs = {};

function FrozenThinThinFD(fd)
{
    var rfdno;

    for (rfdno = 0; rfdno in gRemoteFDs; rfdno++);

    gRemoteFDs[rfdno] = fd;

    this.rfdno = rfdno;
    this.fdno = fd.fdno;
}

FrozenThinThinFD.prototype.thaw = function (process, target)
{
    var fd = new RemoteFD(process, target, this.rfdno, this.fdno);
    gRemoteFDs[this.rfdno] = fd;
    fd.target = target;

    return fd;
};

function ThinThinFetchFD(process, url, fdno = undefined)
{
    ThinThinFD.call(this, process, fdno);
    this.url = url;
    this.makeSeekable();
}

ThinThinFetchFD.prototype = Object.create(ThinThinFD.prototype);

ThinThinFetchFD.prototype.open = function ()
{
    return this.inputPromise().then(() => this.fdno);
};

ThinThinFetchFD.prototype.inputPromise = function ()
{
    var url = this.url;

    delete this.url;

    if (!url) {
        return Promise.resolve("");
    }

    return fetch(url).then(response => {
        var abp = response.arrayBuffer();

        return abp.then(abuf => {
            var view = new Uint8Array(abuf);
            var text = "";

            for (var i = 0; i < abuf.byteLength; i++) {
                var cc = view[i];
                if (cc & 0x80) cc += 0x100;
                text += String.fromCharCode(cc);
            }

            return text;
        });
    }).catch(error => undefined);
};

function ArrayBufferFD(process, abufPromise, fdno = undefined)
{
    ThinThinFD.call(this, process, fdno);

    this.abufPromise = abufPromise;
}
ArrayBufferFD.prototype = Object.create(ThinThinFD.prototype);

ArrayBufferFD.prototype.inputPromise = function ()
{
    this.abufPromise.then((abuf) => {
    })
}

function PipeFD(process, fdno = undefined)
{
    ThinThinFD.call(this, process, fdno);
}

PipeFD.prototype.connect = function (other)
{
    this.other = other;
};

function PipeConnection(ipipe, opipe)
{
    this.i = ipipe;
    this.o = opipe;
}

function IPipeFD(process, fdno = undefined)
{
    PipeFD.call(this, process, fdno);
}
IPipeFD.prototype = Object.create(PipeFD.prototype);

function OPipeFD(process, fdno = undefined)
{
    PipeFD.call(this, process, fdno);
}
OPipeFD.prototype = Object.create(PipeFD.prototype);

OPipeFD.prototype.outputPromise = function (heap, ptr, len)
{
    if (len == 0)
        return 0;

    if (this.other.ready) {
        var l = Math.min(len, this.other.len);

        for (var i = 0; i < l; i++)
            this.other.heap[this.other.ptr + i] = heap[ptr + i];

        this.other.resolve(l);
    } else {
        
    }
};

function RemoteFD(process, target, rfdno, fdno = undefined)
{
    ThinThinFD.call(this, process, fdno);

    gRemoteFDs[rfdno] = this;
    this.target = target;
    this.rfdno = rfdno;
}

RemoteFD.prototype = Object.create(ThinThinFD.prototype);

RemoteFD.prototype.inputPromise = function ()
{
    console.log("RemoteFD.inputPromise");
    return new Promise((resolve, reject) => {
        this.target(["read", this.rfdno], "*");
        this.stuff = (data) => {
            resolve(data);
            delete this.stuff;
        };
    });
};

RemoteFD.prototype.outputPromise = function (heap, ptr, len)
{
    console.log("RemoteFD.outputPromise " + heap + " " + ptr + " " + len);
    var buf = new ArrayBuffer(len);
    var buf8 = new Uint8Array(buf);
    for (var i = 0; i < buf.byteLength; i++)
        buf8[i] = heap[ptr+i];

    this.target(["send", this.rfdno, buf]);

    return Promise.resolve(len);
};

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

if (typeof(os) !== "undefined" &&
    typeof(os.sys) !== "undefined") {
    ThinThin.read =         Syscalls.read;
    ThinThin.write =        Syscalls.write;
    ThinThin.open =         Syscalls.open;
    ThinThin.openat =       Syscalls.openat;
    ThinThin.close =        Syscalls.close;
    ThinThin.stat =         Syscalls.stat;
    ThinThin.fstat =        Syscalls.fstat;
    ThinThin.lseek =        Syscalls.lseek;
    ThinThin.access =       Syscalls.access;
    ThinThin.select =       Syscalls.select;
    ThinThin.ioctl_p =      Syscalls.ioctl_p;
    ThinThin.exit =         function (code) {
        quit(code);
        if (code != 0 && code !== undefined)
            throw "Exit Status " + code;
        else
            throw new SuccessException();
    };
    ThinThin.unlink =       Syscalls.unlink;
    ThinThin.rename =       Syscalls.rename;
    ThinThin.chdir =        Syscalls.chdir;
    ThinThin.fcntl_v =      Syscalls.fcntl_v;
    ThinThin.fcntl_i =      Syscalls.fcntl_i;
    ThinThin.getcwd =       Syscalls.getcwd;
    ThinThin.gettimeofday = Syscalls.gettimeofday;
    ThinThin.gethostname = function (addr, len) {
        this.HEAP8[addr] = 0;

        return 0;
    };
    ThinThin.faccessat =   Syscalls.faccessat;
    ThinThin.getdents =    Syscalls.getdents;
    //Syscalls.gettimeofday;
    ThinThin.isatty = function () { return 1 };
    ThinThin.restart = function (dst, src, len, entry)
    {
        return this.restart(dst, src, len, entry);
    };
    ThinThin.ppoll =       Syscalls.ppoll;
} else {
    ThinThin.isatty = function (fdno) {
        return fdno <= 2 ? 1 : 0;
    };
    ThinThin.gethostname = function (addr, len) {
        this.HEAP8[addr] = 0;

        return 0;
    };
    ThinThin.read = function (fdno, ptr, len) {
        var fd = this.fds[fdno];

        if (!fd)
            return -Linux.EBADF;

        if (len == 0)
            return 0;

        var ret = fd.read(this.HEAPU8, ptr, len);

        return ret;
    },
    ThinThin.write = function (fdno, ptr, len) {
        var fd = this.fds[fdno];

        if (!fd)
            return -Linux.EBADF;

        if (len == 0)
            return 0;

        return fd.write(this.HEAPU8, ptr, len);
    };
    ThinThin.open = function (ptr, flags, mode) {
        var path = CStringAt(this.HEAPU8, ptr);

        path = path.replace(/^.*[\/]/, "");

        if (path.match(/\.elc$/) ||
            path.match(/\.el\.el$/) ||
            path.match(/\.el\.e$/))
            return -2;

        var fd = new ThinThinFetchFD(this.process, path);

        return fd.fdno;
    },
    ThinThin.close = function (fdno) {
        var fd = this.fds[fdno];

        if (!fd)
            return -Linux.EBADF;

        return fd.close();
    },
    ThinThin.faccessat = function (fdno, ptr, flags, mode) {
        return 0;
    };
    ThinThin.stat = function (ptr, bufptr) {
        var path = CStringAt(this.HEAPU8, ptr);

        path = path.replace(/^.*[\/]/, "");

        /* st_dev: 64 bits */
        this.HEAP32[bufptr+ 0>>2] = 0;
        this.HEAP32[bufptr+ 4>>2] = 0;
        /* pad1: 32 bits */
        this.HEAP32[bufptr+ 8>>2] = 0;
        /* __st_ino: 32 bits */
        this.HEAP32[bufptr+12>>2] = 0;
        /* st_mode: 32 bits */
        this.HEAP32[bufptr+16>>2] = 0;
        /* st_nlink: 64 bits */
        this.HEAP32[bufptr+20>>2] = 0;
        this.HEAP32[bufptr+24>>2] = 0;
        this.HEAP32[bufptr+28>>2] = 0;
        this.HEAP32[bufptr+32>>2] = 0;
        this.HEAP32[bufptr+36>>2] = 0;
        this.HEAP32[bufptr+40>>2] = 0;
        this.HEAP32[bufptr+44>>2] = 0;

        if (path == "terminfo") {
            this.HEAP32[bufptr+6*4>>2] = 4 << 12;
        } else if (path.match(/\.elc$/)) {
            return -2;
        } else {
            //console.log("statting " + CStringAt(ptr));
        }

        return 0;
    };
    var first = 3;
    ThinThin.getdents = function (fdno, direntp, count)
    {
        if (first) {
        this.HEAP32[direntp>>2] = 0;
        this.HEAP32[direntp+4>>2] = 0;
        this.HEAP32[direntp+8>>2] = 0;
        this.HEAP32[direntp+12>>2] = 0;
        this.HEAP16[direntp+16>>1] = 9;
        this.HEAP8[direntp+18] = "w".charCodeAt(0);
        this.HEAP8[direntp+19] = "o".charCodeAt(0);
        this.HEAP8[direntp+20] = "r".charCodeAt(0);
        this.HEAP8[direntp+21] = "d".charCodeAt(0);
        this.HEAP8[direntp+22] = "s".charCodeAt(0);
        this.HEAP8[direntp+23] = ".".charCodeAt(0);
        this.HEAP8[direntp+24] = "e".charCodeAt(0);
        this.HEAP8[direntp+25] = "n".charCodeAt(0);
        this.HEAP8[direntp+26] = "g".charCodeAt(0);

            first--;
            return 26;
        }
        return 0;
    };
    ThinThin.fstat = function (fdno, bufptr) {
        var fd = this.fds[fdno];
        this.HEAP32[bufptr+ 0>>2] = 0;
        this.HEAP32[bufptr+ 4>>2] = 0;
        this.HEAP32[bufptr+ 8>>2] = 0;
        this.HEAP32[bufptr+12>>2] = 0;
        this.HEAP32[bufptr+16>>2] = 0;
        this.HEAP32[bufptr+20>>2] = 0;
        this.HEAP32[bufptr+24>>2] = 0;
        this.HEAP32[bufptr+28>>2] = 0;
        this.HEAP32[bufptr+32>>2] = 0;
        this.HEAP32[bufptr+36>>2] = 0;
        this.HEAP32[bufptr+40>>2] = 0;
        this.HEAP32[bufptr+44>>2] = 0;
        this.HEAP32[bufptr+48>>2] = 0;
        this.HEAP32[bufptr+52>>2] = 0;
        this.HEAP32[bufptr+56>>2] = 0;
        this.HEAP32[bufptr+60>>2] = 0;
        this.HEAP32[bufptr+64>>2] = 0;

        if (false) {
            this.HEAP32[bufptr+6*4>>2] = 4 << 12;
        } else {
            this.HEAP32[bufptr+6*4>>2] = 1 << 15;
        }

        return Promise.resolve(fd.read()).then(i => {
            this.HEAP32[bufptr+0x30>>2] = fd.readData.length;
            this.HEAP32[bufptr+0x38>>2] = fd.readData.length;
            this.HEAP32[bufptr+0x40>>2] = fd.readData.length;
            return 0;
        });
    };
    ThinThin.ioctl_p = function (fdno, code, intptr) {
        fdno = 0;
        var fd = this.fds[fdno];

        switch (code) {
        case Linux.FIONREAD:
            return fd.available().then(avail => {
                if (avail) {
                    this.HEAP32[intptr>>2] = avail;
                } else {
                    this.HEAP32[intptr>>2] = 0;
                }

                return 0;
            });

        default:
            return -Linux.EINVAL;
        }
    };
    ThinThin.ppoll = function (fdsptr, nfds, toptr, sigmaskptr) {
        var incall = true;
        var retval = 0;
        var retry = function () {
            if (incall)
                return ThinThin.ppoll.call(this,
                                           fdsptr, nfds, toptr, sigmaskptr);
        };

        var all = [];
        var any = [];

        var ii;
        for (ii = 0; ii < nfds; ii++) {
            var i = ii;
            var fdno = this.HEAP32[fdsptr+8*i>>2];
            var fd = this.fds[fdno];
            var events = this.HEAP16[fdsptr+8*i+4>>1];
            if (events & Linux.POLLIN) {
                all.push(fd.available().then((avail) => {
                    if (incall) {
                        if (avail > 0) {
                            retval += this.HEAP16[fdsptr+8*i+6>>1] == 0;
                            this.HEAP16[fdsptr+8*i+6>>1] |= Linux.POLLIN;
                        }
                    }
                }));
                any.push(() => fd.read());
            }
        }

        return Promise.all(all).then(() => {
            if (retval)
                return retval;

            var a = [];
            a.push(Promise.race(any.map(p => Promise.resolve(p()))).then(() => retry()));
            if (toptr) {
                var s = this.HEAP32[toptr>>2];
                var ns = this.HEAP32[toptr+8>>2];

                var ms = 1000 * s + 1e-6 * ns;

                a.push(TimeoutPromise(ms).then(() => 0));
            }

            return Promise.race(a).then(rval => {
                incall = false;
                return rval;
            });
        });
    };
    ThinThin.lseek = function (fdno, pos, whence) {
        console.log("lseek " + fdno + " " + pos + " " + whence);
        var fd = this.fds[fdno];

        if (whence == Linux.SEEK_SET)
            fd.readPosition = pos;
        else if (whence == Linux.SEEK_CUR)
            fd.readPosition += pos;
        else if (whence == Linux.SEEK_END)
            throw("SEEK_END not supported");
        else
            return -Linux.EINVAL;

        return fd.readPosition;
    };
    ThinThin.access = function (ptr, mode) {
        return ThinThin.stat.call(this, ptr, 0);
    };
    ThinThin.exit =         function (code) {
        if (typeof quit !== "undefined")
            quit(code);
        else if (typeof process !== "undefined")
            process.exit(code);
        else if (typeof document !== "undefined") {
            document.getElementById("output").textContent += "Exit Status " + code;
            this.stop(0xffffffff);
        }
        if (code != 0 && code !== undefined)
            throw "Exit Status " + code;
        else
            throw new SuccessException();
    };
    //ThinThin.unlink =       Module._unlink;
    //ThinThin.rename =       Module._rename;
    //ThinThin.chdir =        Module._chdir;
    ThinThin.gettimeofday = function (tvptr, tzptr) {
        var date = new Date();
        var s = date / 1000.0;
        var us = (date % 1000.0) * 1000.0;

        this.HEAP32[tvptr>>2] = s|0;
        this.HEAP32[tvptr+4>>2] = 0;
        this.HEAP32[tvptr+8>>2] = us|0;
        this.HEAP32[tvptr+12>>2] = 0;

        return 0;
    };
    ThinThin.clone = function (flags, child_stack, ptid, ctid, regs)
    {
        var new_process = this.process.clone();
    };
    ThinThin.restart = function (dst, src, len, entry)
    {
        return this.restart(dst, src, len, entry);
    };
    ThinThin.execveat = function (dirfdno, pathptr, argvptr, envpptr, flags)
    {
        if (this.HEAP8[pathptr] == "/".charCodeAt(0))
            dirfdno = Linux.AT_FDROOTD;

        var fd;
        if (this.HEAP8[pathptr] == 0 &&
            flags & Linux.AT_EMPTY_PATH)
            fd = this.fds[dirfdno];
        else
            fd = this.fds[ThinThin.openat.call(this, dirfdno, pathptr, 0)];

        if (!fd)
            return -Linux.EBADF;

        var argv = CStringsAt(argvptr);
        var envp = CStringsAt(envpptr);
        var blob = fd.blob();
    };
}

if (typeof window !== "undefined") {
    window.addEventListener("message", function (e) {
        var origin = e.origin || e.originalEvent.origin;
        alert (origin);

        if (origin &&
            origin !== "http://example.org:8080")
            return;

        var data = e.data;

        switch (data[0]) {
        case "send":
            var rfdno = data[1];
            var payload = data[2];
            var fd = gRemoteFDs[rfdno];

                alert("unknown rfd " + rfdno + " " + gRemoteFDs);
            if (fd) {
                fd.write(payload, 0, payload.byteLength);

                e.source.postMessage([rfdno, "sent"], "*");
            } else {
            }
            return;

        case "receive":
            var rfdno = data[1];
            var fd = gRemoteFDs[rfdno];
            var len = data[2];

            if (fd) {
                var heap = new ArrayBuffer(len);
                var heap8 = new Int8Array(heap);

                fd.read(heap8, 0, len).then(l => {
                    e.source.postMessage([rfdno, "read", heap], "*");
                });
            }

            return;
        }
    });
}

var sys;
var worker;

function newAsmJSModule(mod)
{
    sys = new AsmJSSystem();
    sys.instantiate(mod, args, []);

    while (sys.runqueue.length)
        sys.step();
}


//     worker = new Worker("asmjs-worker.js");
//     worker.onmessage = function (e) {
//         var data = e.data;

//         switch (data[0]) {
//         case "send":
//             var rfdno = data[1];
//             var payload = data[2];
//             var fd = gRemoteFDs[rfdno];

//             if (fd) {
//                 fd.write(new Uint8Array(payload), 0, payload.byteLength)
//                     .then((len) => {
//                         worker.postMessage(["sent", rfdno, len]);
//                     });
//             } else {
//                 alert("unknown rfd " + rfdno + " " + gRemoteFDs);
//             }
//             return;

//         case "receive":
//             var rfdno = data[1];
//             var fd = gRemoteFDs[rfdno];
//             var len = data[2];

//             if (fd) {
//                 var heap = new ArrayBuffer(len);
//                 var heap8 = new Int8Array(heap);

//                 fd.read(heap8, 0, len).then(l => {
//                     e.source.postMessage([rfdno, "read", heap], "*");
//                 });
//             }

//             return;
//         }
//     };
//     worker.postMessage(["process", sys.processes[0].freeze()]);
// }
