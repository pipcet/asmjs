eval(os.file.readFile("../js/wasm32.js"));

var section = new Wasm32ModuleSection(os.file.readFile("wasm.wasm", "binary"));
var module = new Wasm32Module();
module.add_section(section);
var system = new Wasm32System();

system.instantiate(module, ["this program"], ["A=B"]).then(() => {
    console.log("up and running");
    try {
        console.log("calling main");
        system.threads[0].exports.main(0, 65535 * 1024, 0, 0, 0, 0);
    } catch (e) {
        console.log(e);
        console.log(e.stack);
    }
}).catch((e) => console.log(e));
