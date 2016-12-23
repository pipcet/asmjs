Promise.resolve(1).then(() => {
    WebAssembly.compile(os.file.readFile("libc.wasm", "binary")).then((module) => {
        imports = {};
        imports.sys = {};
        imports.sys.call = () => {};
        imports.sys.eh_return = () => {};
        imports.sys.indcall = () => {};
        imports.sys.trace = () => {};
        imports.sys.got = 0;
        imports.sys.gpo = 0;
        imports.sys.plt = 0;
        imports.sys.table = new WebAssembly.Table({element:"anyfunc",initial:65536,maximum:65536});
        imports.sys.memory = new WebAssembly.Memory({initial: 16384, maximum: 16384});
        console.log("here");
        var now = Date.now();
        while (Date.now() - now < 1000);
        return WebAssembly.instantiate(module, imports)
    }).then((e) => {
        var now = Date.now();
        while (Date.now() - now < 1000);
        console.log("here");
    }).catch(e => console.log(e));
});
