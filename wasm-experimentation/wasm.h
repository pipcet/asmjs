typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;

void *mem;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ai extern inline __attribute__((always_inline))

static i64 _0(i64, i64, i64, i64, i64, i64);
static i64 _1(i64, i64, i64, i64, i64, i64);
static i64 _2(i64, i64, i64, i64, i64, i64);
static i64 _3(i64, i64, i64, i64, i64, i64);
static i64 _4(i64, i64, i64, i64, i64, i64);
static i64 _5(i64, i64, i64, i64, i64, i64);
static i64 _6(i64, i64, i64, i64, i64, i64);
static i64 _7(i64, i64, i64, i64, i64, i64);
static i64 _8(i64, i64, i64, i64, i64, i64);
static i64 _9(i64, i64, i64, i64, i64, i64);
static i64 _10(i64, i64, i64, i64, i64, i64);
static i64 _11(i64, i64, i64, i64, i64, i64);
static i64 _12(i64, i64, i64, i64, i64, i64);
static i64 _13(i64, i64, i64, i64, i64, i64);
static i64 _14(i64, i64, i64, i64, i64, i64);
static i64 _15(i64, i64, i64, i64, i64, i64);
static i64 _16(i64, i64, i64, i64, i64, i64);
static i64 _17(i64, i64, i64, i64, i64, i64);
static i64 _18(i64, i64, i64, i64, i64, i64);
static i64 _19(i64, i64, i64, i64, i64, i64);
static i64 _20(i64, i64, i64, i64, i64, i64);
static i64 _21(i64, i64, i64, i64, i64, i64);
static i64 _22(i64, i64, i64, i64, i64, i64);
static i64 _23(i64, i64, i64, i64, i64, i64);
static i64 _24(i64, i64, i64, i64, i64, i64);
static i64 _25(i64, i64, i64, i64, i64, i64);
static i64 _26(i64, i64, i64, i64, i64, i64);
static i64 _27(i64, i64, i64, i64, i64, i64);
static i64 _28(i64, i64, i64, i64, i64, i64);
static i64 _29(i64, i64, i64, i64, i64, i64);
static i64 _30(i64, i64, i64, i64, i64, i64);
static i64 _31(i64, i64, i64, i64, i64, i64);
static i64 _32(i64, i64, i64, i64, i64, i64);
static i64 _33(i64, i64, i64, i64, i64, i64);
static i64 _34(i64, i64, i64, i64, i64, i64);
static i64 _35(i64, i64, i64, i64, i64, i64);
static i64 _36(i64, i64, i64, i64, i64, i64);
static i64 _37(i64, i64, i64, i64, i64, i64);
static i64 _38(i64, i64, i64, i64, i64, i64);
static i64 _39(i64, i64, i64, i64, i64, i64);
static i64 _40(i64, i64, i64, i64, i64, i64);
static i64 _41(i64, i64, i64, i64, i64, i64);
static i64 _42(i64, i64, i64, i64, i64, i64);
static i64 _43(i64, i64, i64, i64, i64, i64);
static i64 _44(i64, i64, i64, i64, i64, i64);
static i64 _45(i64, i64, i64, i64, i64, i64);
static i64 _46(i64, i64, i64, i64, i64, i64);
static i64 _47(i64, i64, i64, i64, i64, i64);
static i64 _48(i64, i64, i64, i64, i64, i64);
static i64 _49(i64, i64, i64, i64, i64, i64);
static i64 _50(i64, i64, i64, i64, i64, i64);
static i64 _51(i64, i64, i64, i64, i64, i64);
static i64 _52(i64, i64, i64, i64, i64, i64);
static i64 _53(i64, i64, i64, i64, i64, i64);
static i64 _54(i64, i64, i64, i64, i64, i64);
static i64 _55(i64, i64, i64, i64, i64, i64);
static i64 _56(i64, i64, i64, i64, i64, i64);
static i64 _57(i64, i64, i64, i64, i64, i64);
static i64 _58(i64, i64, i64, i64, i64, i64);
static i64 _59(i64, i64, i64, i64, i64, i64);
static i64 _60(i64, i64, i64, i64, i64, i64);
static i64 _61(i64, i64, i64, i64, i64, i64);
static i64 _62(i64, i64, i64, i64, i64, i64);
static i64 _63(i64, i64, i64, i64, i64, i64);
static i64 _64(i64, i64, i64, i64, i64, i64);
static i64 _65(i64, i64, i64, i64, i64, i64);
static i64 _66(i64, i64, i64, i64, i64, i64);
static i64 _67(i64, i64, i64, i64, i64, i64);
static i64 _68(i64, i64, i64, i64, i64, i64);
static i64 _69(i64, i64, i64, i64, i64, i64);
static i64 _70(i64, i64, i64, i64, i64, i64);
static i64 _71(i64, i64, i64, i64, i64, i64);
static i64 _72(i64, i64, i64, i64, i64, i64);
static i64 _73(i64, i64, i64, i64, i64, i64);
static i64 _74(i64, i64, i64, i64, i64, i64);
static i64 _75(i64, i64, i64, i64, i64, i64);
static i64 _76(i64, i64, i64, i64, i64, i64);
static i64 _77(i64, i64, i64, i64, i64, i64);
static i64 _78(i64, i64, i64, i64, i64, i64);
static i64 _79(i64, i64, i64, i64, i64, i64);
static i64 _80(i64, i64, i64, i64, i64, i64);
static i64 _81(i64, i64, i64, i64, i64, i64);
static i64 _82(i64, i64, i64, i64, i64, i64);
static i64 _83(i64, i64, i64, i64, i64, i64);
static i64 _84(i64, i64, i64, i64, i64, i64);
static i64 _85(i64, i64, i64, i64, i64, i64);
static i64 _86(i64, i64, i64, i64, i64, i64);
static i64 _87(i64, i64, i64, i64, i64, i64);
static i64 _88(i64, i64, i64, i64, i64, i64);
static i64 _89(i64, i64, i64, i64, i64, i64);
static i64 _90(i64, i64, i64, i64, i64, i64);
static i64 _91(i64, i64, i64, i64, i64, i64);
static i64 _92(i64, i64, i64, i64, i64, i64);
static i64 _93(i64, i64, i64, i64, i64, i64);
static i64 _94(i64, i64, i64, i64, i64, i64);
static i64 _95(i64, i64, i64, i64, i64, i64);
static i64 _96(i64, i64, i64, i64, i64, i64);
static i64 _97(i64, i64, i64, i64, i64, i64);
static i64 _98(i64, i64, i64, i64, i64, i64);
static i64 _99(i64, i64, i64, i64, i64, i64);
static i64 _100(i64, i64, i64, i64, i64, i64);
static i64 _101(i64, i64, i64, i64, i64, i64);
static i64 _102(i64, i64, i64, i64, i64, i64);
static i64 _103(i64, i64, i64, i64, i64, i64);
static i64 _104(i64, i64, i64, i64, i64, i64);
static i64 _105(i64, i64, i64, i64, i64, i64);
static i64 _106(i64, i64, i64, i64, i64, i64);
static i64 _107(i64, i64, i64, i64, i64, i64);
static i64 _108(i64, i64, i64, i64, i64, i64);
static i64 _109(i64, i64, i64, i64, i64, i64);
static i64 _110(i64, i64, i64, i64, i64, i64);
static i64 _111(i64, i64, i64, i64, i64, i64);
static i64 _112(i64, i64, i64, i64, i64, i64);
static i64 _113(i64, i64, i64, i64, i64, i64);
static i64 _114(i64, i64, i64, i64, i64, i64);
static i64 _115(i64, i64, i64, i64, i64, i64);
static i64 _116(i64, i64, i64, i64, i64, i64);
static i64 _117(i64, i64, i64, i64, i64, i64);
static i64 _118(i64, i64, i64, i64, i64, i64);
static i64 _119(i64, i64, i64, i64, i64, i64);
static i64 _120(i64, i64, i64, i64, i64, i64);
static i64 _121(i64, i64, i64, i64, i64, i64);
static i64 _122(i64, i64, i64, i64, i64, i64);
static i64 _123(i64, i64, i64, i64, i64, i64);
static i64 _124(i64, i64, i64, i64, i64, i64);
static i64 _125(i64, i64, i64, i64, i64, i64);
static i64 _140(i64, i64, i64, i64, i64, i64);
static i64 _142(i64, i64, i64, i64, i64, i64);
static i64 _143(i64, i64, i64, i64, i64, i64);
static i64 _144(i64, i64, i64, i64, i64, i64);
static i64 _145(i64, i64, i64, i64, i64, i64);
static i64 _146(i64, i64, i64, i64, i64, i64);
static i64 _147(i64, i64, i64, i64, i64, i64);
static i64 _148(i64, i64, i64, i64, i64, i64);
static i64 _149(i64, i64, i64, i64, i64, i64);
static i64 _150(i64, i64, i64, i64, i64, i64);
static i64 _151(i64, i64, i64, i64, i64, i64);
static i64 _152(i64, i64, i64, i64, i64, i64);
static i64 _153(i64, i64, i64, i64, i64, i64);
static i64 _154(i64, i64, i64, i64, i64, i64);
static i64 _155(i64, i64, i64, i64, i64, i64);
static i64 _156(i64, i64, i64, i64, i64, i64);
static i64 _157(i64, i64, i64, i64, i64, i64);
static i64 _158(i64, i64, i64, i64, i64, i64);
static i64 _159(i64, i64, i64, i64, i64, i64);
static i64 _160(i64, i64, i64, i64, i64, i64);
static i64 _161(i64, i64, i64, i64, i64, i64);
static i64 _162(i64, i64, i64, i64, i64, i64);
static i64 _163(i64, i64, i64, i64, i64, i64);
static i64 _164(i64, i64, i64, i64, i64, i64);
static i64 _165(i64, i64, i64, i64, i64, i64);
static i64 _166(i64, i64, i64, i64, i64, i64);
static i64 _167(i64, i64, i64, i64, i64, i64);
static i64 _168(i64, i64, i64, i64, i64, i64);
static i64 _169(i64, i64, i64, i64, i64, i64);
static i64 _170(i64, i64, i64, i64, i64, i64);
static i64 _171(i64, i64, i64, i64, i64, i64);
static i64 _172(i64, i64, i64, i64, i64, i64);
static i64 _173(i64, i64, i64, i64, i64, i64);
static i64 _174(i64, i64, i64, i64, i64, i64);
static i64 _175(i64, i64, i64, i64, i64, i64);
static i64 _176(i64, i64, i64, i64, i64, i64);
static i64 _177(i64, i64, i64, i64, i64, i64);
static i64 _178(i64, i64, i64, i64, i64, i64);
static i64 _179(i64, i64, i64, i64, i64, i64);
static i64 _180(i64, i64, i64, i64, i64, i64);
static i64 _181(i64, i64, i64, i64, i64, i64);
static i64 _182(i64, i64, i64, i64, i64, i64);
static i64 _183(i64, i64, i64, i64, i64, i64);
static i64 _184(i64, i64, i64, i64, i64, i64);
static i64 _185(i64, i64, i64, i64, i64, i64);
static i64 _186(i64, i64, i64, i64, i64, i64);
static i64 _187(i64, i64, i64, i64, i64, i64);
static i64 _188(i64, i64, i64, i64, i64, i64);
static i64 _189(i64, i64, i64, i64, i64, i64);
static i64 _190(i64, i64, i64, i64, i64, i64);
static i64 _191(i64, i64, i64, i64, i64, i64);
static i64 _192(i64, i64, i64, i64, i64, i64);
static i64 _193(i64, i64, i64, i64, i64, i64);
static i64 _194(i64, i64, i64, i64, i64, i64);
static i64 _195(i64, i64, i64, i64, i64, i64);
static i64 _196(i64, i64, i64, i64, i64, i64);
static i64 _197(i64, i64, i64, i64, i64, i64);
static i64 _198(i64, i64, i64, i64, i64, i64);
static i64 _199(i64, i64, i64, i64, i64, i64);
static i64 _200(i64, i64, i64, i64, i64, i64);
static i64 _201(i64, i64, i64, i64, i64, i64);
static i64 _202(i64, i64, i64, i64, i64, i64);
static i64 _203(i64, i64, i64, i64, i64, i64);
static i64 _204(i64, i64, i64, i64, i64, i64);
static i64 _205(i64, i64, i64, i64, i64, i64);
static i64 _206(i64, i64, i64, i64, i64, i64);
static i64 _207(i64, i64, i64, i64, i64, i64);
static i64 _208(i64, i64, i64, i64, i64, i64);
static i64 _209(i64, i64, i64, i64, i64, i64);
static i64 _210(i64, i64, i64, i64, i64, i64);
static i64 _211(i64, i64, i64, i64, i64, i64);
static i64 _212(i64, i64, i64, i64, i64, i64);
static i64 _213(i64, i64, i64, i64, i64, i64);
static i64 _214(i64, i64, i64, i64, i64, i64);
static i64 _215(i64, i64, i64, i64, i64, i64);
static i64 _216(i64, i64, i64, i64, i64, i64);
static i64 _217(i64, i64, i64, i64, i64, i64);
static i64 _218(i64, i64, i64, i64, i64, i64);
static i64 _219(i64, i64, i64, i64, i64, i64);
static i64 _220(i64, i64, i64, i64, i64, i64);
static i64 _221(i64, i64, i64, i64, i64, i64);
static i64 _222(i64, i64, i64, i64, i64, i64);
static i64 _223(i64, i64, i64, i64, i64, i64);
static i64 _224(i64, i64, i64, i64, i64, i64);
static i64 _225(i64, i64, i64, i64, i64, i64);
static i64 _226(i64, i64, i64, i64, i64, i64);
static i64 _227(i64, i64, i64, i64, i64, i64);
static i64 _228(i64, i64, i64, i64, i64, i64);
static i64 _229(i64, i64, i64, i64, i64, i64);
static i64 _230(i64, i64, i64, i64, i64, i64);
static i64 _231(i64, i64, i64, i64, i64, i64);
static i64 _232(i64, i64, i64, i64, i64, i64);
static i64 _233(i64, i64, i64, i64, i64, i64);
static i64 _234(i64, i64, i64, i64, i64, i64);
static i64 _235(i64, i64, i64, i64, i64, i64);
static i64 _236(i64, i64, i64, i64, i64, i64);
static i64 _237(i64, i64, i64, i64, i64, i64);
static i64 _238(i64, i64, i64, i64, i64, i64);
static i64 _239(i64, i64, i64, i64, i64, i64);
static i64 _240(i64, i64, i64, i64, i64, i64);
static i64 _241(i64, i64, i64, i64, i64, i64);
static i64 _242(i64, i64, i64, i64, i64, i64);
static i64 _243(i64, i64, i64, i64, i64, i64);
static i64 _244(i64, i64, i64, i64, i64, i64);
static i64 _245(i64, i64, i64, i64, i64, i64);
static i64 _246(i64, i64, i64, i64, i64, i64);
static i64 _247(i64, i64, i64, i64, i64, i64);
static i64 _248(i64, i64, i64, i64, i64, i64);
static i64 _249(i64, i64, i64, i64, i64, i64);
static i64 _250(i64, i64, i64, i64, i64, i64);
static i64 _251(i64, i64, i64, i64, i64, i64);
static i64 _252(i64, i64, i64, i64, i64, i64);
static i64 _253(i64, i64, i64, i64, i64, i64);
static i64 _254(i64, i64, i64, i64, i64, i64);
static i64 _255(i64, i64, i64, i64, i64, i64);
static i64 _256(i64, i64, i64, i64, i64, i64);
static i64 _257(i64, i64, i64, i64, i64, i64);
static i64 _258(i64, i64, i64, i64, i64, i64);
static i64 _259(i64, i64, i64, i64, i64, i64);
static i64 _260(i64, i64, i64, i64, i64, i64);
static i64 _261(i64, i64, i64, i64, i64, i64);
static i64 _262(i64, i64, i64, i64, i64, i64);
static i64 _263(i64, i64, i64, i64, i64, i64);
static i64 _264(i64, i64, i64, i64, i64, i64);
static i64 _265(i64, i64, i64, i64, i64, i64);
static i64 _266(i64, i64, i64, i64, i64, i64);
static i64 _267(i64, i64, i64, i64, i64, i64);
static i64 _268(i64, i64, i64, i64, i64, i64);
static i64 _269(i64, i64, i64, i64, i64, i64);
static i64 _270(i64, i64, i64, i64, i64, i64);
static i64 _271(i64, i64, i64, i64, i64, i64);
static i64 _272(i64, i64, i64, i64, i64, i64);
static i64 _273(i64, i64, i64, i64, i64, i64);
static i64 _274(i64, i64, i64, i64, i64, i64);
static i64 _275(i64, i64, i64, i64, i64, i64);
static i64 _276(i64, i64, i64, i64, i64, i64);
static i64 _277(i64, i64, i64, i64, i64, i64);
static i64 _278(i64, i64, i64, i64, i64, i64);
static i64 _279(i64, i64, i64, i64, i64, i64);
static i64 _280(i64, i64, i64, i64, i64, i64);
static i64 _281(i64, i64, i64, i64, i64, i64);
static i64 _282(i64, i64, i64, i64, i64, i64);
static i64 _283(i64, i64, i64, i64, i64, i64);
static i64 _284(i64, i64, i64, i64, i64, i64);
static i64 _285(i64, i64, i64, i64, i64, i64);
static i64 _286(i64, i64, i64, i64, i64, i64);
static i64 _287(i64, i64, i64, i64, i64, i64);
static i64 _288(i64, i64, i64, i64, i64, i64);
static i64 _289(i64, i64, i64, i64, i64, i64);
static i64 _290(i64, i64, i64, i64, i64, i64);
static i64 _291(i64, i64, i64, i64, i64, i64);
static i64 _292(i64, i64, i64, i64, i64, i64);
static i64 _293(i64, i64, i64, i64, i64, i64);
static i64 _294(i64, i64, i64, i64, i64, i64);
static i64 _295(i64, i64, i64, i64, i64, i64);
static i64 _296(i64, i64, i64, i64, i64, i64);
static i64 _297(i64, i64, i64, i64, i64, i64);
static i64 _298(i64, i64, i64, i64, i64, i64);
static i64 _299(i64, i64, i64, i64, i64, i64);
static i64 _300(i64, i64, i64, i64, i64, i64);
static i64 _301(i64, i64, i64, i64, i64, i64);
static i64 _302(i64, i64, i64, i64, i64, i64);
static i64 _303(i64, i64, i64, i64, i64, i64);
static i64 _304(i64, i64, i64, i64, i64, i64);
static i64 _305(i64, i64, i64, i64, i64, i64);
static i64 _306(i64, i64, i64, i64, i64, i64);
static i64 _307(i64, i64, i64, i64, i64, i64);
static i64 _308(i64, i64, i64, i64, i64, i64);
static i64 _309(i64, i64, i64, i64, i64, i64);
static i64 _310(i64, i64, i64, i64, i64, i64);
static i64 _311(i64, i64, i64, i64, i64, i64);
static i64 _312(i64, i64, i64, i64, i64, i64);
static i64 _313(i64, i64, i64, i64, i64, i64);
static i64 _314(i64, i64, i64, i64, i64, i64);
static i64 _315(i64, i64, i64, i64, i64, i64);
static i64 _316(i64, i64, i64, i64, i64, i64);
static i64 _317(i64, i64, i64, i64, i64, i64);
static i64 _318(i64, i64, i64, i64, i64, i64);
static i64 _319(i64, i64, i64, i64, i64, i64);
static i64 _320(i64, i64, i64, i64, i64, i64);
static i64 _321(i64, i64, i64, i64, i64, i64);
static i64 _322(i64, i64, i64, i64, i64, i64);
static i64 _323(i64, i64, i64, i64, i64, i64);
static i64 _324(i64, i64, i64, i64, i64, i64);
static i64 _325(i64, i64, i64, i64, i64, i64);
static i64 _326(i64, i64, i64, i64, i64, i64);
static i64 _327(i64, i64, i64, i64, i64, i64);
static i64 _328(i64, i64, i64, i64, i64, i64);
static i64 _329(i64, i64, i64, i64, i64, i64);
static i64 _330(i64, i64, i64, i64, i64, i64);
static i64 _331(i64, i64, i64, i64, i64, i64);
static i64 _332(i64, i64, i64, i64, i64, i64);
static i64 _333(i64, i64, i64, i64, i64, i64);
static i64 _334(i64, i64, i64, i64, i64, i64);
static i64 _335(i64, i64, i64, i64, i64, i64);
static i64 _336(i64, i64, i64, i64, i64, i64);
static i64 _337(i64, i64, i64, i64, i64, i64);
static i64 _338(i64, i64, i64, i64, i64, i64);
static i64 _339(i64, i64, i64, i64, i64, i64);
static i64 _340(i64, i64, i64, i64, i64, i64);
static i64 _341(i64, i64, i64, i64, i64, i64);
static i64 _342(i64, i64, i64, i64, i64, i64);
static i64 _343(i64, i64, i64, i64, i64, i64);
static i64 _344(i64, i64, i64, i64, i64, i64);
static i64 _345(i64, i64, i64, i64, i64, i64);
static i64 _346(i64, i64, i64, i64, i64, i64);
static i64 _347(i64, i64, i64, i64, i64, i64);
static i64 _348(i64, i64, i64, i64, i64, i64);
static i64 _349(i64, i64, i64, i64, i64, i64);
static i64 _350(i64, i64, i64, i64, i64, i64);
static i64 _351(i64, i64, i64, i64, i64, i64);
static i64 _352(i64, i64, i64, i64, i64, i64);
static i64 _353(i64, i64, i64, i64, i64, i64);
static i64 _354(i64, i64, i64, i64, i64, i64);
static i64 _355(i64, i64, i64, i64, i64, i64);
static i64 _356(i64, i64, i64, i64, i64, i64);
static i64 _357(i64, i64, i64, i64, i64, i64);
static i64 _358(i64, i64, i64, i64, i64, i64);
static i64 _359(i64, i64, i64, i64, i64, i64);
static i64 _360(i64, i64, i64, i64, i64, i64);
static i64 _361(i64, i64, i64, i64, i64, i64);
static i64 _362(i64, i64, i64, i64, i64, i64);
static i64 _363(i64, i64, i64, i64, i64, i64);
static i64 _364(i64, i64, i64, i64, i64, i64);
static i64 _365(i64, i64, i64, i64, i64, i64);
static i64 _366(i64, i64, i64, i64, i64, i64);
static i64 _367(i64, i64, i64, i64, i64, i64);
static i64 _368(i64, i64, i64, i64, i64, i64);
static i64 _369(i64, i64, i64, i64, i64, i64);
static i64 _370(i64, i64, i64, i64, i64, i64);
static i64 _371(i64, i64, i64, i64, i64, i64);
static i64 _372(i64, i64, i64, i64, i64, i64);
static i64 _373(i64, i64, i64, i64, i64, i64);
static i64 _374(i64, i64, i64, i64, i64, i64);
static i64 _375(i64, i64, i64, i64, i64, i64);
static i64 _376(i64, i64, i64, i64, i64, i64);
static i64 _377(i64, i64, i64, i64, i64, i64);
static i64 _378(i64, i64, i64, i64, i64, i64);
static i64 _379(i64, i64, i64, i64, i64, i64);
static i64 _380(i64, i64, i64, i64, i64, i64);
static i64 _381(i64, i64, i64, i64, i64, i64);
static i64 _382(i64, i64, i64, i64, i64, i64);
static i64 _383(i64, i64, i64, i64, i64, i64);
static i64 _384(i64, i64, i64, i64, i64, i64);
static i64 _385(i64, i64, i64, i64, i64, i64);
static i64 _386(i64, i64, i64, i64, i64, i64);
static i64 _387(i64, i64, i64, i64, i64, i64);
static i64 _388(i64, i64, i64, i64, i64, i64);
static i64 _389(i64, i64, i64, i64, i64, i64);
static i64 _390(i64, i64, i64, i64, i64, i64);
static i64 _391(i64, i64, i64, i64, i64, i64);
static i64 _392(i64, i64, i64, i64, i64, i64);
static i64 _393(i64, i64, i64, i64, i64, i64);
static i64 _394(i64, i64, i64, i64, i64, i64);
static i64 _395(i64, i64, i64, i64, i64, i64);
static i64 _396(i64, i64, i64, i64, i64, i64);
static i64 _397(i64, i64, i64, i64, i64, i64);
static i64 _398(i64, i64, i64, i64, i64, i64);
static i64 _399(i64, i64, i64, i64, i64, i64);
static i64 _400(i64, i64, i64, i64, i64, i64);
static i64 _401(i64, i64, i64, i64, i64, i64);
static i64 _402(i64, i64, i64, i64, i64, i64);
static i64 _403(i64, i64, i64, i64, i64, i64);
static i64 _404(i64, i64, i64, i64, i64, i64);
static i64 _405(i64, i64, i64, i64, i64, i64);
static i64 _406(i64, i64, i64, i64, i64, i64);
static i64 _407(i64, i64, i64, i64, i64, i64);
static i64 _408(i64, i64, i64, i64, i64, i64);
static i64 _409(i64, i64, i64, i64, i64, i64);
static i64 _410(i64, i64, i64, i64, i64, i64);
static i64 _411(i64, i64, i64, i64, i64, i64);
static i64 _412(i64, i64, i64, i64, i64, i64);
static i64 _413(i64, i64, i64, i64, i64, i64);
static i64 _414(i64, i64, i64, i64, i64, i64);
static i64 _415(i64, i64, i64, i64, i64, i64);
static i64 _416(i64, i64, i64, i64, i64, i64);
static i64 _417(i64, i64, i64, i64, i64, i64);
static i64 _418(i64, i64, i64, i64, i64, i64);
static i64 _419(i64, i64, i64, i64, i64, i64);
static i64 _420(i64, i64, i64, i64, i64, i64);
static i64 _421(i64, i64, i64, i64, i64, i64);
static i64 _422(i64, i64, i64, i64, i64, i64);
static i64 _423(i64, i64, i64, i64, i64, i64);
static i64 _424(i64, i64, i64, i64, i64, i64);
static i64 _425(i64, i64, i64, i64, i64, i64);
static i64 _426(i64, i64, i64, i64, i64, i64);
static i64 _427(i64, i64, i64, i64, i64, i64);
static i64 _428(i64, i64, i64, i64, i64, i64);
static i64 _429(i64, i64, i64, i64, i64, i64);
static i64 _430(i64, i64, i64, i64, i64, i64);
static i64 _431(i64, i64, i64, i64, i64, i64);
static i64 _432(i64, i64, i64, i64, i64, i64);
static i64 _433(i64, i64, i64, i64, i64, i64);
static i64 _434(i64, i64, i64, i64, i64, i64);
static i64 _435(i64, i64, i64, i64, i64, i64);
static i64 _436(i64, i64, i64, i64, i64, i64);
static i64 _437(i64, i64, i64, i64, i64, i64);
static i64 _438(i64, i64, i64, i64, i64, i64);
static i64 _439(i64, i64, i64, i64, i64, i64);
static i64 _440(i64, i64, i64, i64, i64, i64);
static i64 _441(i64, i64, i64, i64, i64, i64);
static i64 _442(i64, i64, i64, i64, i64, i64);
static i64 _443(i64, i64, i64, i64, i64, i64);
static i64 _444(i64, i64, i64, i64, i64, i64);
static i64 _445(i64, i64, i64, i64, i64, i64);
static i64 _446(i64, i64, i64, i64, i64, i64);
static i64 _447(i64, i64, i64, i64, i64, i64);
static i64 _448(i64, i64, i64, i64, i64, i64);
static i64 _449(i64, i64, i64, i64, i64, i64);
static i64 _450(i64, i64, i64, i64, i64, i64);
static i64 _451(i64, i64, i64, i64, i64, i64);
static i64 _452(i64, i64, i64, i64, i64, i64);
static i64 _453(i64, i64, i64, i64, i64, i64);
static i64 _454(i64, i64, i64, i64, i64, i64);
static i64 _455(i64, i64, i64, i64, i64, i64);
static i64 _456(i64, i64, i64, i64, i64, i64);
static i64 _457(i64, i64, i64, i64, i64, i64);
static i64 _458(i64, i64, i64, i64, i64, i64);
static i64 _459(i64, i64, i64, i64, i64, i64);
static i64 _460(i64, i64, i64, i64, i64, i64);
static i64 _461(i64, i64, i64, i64, i64, i64);
static i64 _462(i64, i64, i64, i64, i64, i64);
static i64 _463(i64, i64, i64, i64, i64, i64);
static i64 _464(i64, i64, i64, i64, i64, i64);
static i64 _465(i64, i64, i64, i64, i64, i64);
static i64 _466(i64, i64, i64, i64, i64, i64);
static i64 _467(i64, i64, i64, i64, i64, i64);
static i64 _468(i64, i64, i64, i64, i64, i64);
static i64 _469(i64, i64, i64, i64, i64, i64);
static i64 _470(i64, i64, i64, i64, i64, i64);
static i64 _471(i64, i64, i64, i64, i64, i64);
static i64 _472(i64, i64, i64, i64, i64, i64);
static i64 _473(i64, i64, i64, i64, i64, i64);
static i64 _474(i64, i64, i64, i64, i64, i64);
static i64 _475(i64, i64, i64, i64, i64, i64);
static i64 _476(i64, i64, i64, i64, i64, i64);
static i64 _477(i64, i64, i64, i64, i64, i64);
static i64 _478(i64, i64, i64, i64, i64, i64);
static i64 _479(i64, i64, i64, i64, i64, i64);
static i64 _480(i64, i64, i64, i64, i64, i64);
static i64 _481(i64, i64, i64, i64, i64, i64);
static i64 _482(i64, i64, i64, i64, i64, i64);
static i64 _483(i64, i64, i64, i64, i64, i64);
static i64 _484(i64, i64, i64, i64, i64, i64);
static i64 _485(i64, i64, i64, i64, i64, i64);
static i64 _486(i64, i64, i64, i64, i64, i64);
static i64 _487(i64, i64, i64, i64, i64, i64);
static i64 _488(i64, i64, i64, i64, i64, i64);
static i64 _489(i64, i64, i64, i64, i64, i64);
static i64 _490(i64, i64, i64, i64, i64, i64);
static i64 _491(i64, i64, i64, i64, i64, i64);
static i64 _492(i64, i64, i64, i64, i64, i64);
static i64 _493(i64, i64, i64, i64, i64, i64);
static i64 _494(i64, i64, i64, i64, i64, i64);
static i64 _495(i64, i64, i64, i64, i64, i64);
static i64 _496(i64, i64, i64, i64, i64, i64);
static i64 _497(i64, i64, i64, i64, i64, i64);
static i64 _498(i64, i64, i64, i64, i64, i64);
static i64 _499(i64, i64, i64, i64, i64, i64);
static i64 _500(i64, i64, i64, i64, i64, i64);
static i64 _501(i64, i64, i64, i64, i64, i64);
static i64 _502(i64, i64, i64, i64, i64, i64);
static i64 _503(i64, i64, i64, i64, i64, i64);
static i64 _504(i64, i64, i64, i64, i64, i64);
static i64 _505(i64, i64, i64, i64, i64, i64);
static i64 _506(i64, i64, i64, i64, i64, i64);
static i64 _507(i64, i64, i64, i64, i64, i64);
static i64 _508(i64, i64, i64, i64, i64, i64);
static i64 _509(i64, i64, i64, i64, i64, i64);
static i64 _510(i64, i64, i64, i64, i64, i64);
static i64 _511(i64, i64, i64, i64, i64, i64);
static i64 _512(i64, i64, i64, i64, i64, i64);
static i64 _513(i64, i64, i64, i64, i64, i64);
static i64 _514(i64, i64, i64, i64, i64, i64);
static i64 _515(i64, i64, i64, i64, i64, i64);
static i64 _516(i64, i64, i64, i64, i64, i64);
static i64 _517(i64, i64, i64, i64, i64, i64);
static i64 _518(i64, i64, i64, i64, i64, i64);
static i64 _519(i64, i64, i64, i64, i64, i64);
static i64 _520(i64, i64, i64, i64, i64, i64);
static i64 _521(i64, i64, i64, i64, i64, i64);
static i64 _522(i64, i64, i64, i64, i64, i64);
static i64 _523(i64, i64, i64, i64, i64, i64);
static i64 _524(i64, i64, i64, i64, i64, i64);
static i64 _525(i64, i64, i64, i64, i64, i64);
static i64 _526(i64, i64, i64, i64, i64, i64);
static i64 _527(i64, i64, i64, i64, i64, i64);
static i64 _528(i64, i64, i64, i64, i64, i64);
static i64 _529(i64, i64, i64, i64, i64, i64);
static i64 _530(i64, i64, i64, i64, i64, i64);
static i64 _531(i64, i64, i64, i64, i64, i64);
static i64 _532(i64, i64, i64, i64, i64, i64);
static i64 _533(i64, i64, i64, i64, i64, i64);
static i64 _534(i64, i64, i64, i64, i64, i64);
static i64 _535(i64, i64, i64, i64, i64, i64);
static i64 _536(i64, i64, i64, i64, i64, i64);
static i64 _537(i64, i64, i64, i64, i64, i64);
static i64 _538(i64, i64, i64, i64, i64, i64);
static i64 _539(i64, i64, i64, i64, i64, i64);
static i64 _540(i64, i64, i64, i64, i64, i64);
static i64 _541(i64, i64, i64, i64, i64, i64);
static i64 _542(i64, i64, i64, i64, i64, i64);
static i64 _543(i64, i64, i64, i64, i64, i64);
static i64 _544(i64, i64, i64, i64, i64, i64);
static i64 _545(i64, i64, i64, i64, i64, i64);
static i64 _546(i64, i64, i64, i64, i64, i64);
static i64 _547(i64, i64, i64, i64, i64, i64);
static i64 _548(i64, i64, i64, i64, i64, i64);
static i64 _549(i64, i64, i64, i64, i64, i64);
static i64 _550(i64, i64, i64, i64, i64, i64);
static i64 _551(i64, i64, i64, i64, i64, i64);
static i64 _552(i64, i64, i64, i64, i64, i64);
static i64 _553(i64, i64, i64, i64, i64, i64);
static i64 _554(i64, i64, i64, i64, i64, i64);
static i64 _555(i64, i64, i64, i64, i64, i64);
static i64 _556(i64, i64, i64, i64, i64, i64);
static i64 _557(i64, i64, i64, i64, i64, i64);
static i64 _558(i64, i64, i64, i64, i64, i64);
static i64 _559(i64, i64, i64, i64, i64, i64);
static i64 _560(i64, i64, i64, i64, i64, i64);
static i64 _561(i64, i64, i64, i64, i64, i64);
static i64 _562(i64, i64, i64, i64, i64, i64);
static i64 _563(i64, i64, i64, i64, i64, i64);
static i64 _564(i64, i64, i64, i64, i64, i64);
static i64 _565(i64, i64, i64, i64, i64, i64);
static i64 _566(i64, i64, i64, i64, i64, i64);
static i64 _567(i64, i64, i64, i64, i64, i64);
static i64 _568(i64, i64, i64, i64, i64, i64);
static i64 _569(i64, i64, i64, i64, i64, i64);
static i64 _570(i64, i64, i64, i64, i64, i64);
static i64 _571(i64, i64, i64, i64, i64, i64);
static i64 _572(i64, i64, i64, i64, i64, i64);
static i64 _573(i64, i64, i64, i64, i64, i64);
static i64 _574(i64, i64, i64, i64, i64, i64);
static i64 _575(i64, i64, i64, i64, i64, i64);
static i64 _576(i64, i64, i64, i64, i64, i64);
static i64 _577(i64, i64, i64, i64, i64, i64);
static i64 _578(i64, i64, i64, i64, i64, i64);
static i64 _579(i64, i64, i64, i64, i64, i64);
static i64 _580(i64, i64, i64, i64, i64, i64);
static i64 _581(i64, i64, i64, i64, i64, i64);
static i64 _582(i64, i64, i64, i64, i64, i64);
static i64 _583(i64, i64, i64, i64, i64, i64);
static i64 _584(i64, i64, i64, i64, i64, i64);
static i64 _585(i64, i64, i64, i64, i64, i64);
static i64 _586(i64, i64, i64, i64, i64, i64);
static i64 _587(i64, i64, i64, i64, i64, i64);
static i64 _588(i64, i64, i64, i64, i64, i64);
static i64 _589(i64, i64, i64, i64, i64, i64);
static i64 _590(i64, i64, i64, i64, i64, i64);
static i64 _591(i64, i64, i64, i64, i64, i64);
static i64 _592(i64, i64, i64, i64, i64, i64);
static i64 _593(i64, i64, i64, i64, i64, i64);
static i64 _594(i64, i64, i64, i64, i64, i64);
static i64 _595(i64, i64, i64, i64, i64, i64);
static i64 _596(i64, i64, i64, i64, i64, i64);
static i64 _597(i64, i64, i64, i64, i64, i64);
static i64 _598(i64, i64, i64, i64, i64, i64);
static i64 _599(i64, i64, i64, i64, i64, i64);
static i64 _600(i64, i64, i64, i64, i64, i64);
static i64 _601(i64, i64, i64, i64, i64, i64);
static i64 _602(i64, i64, i64, i64, i64, i64);
static i64 _603(i64, i64, i64, i64, i64, i64);
static i64 _604(i64, i64, i64, i64, i64, i64);
static i64 _605(i64, i64, i64, i64, i64, i64);
static i64 _606(i64, i64, i64, i64, i64, i64);
static i64 _607(i64, i64, i64, i64, i64, i64);
static i64 _608(i64, i64, i64, i64, i64, i64);
static i64 _609(i64, i64, i64, i64, i64, i64);
static i64 _610(i64, i64, i64, i64, i64, i64);
static i64 _611(i64, i64, i64, i64, i64, i64);
static i64 _612(i64, i64, i64, i64, i64, i64);
static i64 _613(i64, i64, i64, i64, i64, i64);
static i64 _614(i64, i64, i64, i64, i64, i64);
static i64 _615(i64, i64, i64, i64, i64, i64);
static i64 _616(i64, i64, i64, i64, i64, i64);
static i64 _617(i64, i64, i64, i64, i64, i64);
static i64 _618(i64, i64, i64, i64, i64, i64);
static i64 _619(i64, i64, i64, i64, i64, i64);
static i64 _620(i64, i64, i64, i64, i64, i64);
static i64 _621(i64, i64, i64, i64, i64, i64);
static i64 _622(i64, i64, i64, i64, i64, i64);
static i64 _623(i64, i64, i64, i64, i64, i64);
static i64 _624(i64, i64, i64, i64, i64, i64);
static i64 _625(i64, i64, i64, i64, i64, i64);
static i64 _626(i64, i64, i64, i64, i64, i64);
static i64 _627(i64, i64, i64, i64, i64, i64);
static i64 _628(i64, i64, i64, i64, i64, i64);
static i64 _629(i64, i64, i64, i64, i64, i64);
static i64 _630(i64, i64, i64, i64, i64, i64);
static i64 _631(i64, i64, i64, i64, i64, i64);
static i64 _632(i64, i64, i64, i64, i64, i64);
static i64 _633(i64, i64, i64, i64, i64, i64);
static i64 _634(i64, i64, i64, i64, i64, i64);
static i64 _635(i64, i64, i64, i64, i64, i64);
static i64 _636(i64, i64, i64, i64, i64, i64);
static i64 _637(i64, i64, i64, i64, i64, i64);
static i64 _638(i64, i64, i64, i64, i64, i64);
static i64 _639(i64, i64, i64, i64, i64, i64);
static i64 _640(i64, i64, i64, i64, i64, i64);
static i64 _641(i64, i64, i64, i64, i64, i64);
static i64 _642(i64, i64, i64, i64, i64, i64);
static i64 _643(i64, i64, i64, i64, i64, i64);
static i64 _644(i64, i64, i64, i64, i64, i64);
static i64 _645(i64, i64, i64, i64, i64, i64);
static i64 _646(i64, i64, i64, i64, i64, i64);
static i64 _647(i64, i64, i64, i64, i64, i64);
static i64 _648(i64, i64, i64, i64, i64, i64);
static i64 _649(i64, i64, i64, i64, i64, i64);
static i64 _650(i64, i64, i64, i64, i64, i64);
static i64 _651(i64, i64, i64, i64, i64, i64);
static i64 _652(i64, i64, i64, i64, i64, i64);
static i64 _653(i64, i64, i64, i64, i64, i64);
static i64 _654(i64, i64, i64, i64, i64, i64);
static i64 _655(i64, i64, i64, i64, i64, i64);
static i64 _656(i64, i64, i64, i64, i64, i64);
static i64 _657(i64, i64, i64, i64, i64, i64);
static i64 _658(i64, i64, i64, i64, i64, i64);
static i64 _659(i64, i64, i64, i64, i64, i64);
static i64 _660(i64, i64, i64, i64, i64, i64);
static i64 _661(i64, i64, i64, i64, i64, i64);
static i64 _662(i64, i64, i64, i64, i64, i64);
static i64 _663(i64, i64, i64, i64, i64, i64);
static i64 _664(i64, i64, i64, i64, i64, i64);
static i64 _665(i64, i64, i64, i64, i64, i64);
static i64 _666(i64, i64, i64, i64, i64, i64);
static i64 _667(i64, i64, i64, i64, i64, i64);
static i64 _668(i64, i64, i64, i64, i64, i64);
static i64 _669(i64, i64, i64, i64, i64, i64);
static i64 _670(i64, i64, i64, i64, i64, i64);
static i64 _671(i64, i64, i64, i64, i64, i64);
static i64 _672(i64, i64, i64, i64, i64, i64);
static i64 _673(i64, i64, i64, i64, i64, i64);
static i64 _674(i64, i64, i64, i64, i64, i64);
static i64 _675(i64, i64, i64, i64, i64, i64);
static i64 _676(i64, i64, i64, i64, i64, i64);
static i64 _677(i64, i64, i64, i64, i64, i64);
static i64 _678(i64, i64, i64, i64, i64, i64);
static i64 _679(i64, i64, i64, i64, i64, i64);
static i64 _680(i64, i64, i64, i64, i64, i64);
static i64 _681(i64, i64, i64, i64, i64, i64);
static i64 _682(i64, i64, i64, i64, i64, i64);
static i64 _683(i64, i64, i64, i64, i64, i64);
static i64 _684(i64, i64, i64, i64, i64, i64);
static i64 _685(i64, i64, i64, i64, i64, i64);
static i64 _686(i64, i64, i64, i64, i64, i64);
static i64 _687(i64, i64, i64, i64, i64, i64);
static i64 _688(i64, i64, i64, i64, i64, i64);
static i64 _689(i64, i64, i64, i64, i64, i64);
static i64 _690(i64, i64, i64, i64, i64, i64);
static i64 _691(i64, i64, i64, i64, i64, i64);
static i64 _692(i64, i64, i64, i64, i64, i64);
static i64 _693(i64, i64, i64, i64, i64, i64);
static i64 _694(i64, i64, i64, i64, i64, i64);
static i64 _695(i64, i64, i64, i64, i64, i64);
static i64 _696(i64, i64, i64, i64, i64, i64);
static i64 _697(i64, i64, i64, i64, i64, i64);
static i64 _698(i64, i64, i64, i64, i64, i64);
static i64 _699(i64, i64, i64, i64, i64, i64);
static i64 _700(i64, i64, i64, i64, i64, i64);
static i64 _701(i64, i64, i64, i64, i64, i64);
static i64 _702(i64, i64, i64, i64, i64, i64);
static i64 _703(i64, i64, i64, i64, i64, i64);
static i64 _704(i64, i64, i64, i64, i64, i64);
static i64 _705(i64, i64, i64, i64, i64, i64);
static i64 _706(i64, i64, i64, i64, i64, i64);
static i64 _707(i64, i64, i64, i64, i64, i64);
static i64 _708(i64, i64, i64, i64, i64, i64);
static i64 _709(i64, i64, i64, i64, i64, i64);
static i64 _710(i64, i64, i64, i64, i64, i64);
static i64 _711(i64, i64, i64, i64, i64, i64);
static i64 _712(i64, i64, i64, i64, i64, i64);
static i64 _713(i64, i64, i64, i64, i64, i64);
static i64 _714(i64, i64, i64, i64, i64, i64);
static i64 _715(i64, i64, i64, i64, i64, i64);
static i64 _716(i64, i64, i64, i64, i64, i64);
static i64 _717(i64, i64, i64, i64, i64, i64);
static i64 _718(i64, i64, i64, i64, i64, i64);
static i64 _719(i64, i64, i64, i64, i64, i64);
static i64 _720(i64, i64, i64, i64, i64, i64);
static i64 _721(i64, i64, i64, i64, i64, i64);
static i64 _722(i64, i64, i64, i64, i64, i64);
static i64 _723(i64, i64, i64, i64, i64, i64);
static i64 _724(i64, i64, i64, i64, i64, i64);
static i64 _725(i64, i64, i64, i64, i64, i64);
static i64 _726(i64, i64, i64, i64, i64, i64);
static i64 _727(i64, i64, i64, i64, i64, i64);
static i64 _728(i64, i64, i64, i64, i64, i64);
static i64 _729(i64, i64, i64, i64, i64, i64);
static i64 _730(i64, i64, i64, i64, i64, i64);
static i64 _731(i64, i64, i64, i64, i64, i64);
static i64 _732(i64, i64, i64, i64, i64, i64);
static i64 _733(i64, i64, i64, i64, i64, i64);
static i64 _734(i64, i64, i64, i64, i64, i64);
static i64 _735(i64, i64, i64, i64, i64, i64);
static i64 _736(i64, i64, i64, i64, i64, i64);
static i64 _737(i64, i64, i64, i64, i64, i64);
static i64 _738(i64, i64, i64, i64, i64, i64);
static i64 _739(i64, i64, i64, i64, i64, i64);
static i64 _740(i64, i64, i64, i64, i64, i64);
static i64 _741(i64, i64, i64, i64, i64, i64);
static i64 _742(i64, i64, i64, i64, i64, i64);
static i64 _743(i64, i64, i64, i64, i64, i64);
static i64 _744(i64, i64, i64, i64, i64, i64);
static i64 _745(i64, i64, i64, i64, i64, i64);
static i64 _746(i64, i64, i64, i64, i64, i64);
static i64 _747(i64, i64, i64, i64, i64, i64);
static i64 _748(i64, i64, i64, i64, i64, i64);
static i64 _749(i64, i64, i64, i64, i64, i64);
static i64 _750(i64, i64, i64, i64, i64, i64);
static i64 _751(i64, i64, i64, i64, i64, i64);
static i64 _752(i64, i64, i64, i64, i64, i64);
static i64 _753(i64, i64, i64, i64, i64, i64);
static i64 _754(i64, i64, i64, i64, i64, i64);
static i64 _755(i64, i64, i64, i64, i64, i64);
static i64 _756(i64, i64, i64, i64, i64, i64);
static i64 _757(i64, i64, i64, i64, i64, i64);
static i64 _758(i64, i64, i64, i64, i64, i64);
static i64 _759(i64, i64, i64, i64, i64, i64);
static i64 _760(i64, i64, i64, i64, i64, i64);
static i64 _761(i64, i64, i64, i64, i64, i64);
static i64 _762(i64, i64, i64, i64, i64, i64);
static i64 _763(i64, i64, i64, i64, i64, i64);
static i64 _764(i64, i64, i64, i64, i64, i64);
static i64 _765(i64, i64, i64, i64, i64, i64);
static i64 _766(i64, i64, i64, i64, i64, i64);
static i64 _767(i64, i64, i64, i64, i64, i64);
static i64 _768(i64, i64, i64, i64, i64, i64);
static i64 _769(i64, i64, i64, i64, i64, i64);
static i64 _770(i64, i64, i64, i64, i64, i64);
static i64 _771(i64, i64, i64, i64, i64, i64);
static i64 _772(i64, i64, i64, i64, i64, i64);
static i64 _773(i64, i64, i64, i64, i64, i64);
static i64 _774(i64, i64, i64, i64, i64, i64);
static i64 _775(i64, i64, i64, i64, i64, i64);
static i64 _776(i64, i64, i64, i64, i64, i64);
static i64 _777(i64, i64, i64, i64, i64, i64);
static i64 _778(i64, i64, i64, i64, i64, i64);
static i64 _779(i64, i64, i64, i64, i64, i64);
static i64 _780(i64, i64, i64, i64, i64, i64);
static i64 _781(i64, i64, i64, i64, i64, i64);
static i64 _782(i64, i64, i64, i64, i64, i64);
static i64 _783(i64, i64, i64, i64, i64, i64);
static i64 _784(i64, i64, i64, i64, i64, i64);
static i64 _785(i64, i64, i64, i64, i64, i64);
static i64 _786(i64, i64, i64, i64, i64, i64);
static i64 _787(i64, i64, i64, i64, i64, i64);
static i64 _788(i64, i64, i64, i64, i64, i64);
static i64 _789(i64, i64, i64, i64, i64, i64);
static i64 _790(i64, i64, i64, i64, i64, i64);
static i64 _791(i64, i64, i64, i64, i64, i64);
static i64 _792(i64, i64, i64, i64, i64, i64);
static i64 _793(i64, i64, i64, i64, i64, i64);
static i64 _794(i64, i64, i64, i64, i64, i64);
static i64 _795(i64, i64, i64, i64, i64, i64);
static i64 _796(i64, i64, i64, i64, i64, i64);
static i64 _797(i64, i64, i64, i64, i64, i64);
static i64 _798(i64, i64, i64, i64, i64, i64);
static i64 _799(i64, i64, i64, i64, i64, i64);
static i64 _800(i64, i64, i64, i64, i64, i64);
static i64 _801(i64, i64, i64, i64, i64, i64);
static i64 _802(i64, i64, i64, i64, i64, i64);
static i64 _803(i64, i64, i64, i64, i64, i64);
static i64 _804(i64, i64, i64, i64, i64, i64);
static i64 _805(i64, i64, i64, i64, i64, i64);
static i64 _806(i64, i64, i64, i64, i64, i64);
static i64 _807(i64, i64, i64, i64, i64, i64);
static i64 _808(i64, i64, i64, i64, i64, i64);
static i64 _809(i64, i64, i64, i64, i64, i64);
static i64 _810(i64, i64, i64, i64, i64, i64);
static i64 _811(i64, i64, i64, i64, i64, i64);
static i64 _812(i64, i64, i64, i64, i64, i64);
static i64 _813(i64, i64, i64, i64, i64, i64);
static i64 _814(i64, i64, i64, i64, i64, i64);
static i64 _815(i64, i64, i64, i64, i64, i64);
static i64 _816(i64, i64, i64, i64, i64, i64);
static i64 _817(i64, i64, i64, i64, i64, i64);
static i64 _818(i64, i64, i64, i64, i64, i64);
static i64 _819(i64, i64, i64, i64, i64, i64);
static i64 _820(i64, i64, i64, i64, i64, i64);
static i64 _821(i64, i64, i64, i64, i64, i64);
static i64 _822(i64, i64, i64, i64, i64, i64);
static i64 _823(i64, i64, i64, i64, i64, i64);
static i64 _824(i64, i64, i64, i64, i64, i64);
static i64 _825(i64, i64, i64, i64, i64, i64);
static i64 _826(i64, i64, i64, i64, i64, i64);
static i64 _827(i64, i64, i64, i64, i64, i64);
static i64 _828(i64, i64, i64, i64, i64, i64);
static i64 _829(i64, i64, i64, i64, i64, i64);
static i64 _830(i64, i64, i64, i64, i64, i64);
static i64 _831(i64, i64, i64, i64, i64, i64);
static i64 _832(i64, i64, i64, i64, i64, i64);
static i64 _833(i64, i64, i64, i64, i64, i64);
static i64 _834(i64, i64, i64, i64, i64, i64);
static i64 _835(i64, i64, i64, i64, i64, i64);
static i64 _836(i64, i64, i64, i64, i64, i64);
static i64 _837(i64, i64, i64, i64, i64, i64);
static i64 _838(i64, i64, i64, i64, i64, i64);
static i64 _839(i64, i64, i64, i64, i64, i64);
static i64 _840(i64, i64, i64, i64, i64, i64);
static i64 _841(i64, i64, i64, i64, i64, i64);
static i64 _842(i64, i64, i64, i64, i64, i64);
static i64 _843(i64, i64, i64, i64, i64, i64);
static i64 _844(i64, i64, i64, i64, i64, i64);
static i64 _845(i64, i64, i64, i64, i64, i64);
static i64 _846(i64, i64, i64, i64, i64, i64);
static i64 _847(i64, i64, i64, i64, i64, i64);
static i64 _848(i64, i64, i64, i64, i64, i64);
static i64 _849(i64, i64, i64, i64, i64, i64);
static i64 _850(i64, i64, i64, i64, i64, i64);
static i64 _851(i64, i64, i64, i64, i64, i64);
static i64 _852(i64, i64, i64, i64, i64, i64);
static i64 _853(i64, i64, i64, i64, i64, i64);
static i64 _854(i64, i64, i64, i64, i64, i64);
static i64 _855(i64, i64, i64, i64, i64, i64);
static i64 _856(i64, i64, i64, i64, i64, i64);
static i64 _857(i64, i64, i64, i64, i64, i64);
static i64 _858(i64, i64, i64, i64, i64, i64);
static i64 _859(i64, i64, i64, i64, i64, i64);
static i64 _860(i64, i64, i64, i64, i64, i64);
static i64 _861(i64, i64, i64, i64, i64, i64);
static i64 _862(i64, i64, i64, i64, i64, i64);
static i64 _863(i64, i64, i64, i64, i64, i64);
static i64 _864(i64, i64, i64, i64, i64, i64);
static i64 _865(i64, i64, i64, i64, i64, i64);
static i64 _866(i64, i64, i64, i64, i64, i64);
static i64 _867(i64, i64, i64, i64, i64, i64);
static i64 _868(i64, i64, i64, i64, i64, i64);
static i64 _869(i64, i64, i64, i64, i64, i64);
static i64 _870(i64, i64, i64, i64, i64, i64);
static i64 _871(i64, i64, i64, i64, i64, i64);
static i64 _872(i64, i64, i64, i64, i64, i64);
static i64 _873(i64, i64, i64, i64, i64, i64);
static i64 _874(i64, i64, i64, i64, i64, i64);
static i64 _875(i64, i64, i64, i64, i64, i64);
static i64 _876(i64, i64, i64, i64, i64, i64);
static i64 _877(i64, i64, i64, i64, i64, i64);
static i64 _878(i64, i64, i64, i64, i64, i64);
static i64 _879(i64, i64, i64, i64, i64, i64);
static i64 _880(i64, i64, i64, i64, i64, i64);
static i64 _881(i64, i64, i64, i64, i64, i64);
static i64 _882(i64, i64, i64, i64, i64, i64);
static i64 _883(i64, i64, i64, i64, i64, i64);
static i64 _884(i64, i64, i64, i64, i64, i64);
static i64 _885(i64, i64, i64, i64, i64, i64);
static i64 _886(i64, i64, i64, i64, i64, i64);
static i64 _887(i64, i64, i64, i64, i64, i64);
static i64 _888(i64, i64, i64, i64, i64, i64);
static i64 _889(i64, i64, i64, i64, i64, i64);
static i64 _890(i64, i64, i64, i64, i64, i64);
static i64 _891(i64, i64, i64, i64, i64, i64);
static i64 _892(i64, i64, i64, i64, i64, i64);
static i64 _893(i64, i64, i64, i64, i64, i64);
static i64 _894(i64, i64, i64, i64, i64, i64);
static i64 _895(i64, i64, i64, i64, i64, i64);
static i64 _896(i64, i64, i64, i64, i64, i64);
static i64 _897(i64, i64, i64, i64, i64, i64);
static i64 _898(i64, i64, i64, i64, i64, i64);
static i64 _899(i64, i64, i64, i64, i64, i64);
static i64 _900(i64, i64, i64, i64, i64, i64);
static i64 _901(i64, i64, i64, i64, i64, i64);
static i64 _902(i64, i64, i64, i64, i64, i64);
static i64 _903(i64, i64, i64, i64, i64, i64);
static i64 _904(i64, i64, i64, i64, i64, i64);
static i64 _905(i64, i64, i64, i64, i64, i64);
static i64 _906(i64, i64, i64, i64, i64, i64);
static i64 _907(i64, i64, i64, i64, i64, i64);
static i64 _908(i64, i64, i64, i64, i64, i64);
static i64 _909(i64, i64, i64, i64, i64, i64);
static i64 _910(i64, i64, i64, i64, i64, i64);
static i64 _911(i64, i64, i64, i64, i64, i64);
static i64 _912(i64, i64, i64, i64, i64, i64);
static i64 _913(i64, i64, i64, i64, i64, i64);
static i64 _914(i64, i64, i64, i64, i64, i64);
static i64 _915(i64, i64, i64, i64, i64, i64);
static i64 _916(i64, i64, i64, i64, i64, i64);
static i64 _917(i64, i64, i64, i64, i64, i64);
static i64 _918(i64, i64, i64, i64, i64, i64);
static i64 _919(i64, i64, i64, i64, i64, i64);
static i64 _920(i64, i64, i64, i64, i64, i64);
static i64 _921(i64, i64, i64, i64, i64, i64);
static i64 _922(i64, i64, i64, i64, i64, i64);
static i64 _923(i64, i64, i64, i64, i64, i64);
static i64 _924(i64, i64, i64, i64, i64, i64);
static i64 _925(i64, i64, i64, i64, i64, i64);
static i64 _926(i64, i64, i64, i64, i64, i64);
static i64 _927(i64, i64, i64, i64, i64, i64);
static i64 _928(i64, i64, i64, i64, i64, i64);
static i64 _929(i64, i64, i64, i64, i64, i64);
static i64 _930(i64, i64, i64, i64, i64, i64);
static i64 _931(i64, i64, i64, i64, i64, i64);
static i64 _932(i64, i64, i64, i64, i64, i64);
static i64 _933(i64, i64, i64, i64, i64, i64);
static i64 _934(i64, i64, i64, i64, i64, i64);
static i64 _935(i64, i64, i64, i64, i64, i64);
static i64 _936(i64, i64, i64, i64, i64, i64);
static i64 _1002(i64, i64, i64, i64, i64, i64);
static i64 _1003(i64, i64, i64, i64, i64, i64);
static i64 _1004(i64, i64, i64, i64, i64, i64);
static i64 _1005(i64, i64, i64, i64, i64, i64);
static i64 _1006(i64, i64, i64, i64, i64, i64);
static i64 _1007(i64, i64, i64, i64, i64, i64);
static i64 _1008(i64, i64, i64, i64, i64, i64);
static i64 _1009(i64, i64, i64, i64, i64, i64);
static i64 _1010(i64, i64, i64, i64, i64, i64);
static i64 _1011(i64, i64, i64, i64, i64, i64);
static i64 _1012(i64, i64, i64, i64, i64, i64);
static i64 _1013(i64, i64, i64, i64, i64, i64);
static i64 _1014(i64, i64, i64, i64, i64, i64);
static i64 _1015(i64, i64, i64, i64, i64, i64);
static i64 _1016(i64, i64, i64, i64, i64, i64);
static i64 _1017(i64, i64, i64, i64, i64, i64);
static i64 _1018(i64, i64, i64, i64, i64, i64);
static i64 _1019(i64, i64, i64, i64, i64, i64);
static i64 _1020(i64, i64, i64, i64, i64, i64);
static i64 _1021(i64, i64, i64, i64, i64, i64);
static i64 _1022(i64, i64, i64, i64, i64, i64);
static i64 _1023(i64, i64, i64, i64, i64, i64);

ai i32 i64_eq(i64 a, i64 b) { return a == b; }
ai i32 i64_ne(i64 a, i64 b) { return a != b; }

ai i32 f64_eq(f64 a, f64 b) { return a == b; }
ai i32 f64_ne(f64 a, f64 b) { return a != b; }
ai i32 f64_lt(f64 a, f64 b) { return a <  b; }
ai i32 f64_gt(f64 a, f64 b) { return a >  b; }
ai i32 f64_le(f64 a, f64 b) { return a <= b; }
ai i32 f64_ge(f64 a, f64 b) { return a >= b; }

ai i32 f32_eq(f32 a, f32 b) { return a == b; }
ai i32 f32_ne(f32 a, f32 b) { return a != b; }
ai i32 f32_lt(f32 a, f32 b) { return a <  b; }
ai i32 f32_gt(f32 a, f32 b) { return a >  b; }
ai i32 f32_le(f32 a, f32 b) { return a <= b; }
ai i32 f32_ge(f32 a, f32 b) { return a >= b; }

ai i32 i64_lt_u(i64 a, i64 b) { return (unsigned long)a <  (unsigned long)b; }
ai i32 i64_gt_u(i64 a, i64 b) { return (unsigned long)a >  (unsigned long)b; }
ai i32 i64_le_u(i64 a, i64 b) { return (unsigned long)a <= (unsigned long)b; }
ai i32 i64_ge_u(i64 a, i64 b) { return (unsigned long)a >= (unsigned long)b; }

ai i32 i64_lt_s(i64 a, i64 b) { return a <  b; }
ai i32 i64_gt_s(i64 a, i64 b) { return a >  b; }
ai i32 i64_le_s(i64 a, i64 b) { return a <= b; }
ai i32 i64_ge_s(i64 a, i64 b) { return a >= b; }

ai i32 i32_eq(i32 a, i32 b) { return a == b; }
ai i32 i32_ne(i32 a, i32 b) { return a != b; }

ai i32 i32_lt_u(i32 a, i32 b) { return (unsigned)a <  (unsigned)b; }
ai i32 i32_gt_u(i32 a, i32 b) { return (unsigned)a >  (unsigned)b; }
ai i32 i32_le_u(i32 a, i32 b) { return (unsigned)a <= (unsigned)b; }
ai i32 i32_ge_u(i32 a, i32 b) { return (unsigned)a >= (unsigned)b; }

ai i32 i32_lt_s(i32 a, i32 b) { return a <  b; }
ai i32 i32_gt_s(i32 a, i32 b) { return a >  b; }
ai i32 i32_le_s(i32 a, i32 b) { return a <= b; }
ai i32 i32_ge_s(i32 a, i32 b) { return a >= b; }

ai i64 i64_shl(i64 a, i64 b) { return a << (b&63); }
ai i64 i64_shr_s(i64 a, i64 b) { return a >> (b&63); }
ai i64 i64_shr_u(i64 a, i64 b) { return (unsigned long)a >> (b&63); }
ai i64 i64_rotr(i64 a, i64 b) { return a>>(b&63) | a<<(32-(b&63)); }
ai i64 i64_rotl(i64 a, i64 b) { return a<<(b&63) | a>>(32-(b&63)); }

ai i32 i32_shl(i32 a, i32 b) { return a << (b&31); }
ai i32 i32_shr_s(i32 a, i32 b) { return a >> (b&31); }
ai i32 i32_shr_u(i32 a, i32 b) { return (unsigned long)a >> (b&31); }
ai i32 i32_rotr(i32 a, i32 b) { return a>>(b&31) | a<<(32-(b&31)); }
ai i32 i32_rotl(i32 a, i32 b) { return a<<(b&31) | a>>(32-(b&31)); }

ai i64 i64_reinterpret_f64(f64 x)
{
  return *(i64 *)(&x);
}

ai f64 f64_reinterpret_i64(i64 x)
{
  return *(f64 *)(&x);
}

ai i32 i32_reinterpret_f32(f32 x)
{
  return *(i32 *)(&x);
}

ai f32 f32_reinterpret_i32(i32 x)
{
  return *(f32 *)(&x);
}

ai i32 fix_ptr(i32 ptr)
{
  return ptr & 0xffffffff;
}

ai i32 load_i32_i8_u(i32 ptr)
{
  return *(unsigned char *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i8_s(i32 ptr)
{
  return *(signed char *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i16_u(i32 ptr)
{
  return *(unsigned short *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i16_s(i32 ptr)
{
  return *(short *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i32_u(i32 ptr)
{
  return *(i32 *)(mem + fix_ptr(ptr));
}

ai i32 load_i32_i32_s(i32 ptr)
{
  return *(i32 *)(mem + fix_ptr(ptr));
}

ai i64 load_i64_i64_u(i32 ptr)
{
  return *(i64 *)(mem + fix_ptr(ptr));
}

ai i64 load_i64_i64_s(i32 ptr)
{
  return *(i64 *)(mem + fix_ptr(ptr));
}

ai f32 load_f32_f32(i32 ptr)
{
  return *(f32 *)(mem + fix_ptr(ptr));
}

ai f64 load_f64_f64(i32 ptr)
{
  return *(f64 *)(mem + fix_ptr(ptr));
}

ai i32 i32_wrap_i64(i64 x)
{
  return (i32)x;
}

ai i64 i64_extend_s_i32(i32 x)
{
  return (i64)x;
}

ai i64 i64_extend_u_i32(i32 x)
{
  return (i64)(unsigned int)x;
}

ai i32 store_i32_i8(i32 ptr, i32 value)
{
  return *(char *)(mem + fix_ptr(ptr)) = value;
}

ai i32 store_i32_i16(i32 ptr, i32 value)
{
  return *(short *)(mem + fix_ptr(ptr)) = value;
}

ai i32 store_i32_i32(i32 ptr, i32 value)
{
  return *(i32 *)(mem + fix_ptr(ptr)) = value;
}

ai i64 store_i64_i64(i32 ptr, i64 value)
{
  return *(i64 *)(mem + fix_ptr(ptr)) = value;
}

ai f64 store_f64_f64(i32 ptr, f64 value)
{
  return *(f64 *)(mem + fix_ptr(ptr)) = value;
}

ai f32 store_f32_f32(i32 ptr, f32 value)
{
  return *(f32 *)(mem + fix_ptr(ptr)) = value;
}

ai i32 i32_add(i32 a, i32 b) { return a + b; }
ai i32 i32_sub(i32 a, i32 b) { return a - b; }
ai i32 i32_and(i32 a, i32 b) { return a & b; }
ai i32 i32_xor(i32 a, i32 b) { return a ^ b; }
ai i32 i32_or (i32 a, i32 b) { return a | b; }
ai i32 i32_mul(i32 a, i32 b) { return a * b; }

ai i64 i64_add(i64 a, i64 b) { return a + b; }
ai i64 i64_sub(i64 a, i64 b) { return a - b; }
ai i64 i64_and(i64 a, i64 b) { return a & b; }
ai i64 i64_xor(i64 a, i64 b) { return a ^ b; }
ai i64 i64_or (i64 a, i64 b) { return a | b; }
ai i64 i64_mul(i64 a, i64 b) { return a * b; }

/* XXX negative */
ai i64 i64_div_s(i64 a, i64 b) { return a / b; }
ai i64 i64_div_u(i64 a, i64 b) { return (unsigned long)a/(unsigned long)b; }
ai i64 i64_rem_s(i64 a, i64 b) { return a % b; }
ai i64 i64_rem_u(i64 a, i64 b) { return (unsigned long)a%(unsigned long)b; }

/* XXX negative */
ai i32 i32_div_s(i32 a, i32 b) { return a / b; }
ai i32 i32_div_u(i32 a, i32 b) { return (unsigned)a/(unsigned)b; }
ai i32 i32_rem_s(i32 a, i32 b) { return a % b; }
ai i32 i32_rem_u(i32 a, i32 b) { return (unsigned)a%(unsigned)b; }

ai f64 f64_add(f64 a, f64 b) { return a + b; }
ai f64 f64_sub(f64 a, f64 b) { return a - b; }
ai f64 f64_mul(f64 a, f64 b) { return a * b; }
ai f64 f64_div(f64 a, f64 b) { return a / b; }

/* XXX NaN */
ai f64 f64_min(f64 a, f64 b) { return a < b ? a : b; }
ai f64 f64_max(f64 a, f64 b) { return a > b ? a : b; }
ai f64 f64_abs(f64 a) { return f64_max(a, -a); }
ai f64 f64_neg(f64 a) { return -a; }

ai f64 f64_sqrt(f64 a) { return sqrt(a); }

ai f32 f32_add(f32 a, f32 b) { return a + b; }
ai f32 f32_sub(f32 a, f32 b) { return a - b; }
ai f32 f32_mul(f32 a, f32 b) { return a * b; }
ai f32 f32_div(f32 a, f32 b) { return a / b; }

/* XXX NaN */
ai f32 f32_min(f32 a, f32 b) { return a < b ? a : b; }
ai f32 f32_max(f32 a, f32 b) { return a > b ? a : b; }
ai f32 f32_abs(f32 a) { return f32_max(a, -a); }
ai f32 f32_neg(f32 a) { return -a; }

ai f32 f32_sqrt(f32 a) { return sqrt(a); }

ai f64 f64_promote_f32(f32 a) { return a; }
ai f32 f32_demote_f64(f64 a) { return a; }

ai i32 i32_trunc_s_f32(f32 a) { return a; }
ai i32 i32_trunc_s_f64(f64 a) { return a; }
ai i32 i32_trunc_u_f32(f32 a) { return (unsigned)a; }
ai i32 i32_trunc_u_f64(f64 a) { return (unsigned)a; }
ai i64 i64_trunc_s_f32(f32 a) { return a; }
ai i64 i64_trunc_s_f64(f64 a) { return a; }
ai i64 i64_trunc_u_f32(f32 a) { return (unsigned long)a; }
ai i64 i64_trunc_u_f64(f64 a) { return (unsigned long)a; }

ai i64 i64_extend_s(i32 a) { return a; }
ai i64 i64_extend_u(i32 a) { return (unsigned)a; }

ai f32 f32_convert_s_i32(i32 a) { return a; }
ai f32 f32_convert_u_i32(i32 a) { return (unsigned)a; }
ai f32 f32_convert_s_i64(i64 a) { return a; }
ai f32 f32_convert_u_i64(i64 a) { return (unsigned long)a; }
ai f64 f64_convert_s_i32(i32 a) { return a; }
ai f64 f64_convert_u_i32(i32 a) { return (unsigned)a; }
ai f64 f64_convert_s_i64(i64 a) { return a; }
ai f64 f64_convert_u_i64(i64 a) { return (unsigned long)a; }

ai i32 i32_popcnt(i32 a) { return __builtin_popcount(a); }
ai i64 i64_popcnt(i64 a) { return __builtin_popcountl(a); }
/* XXX 0 */
ai i32 i32_clz(i32 a) { return __builtin_clz(a); }
ai i64 i64_clz(i64 a) { return __builtin_clzl(a); }
ai i32 i32_ctz(i32 a) { return __builtin_ctz(a); }
ai i64 i64_ctz(i64 a) { return __builtin_ctzl(a); }

ai i32 i32_eqz(i32 a) { return !a; }
ai i32 i64_eqz(i64 a) { return !a; }

ai f32 f32_trunc(f32 a) { return truncf(a); }
ai f64 f64_trunc(f64 a) { return trunc(a); }

ai f32 f32_ceil(f32 a) { return ceilf(a); }
ai f64 f64_ceil(f64 a) { return ceil(a); }

ai f32 f32_floor(f32 a) { return floorf(a); }
ai f64 f64_floor(f64 a) { return floor(a); }

ai f32 f32_nearest(f32 a) { return nearbyintf(a); }
ai f64 f64_nearest(f64 a) { return nearbyint(a); }

ai f32 f32_copysign(f32 a, f32 b) { return copysignf(a, b); }
ai f64 f64_copysign(f64 a, f64 b) { return copysign(a, b); }

long wasm_start[32] = {
     0, 0,
     1, 0,
     2, 0,
     3, 0,
     -1, 0,
     -1, 0,
     -1, 0,
     -1, 0
};

void* instance;
void* exports;
void* heap;
void* jscontext;

extern void start(void);
int main(void)
{
  /* instance = (void*)wasm_start[11]; */
  /* exports = (void*)wasm_start[9]; */
  /* heap = (void*)wasm_start[13]; */
  /* jscontext = (void*)wasm_start[15]; */

  mem = malloc(128 * 1024 * 1024);

  FILE *f;
  f = fopen("wasm.data", "r");

  if (!f)
    return 1;

  void *p = mem + 0x4040;
  size_t res;
  while (res = fread(p, 1, 4096, f))
    p += res;

  fclose(f);

  long pc = 195LL<<32LL;
  long sp = 2 * 1024 * 1024;
  long rpc = 0;
  long rp;

  while (pc != 0) {
    rp = _125(pc, sp, 0, 0, rpc, pc & 0xffffffff00000000UL);
    sp = rp;

    if (sp & 3) {
      sp &= -4L;
      pc = *(long *)(mem + sp + 16);
      pc |= 0xffffffffUL;
      sp += 16;
    } else {
      sp = *(long *)(mem + rp);
      pc = *(long *)(mem + sp + 16);
      pc |= 0xffffffffUL;
      sp += 16;
    }
  }

  return 0;
}

void extcall(void)
{
  long (*cbtn)(void *, void *, unsigned long, long, long, long, long);
  cbtn = exports;

  cbtn(jscontext, instance, 0, 0, 0, 0, 0);
}

i64 import_0(i64 x, i64 y, i64 z, i64 a)
{
  fprintf (stderr, "import_0\n");
  return 0;
}
i64 import_1(i64 x, i64 y, i64 z)
{
  fprintf (stderr, "import_1\n");
  return 0;
}
i64 import_3(i64 x)
{
  fprintf (stderr, "import_3\n");
  return 0;
}
i64 import$0(i64 x, i64 y, i64 z, i64 a)
{
  char *name = mem + y;
  fprintf (stderr, "import$0 %s\n", name);
  *(long *)(mem + 4096) = -1;

  if (strcmp(name, "write") == 0) {
    long count = *(long *)(mem + a + 0x20);
    long pointer = *(long *)(mem + a + 0x18);
    fwrite (mem + pointer, 1, count, stderr);
    *(long *)(mem + 4096) = count;
  } else if (strcmp(name, "exit") == 0) {
    long code = *(long *)(mem + a + 0x10);
    exit(code);
  }
  return 0;
}
i64 import$1(i64 fp, i64 sp, i64 handler)
{
  fprintf (stderr, "import$1 %lx %lx %lx\n", fp, sp, handler);
  *(long *)(mem + 4104) = *(long *)(mem + fp + 48);
  *(long *)(mem + 4112) = *(long *)(mem + fp + 56);
  *(long *)(mem + 4120) = *(long *)(mem + fp + 64);
  *(long *)(mem + 4128) = *(long *)(mem + fp + 72);

  fp = *(long *)(mem + fp);
  fp = *(long *)(mem + fp);

  *(long *)(mem + fp + 8) = handler & 0xffffffff00000000UL;
  *(long *)(mem + fp + 16) = handler;

  return fp|3;
}
i64 import$3(i64 x)
{
  fprintf (stderr, "import$3 %lx\n", x);
  return 0;
}
#if 0
/* i64 import_0(i64 x) */
/* { */
/*   sprintf((char *)mem + 12288 + 2048, "log"); */
/*   store_i64_i64(12288, 2); */
/*   store_i64_i64(12296, (int64_t)12288 + 2048); */
/*   store_i64_i64(12304, x); */
/*   extcall(); */
/*   return load_i64_i64_u(12288); */
/* } */

i64 import_2(i64 dpc, i64 sp, i64 r0, i64 r1, i64 rpc, i64 pc0);

i64 import_0(i64 a0, i64 a1, i64 a2, i64 a3)
{
  sprintf((char *)mem + 12288 + 2048, "extcall");
  store_i64_i64(12288, 5);
  store_i64_i64(12296, (int64_t)12288 + 2048);
  store_i64_i64(12304, a0);
  store_i64_i64(12312, a1);
  store_i64_i64(12320, a2);
  store_i64_i64(12328, a3);
  extcall();
  return load_i64_i64_u(12288);
}

i64 import_1(i64 x, i64 y, i64 z)
{
  fprintf(stderr, "mystery call: %lx\n", x);
}
#endif

i64 (*table[1024])(i64, i64, i64, i64, i64, i64) = {
[0] = _0,
[1] = _1,
[2] = _2,
[3] = _3,
[4] = _4,
[5] = _5,
[6] = _6,
[7] = _7,
[8] = _8,
[9] = _9,
[10] = _10,
[11] = _11,
[12] = _12,
[13] = _13,
[14] = _14,
[15] = _15,
[16] = _16,
[17] = _17,
[18] = _18,
[19] = _19,
[20] = _20,
[21] = _21,
[22] = _22,
[23] = _23,
[24] = _24,
[25] = _25,
[26] = _26,
[27] = _27,
[28] = _28,
[29] = _29,
[30] = _30,
[31] = _31,
[32] = _32,
[33] = _33,
[34] = _34,
[35] = _35,
[36] = _36,
[37] = _37,
[38] = _38,
[39] = _39,
[40] = _40,
[41] = _41,
[42] = _42,
[43] = _43,
[44] = _44,
[45] = _45,
[46] = _46,
[47] = _47,
[48] = _48,
[49] = _49,
[50] = _50,
[51] = _51,
[52] = _52,
[53] = _53,
[54] = _54,
[55] = _55,
[56] = _56,
[57] = _57,
[58] = _58,
[59] = _59,
[60] = _60,
[61] = _61,
[62] = _62,
[63] = _63,
[64] = _64,
[65] = _65,
[66] = _66,
[67] = _67,
[68] = _68,
[69] = _69,
[70] = _70,
[71] = _71,
[72] = _72,
[73] = _73,
[74] = _74,
[75] = _75,
[76] = _76,
[77] = _77,
[78] = _78,
[79] = _79,
[80] = _80,
[81] = _81,
[82] = _82,
[83] = _83,
[84] = _84,
[85] = _85,
[86] = _86,
[87] = _87,
[88] = _88,
[89] = _89,
[90] = _90,
[91] = _91,
[92] = _92,
[93] = _93,
[94] = _94,
[95] = _95,
[96] = _96,
[97] = _97,
[98] = _98,
[99] = _99,
[100] = _100,
[101] = _101,
[102] = _102,
[103] = _103,
[104] = _104,
[105] = _105,
[106] = _106,
[107] = _107,
[108] = _108,
[109] = _109,
[110] = _110,
[111] = _111,
[112] = _112,
[113] = _113,
[114] = _114,
[115] = _115,
[116] = _116,
[117] = _117,
[118] = _118,
[119] = _119,
[120] = _120,
[121] = _121,
[122] = _122,
[123] = _123,
[124] = _124,
[125] = _125,
[140] = _140,
[142] = _142,
[143] = _143,
[144] = _144,
[145] = _145,
[146] = _146,
[147] = _147,
[148] = _148,
[149] = _149,
[150] = _150,
[151] = _151,
[152] = _152,
[153] = _153,
[154] = _154,
[155] = _155,
[156] = _156,
[157] = _157,
[158] = _158,
[159] = _159,
[160] = _160,
[161] = _161,
[162] = _162,
[163] = _163,
[164] = _164,
[165] = _165,
[166] = _166,
[167] = _167,
[168] = _168,
[169] = _169,
[170] = _170,
[171] = _171,
[172] = _172,
[173] = _173,
[174] = _174,
[175] = _175,
[176] = _176,
[177] = _177,
[178] = _178,
[179] = _179,
[180] = _180,
[181] = _181,
[182] = _182,
[183] = _183,
[184] = _184,
[185] = _185,
[186] = _186,
[187] = _187,
[188] = _188,
[189] = _189,
[190] = _190,
[191] = _191,
[192] = _192,
[193] = _193,
[194] = _194,
[195] = _195,
[196] = _196,
[197] = _197,
[198] = _198,
[199] = _199,
[200] = _200,
[201] = _201,
[202] = _202,
[203] = _203,
[204] = _204,
[205] = _205,
[206] = _206,
[207] = _207,
[208] = _208,
[209] = _209,
[210] = _210,
[211] = _211,
[212] = _212,
[213] = _213,
[214] = _214,
[215] = _215,
[216] = _216,
[217] = _217,
[218] = _218,
[219] = _219,
[220] = _220,
[221] = _221,
[222] = _222,
[223] = _223,
[224] = _224,
[225] = _225,
[226] = _226,
[227] = _227,
[228] = _228,
[229] = _229,
[230] = _230,
[231] = _231,
[232] = _232,
[233] = _233,
[234] = _234,
[235] = _235,
[236] = _236,
[237] = _237,
[238] = _238,
[239] = _239,
[240] = _240,
[241] = _241,
[242] = _242,
[243] = _243,
[244] = _244,
[245] = _245,
[246] = _246,
[247] = _247,
[248] = _248,
[249] = _249,
[250] = _250,
[251] = _251,
[252] = _252,
[253] = _253,
[254] = _254,
[255] = _255,
[256] = _256,
[257] = _257,
[258] = _258,
[259] = _259,
[260] = _260,
[261] = _261,
[262] = _262,
[263] = _263,
[264] = _264,
[265] = _265,
[266] = _266,
[267] = _267,
[268] = _268,
[269] = _269,
[270] = _270,
[271] = _271,
[272] = _272,
[273] = _273,
[274] = _274,
[275] = _275,
[276] = _276,
[277] = _277,
[278] = _278,
[279] = _279,
[280] = _280,
[281] = _281,
[282] = _282,
[283] = _283,
[284] = _284,
[285] = _285,
[286] = _286,
[287] = _287,
[288] = _288,
[289] = _289,
[290] = _290,
[291] = _291,
[292] = _292,
[293] = _293,
[294] = _294,
[295] = _295,
[296] = _296,
[297] = _297,
[298] = _298,
[299] = _299,
[300] = _300,
[301] = _301,
[302] = _302,
[303] = _303,
[304] = _304,
[305] = _305,
[306] = _306,
[307] = _307,
[308] = _308,
[309] = _309,
[310] = _310,
[311] = _311,
[312] = _312,
[313] = _313,
[314] = _314,
[315] = _315,
[316] = _316,
[317] = _317,
[318] = _318,
[319] = _319,
[320] = _320,
[321] = _321,
[322] = _322,
[323] = _323,
[324] = _324,
[325] = _325,
[326] = _326,
[327] = _327,
[328] = _328,
[329] = _329,
[330] = _330,
[331] = _331,
[332] = _332,
[333] = _333,
[334] = _334,
[335] = _335,
[336] = _336,
[337] = _337,
[338] = _338,
[339] = _339,
[340] = _340,
[341] = _341,
[342] = _342,
[343] = _343,
[344] = _344,
[345] = _345,
[346] = _346,
[347] = _347,
[348] = _348,
[349] = _349,
[350] = _350,
[351] = _351,
[352] = _352,
[353] = _353,
[354] = _354,
[355] = _355,
[356] = _356,
[357] = _357,
[358] = _358,
[359] = _359,
[360] = _360,
[361] = _361,
[362] = _362,
[363] = _363,
[364] = _364,
[365] = _365,
[366] = _366,
[367] = _367,
[368] = _368,
[369] = _369,
[370] = _370,
[371] = _371,
[372] = _372,
[373] = _373,
[374] = _374,
[375] = _375,
[376] = _376,
[377] = _377,
[378] = _378,
[379] = _379,
[380] = _380,
[381] = _381,
[382] = _382,
[383] = _383,
[384] = _384,
[385] = _385,
[386] = _386,
[387] = _387,
[388] = _388,
[389] = _389,
[390] = _390,
[391] = _391,
[392] = _392,
[393] = _393,
[394] = _394,
[395] = _395,
[396] = _396,
[397] = _397,
[398] = _398,
[399] = _399,
[400] = _400,
[401] = _401,
[402] = _402,
[403] = _403,
[404] = _404,
[405] = _405,
[406] = _406,
[407] = _407,
[408] = _408,
[409] = _409,
[410] = _410,
[411] = _411,
[412] = _412,
[413] = _413,
[414] = _414,
[415] = _415,
[416] = _416,
[417] = _417,
[418] = _418,
[419] = _419,
[420] = _420,
[421] = _421,
[422] = _422,
[423] = _423,
[424] = _424,
[425] = _425,
[426] = _426,
[427] = _427,
[428] = _428,
[429] = _429,
[430] = _430,
[431] = _431,
[432] = _432,
[433] = _433,
[434] = _434,
[435] = _435,
[436] = _436,
[437] = _437,
[438] = _438,
[439] = _439,
[440] = _440,
[441] = _441,
[442] = _442,
[443] = _443,
[444] = _444,
[445] = _445,
[446] = _446,
[447] = _447,
[448] = _448,
[449] = _449,
[450] = _450,
[451] = _451,
[452] = _452,
[453] = _453,
[454] = _454,
[455] = _455,
[456] = _456,
[457] = _457,
[458] = _458,
[459] = _459,
[460] = _460,
[461] = _461,
[462] = _462,
[463] = _463,
[464] = _464,
[465] = _465,
[466] = _466,
[467] = _467,
[468] = _468,
[469] = _469,
[470] = _470,
[471] = _471,
[472] = _472,
[473] = _473,
[474] = _474,
[475] = _475,
[476] = _476,
[477] = _477,
[478] = _478,
[479] = _479,
[480] = _480,
[481] = _481,
[482] = _482,
[483] = _483,
[484] = _484,
[485] = _485,
[486] = _486,
[487] = _487,
[488] = _488,
[489] = _489,
[490] = _490,
[491] = _491,
[492] = _492,
[493] = _493,
[494] = _494,
[495] = _495,
[496] = _496,
[497] = _497,
[498] = _498,
[499] = _499,
[500] = _500,
[501] = _501,
[502] = _502,
[503] = _503,
[504] = _504,
[505] = _505,
[506] = _506,
[507] = _507,
[508] = _508,
[509] = _509,
[510] = _510,
[511] = _511,
[512] = _512,
[513] = _513,
[514] = _514,
[515] = _515,
[516] = _516,
[517] = _517,
[518] = _518,
[519] = _519,
[520] = _520,
[521] = _521,
[522] = _522,
[523] = _523,
[524] = _524,
[525] = _525,
[526] = _526,
[527] = _527,
[528] = _528,
[529] = _529,
[530] = _530,
[531] = _531,
[532] = _532,
[533] = _533,
[534] = _534,
[535] = _535,
[536] = _536,
[537] = _537,
[538] = _538,
[539] = _539,
[540] = _540,
[541] = _541,
[542] = _542,
[543] = _543,
[544] = _544,
[545] = _545,
[546] = _546,
[547] = _547,
[548] = _548,
[549] = _549,
[550] = _550,
[551] = _551,
[552] = _552,
[553] = _553,
[554] = _554,
[555] = _555,
[556] = _556,
[557] = _557,
[558] = _558,
[559] = _559,
[560] = _560,
[561] = _561,
[562] = _562,
[563] = _563,
[564] = _564,
[565] = _565,
[566] = _566,
[567] = _567,
[568] = _568,
[569] = _569,
[570] = _570,
[571] = _571,
[572] = _572,
[573] = _573,
[574] = _574,
[575] = _575,
[576] = _576,
[577] = _577,
[578] = _578,
[579] = _579,
[580] = _580,
[581] = _581,
[582] = _582,
[583] = _583,
[584] = _584,
[585] = _585,
[586] = _586,
[587] = _587,
[588] = _588,
[589] = _589,
[590] = _590,
[591] = _591,
[592] = _592,
[593] = _593,
[594] = _594,
[595] = _595,
[596] = _596,
[597] = _597,
[598] = _598,
[599] = _599,
[600] = _600,
[601] = _601,
[602] = _602,
[603] = _603,
[604] = _604,
[605] = _605,
[606] = _606,
[607] = _607,
[608] = _608,
[609] = _609,
[610] = _610,
[611] = _611,
[612] = _612,
[613] = _613,
[614] = _614,
[615] = _615,
[616] = _616,
[617] = _617,
[618] = _618,
[619] = _619,
[620] = _620,
[621] = _621,
[622] = _622,
[623] = _623,
[624] = _624,
[625] = _625,
[626] = _626,
[627] = _627,
[628] = _628,
[629] = _629,
[630] = _630,
[631] = _631,
[632] = _632,
[633] = _633,
[634] = _634,
[635] = _635,
[636] = _636,
[637] = _637,
[638] = _638,
[639] = _639,
[640] = _640,
[641] = _641,
[642] = _642,
[643] = _643,
[644] = _644,
[645] = _645,
[646] = _646,
[647] = _647,
[648] = _648,
[649] = _649,
[650] = _650,
[651] = _651,
[652] = _652,
[653] = _653,
[654] = _654,
[655] = _655,
[656] = _656,
[657] = _657,
[658] = _658,
[659] = _659,
[660] = _660,
[661] = _661,
[662] = _662,
[663] = _663,
[664] = _664,
[665] = _665,
[666] = _666,
[667] = _667,
[668] = _668,
[669] = _669,
[670] = _670,
[671] = _671,
[672] = _672,
[673] = _673,
[674] = _674,
[675] = _675,
[676] = _676,
[677] = _677,
[678] = _678,
[679] = _679,
[680] = _680,
[681] = _681,
[682] = _682,
[683] = _683,
[684] = _684,
[685] = _685,
[686] = _686,
[687] = _687,
[688] = _688,
[689] = _689,
[690] = _690,
[691] = _691,
[692] = _692,
[693] = _693,
[694] = _694,
[695] = _695,
[696] = _696,
[697] = _697,
[698] = _698,
[699] = _699,
[700] = _700,
[701] = _701,
[702] = _702,
[703] = _703,
[704] = _704,
[705] = _705,
[706] = _706,
[707] = _707,
[708] = _708,
[709] = _709,
[710] = _710,
[711] = _711,
[712] = _712,
[713] = _713,
[714] = _714,
[715] = _715,
[716] = _716,
[717] = _717,
[718] = _718,
[719] = _719,
[720] = _720,
[721] = _721,
[722] = _722,
[723] = _723,
[724] = _724,
[725] = _725,
[726] = _726,
[727] = _727,
[728] = _728,
[729] = _729,
[730] = _730,
[731] = _731,
[732] = _732,
[733] = _733,
[734] = _734,
[735] = _735,
[736] = _736,
[737] = _737,
[738] = _738,
[739] = _739,
[740] = _740,
[741] = _741,
[742] = _742,
[743] = _743,
[744] = _744,
[745] = _745,
[746] = _746,
[747] = _747,
[748] = _748,
[749] = _749,
[750] = _750,
[751] = _751,
[752] = _752,
[753] = _753,
[754] = _754,
[755] = _755,
[756] = _756,
[757] = _757,
[758] = _758,
[759] = _759,
[760] = _760,
[761] = _761,
[762] = _762,
[763] = _763,
[764] = _764,
[765] = _765,
[766] = _766,
[767] = _767,
[768] = _768,
[769] = _769,
[770] = _770,
[771] = _771,
[772] = _772,
[773] = _773,
[774] = _774,
[775] = _775,
[776] = _776,
[777] = _777,
[778] = _778,
[779] = _779,
[780] = _780,
[781] = _781,
[782] = _782,
[783] = _783,
[784] = _784,
[785] = _785,
[786] = _786,
[787] = _787,
[788] = _788,
[789] = _789,
[790] = _790,
[791] = _791,
[792] = _792,
[793] = _793,
[794] = _794,
[795] = _795,
[796] = _796,
[797] = _797,
[798] = _798,
[799] = _799,
[800] = _800,
[801] = _801,
[802] = _802,
[803] = _803,
[804] = _804,
[805] = _805,
[806] = _806,
[807] = _807,
[808] = _808,
[809] = _809,
[810] = _810,
[811] = _811,
[812] = _812,
[813] = _813,
[814] = _814,
[815] = _815,
[816] = _816,
[817] = _817,
[818] = _818,
[819] = _819,
[820] = _820,
[821] = _821,
[822] = _822,
[823] = _823,
[824] = _824,
[825] = _825,
[826] = _826,
[827] = _827,
[828] = _828,
[829] = _829,
[830] = _830,
[831] = _831,
[832] = _832,
[833] = _833,
[834] = _834,
[835] = _835,
[836] = _836,
[837] = _837,
[838] = _838,
[839] = _839,
[840] = _840,
[841] = _841,
[842] = _842,
[843] = _843,
[844] = _844,
[845] = _845,
[846] = _846,
[847] = _847,
[848] = _848,
[849] = _849,
[850] = _850,
[851] = _851,
[852] = _852,
[853] = _853,
[854] = _854,
[855] = _855,
[856] = _856,
[857] = _857,
[858] = _858,
[859] = _859,
[860] = _860,
[861] = _861,
[862] = _862,
[863] = _863,
[864] = _864,
[865] = _865,
[866] = _866,
[867] = _867,
[868] = _868,
[869] = _869,
[870] = _870,
[871] = _871,
[872] = _872,
[873] = _873,
[874] = _874,
[875] = _875,
[876] = _876,
[877] = _877,
[878] = _878,
[879] = _879,
[880] = _880,
[881] = _881,
[882] = _882,
[883] = _883,
[884] = _884,
[885] = _885,
[886] = _886,
[887] = _887,
[888] = _888,
[889] = _889,
[890] = _890,
[891] = _891,
[892] = _892,
[893] = _893,
[894] = _894,
[895] = _895,
[896] = _896,
[897] = _897,
[898] = _898,
[899] = _899,
[900] = _900,
[901] = _901,
[902] = _902,
[903] = _903,
[904] = _904,
[905] = _905,
[906] = _906,
[907] = _907,
[908] = _908,
[909] = _909,
[910] = _910,
[911] = _911,
[912] = _912,
[913] = _913,
[914] = _914,
[915] = _915,
[916] = _916,
[917] = _917,
[918] = _918,
[919] = _919,
[920] = _920,
[921] = _921,
[922] = _922,
[923] = _923,
[924] = _924,
[925] = _925,
[926] = _926,
[927] = _927,
[928] = _928,
[929] = _929,
[930] = _930,
[931] = _931,
[932] = _932,
[933] = _933,
[934] = _934,
[935] = _935,
[936] = _936,
};
