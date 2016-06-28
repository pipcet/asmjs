function a(heap, foreign)
{
    "use asm";

    function f(x,y) {
        x = x|0;
        y = y|0;

        return (x << y)|0;
    };

    return { f: f };
}
