#include "../../common.hpp"
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst

#define MOD ((int)1e9 + 7)

const int inv[] = {
    1,         1,         500000004, 333333336, 0xee6b282, 400000003,
    0x9ef21ac, 0x883d3b8, 0x7735941, 0x69f6bc8, 700000005, 818181824,
    83333334,  0x92b818b, 71428572,  466666670, 562500004, 352941179,
    55555556,  0x9694852, 850000006, 47619048,  409090912, 739130440,
    41666667,  280000002, 576923081, 370370373, 35714286,  758620695,
    0xde86257, 0x7b0e043, 281250002, 939393946, 676470593, 628571433,
    27777778,  621621626, 78947369,  717948723, 425000003, 658536590,
    23809524,  395348840, 0xc311db0, 822222228, 369565220, 404255322,
    520833337, 448979595, 0x8583b01, 784313731, 788461544, 56603774,
    685185190, 763636369, 17857143,  385964915, 879310351, 50847458,
    616666671, 688524595, 564516133, 0xf233f8,  0x861c469, 30769231,
    469696973, 686567169, 838235300, 579710149, 814285720, 98591550,
    0xd3ed79,  410958907, 310810813, 93333334,  539473688, 831168837,
    858974365, 0xc12633f, 712500005, 0x75bcd17, 329268295, 84337350,
    0xb5a6fa,  670588240, 0xbc845b4, 0xf128b5d, 0x6188ed8, 415730340,
    411111114, 0x9d32f5e, 0xb038f12, 43010753,  0xc0c392d, 0xdcd9d45,
    760416672, 0xff9fc17, 724489801, 646464651, 570000004, 940594066,
    892156869, 572815538, 394230772, 0xc7d1463, 28301887,  0xd5e883b,
    342592595, 9174312,   881818188, 873873880, 508928575, 893805316,
    692982461, 0x8cfa5a8, 939655179, 0xe43ad11, 25423729,  478991600,
    808333339, 438016532, 844262301, 886178868, 782258070, 856000006,
    7936508,   480314964, 570312504, 798449618, 515384619, 0xb5ffb90,
    734848490, 0x9dc029f, 843283588, 274074076, 419117650, 58394161,
    789855078, 604316551, 407142860, 0x808261e, 49295775,  832167838,
    506944448, 0x90b206b, 705479457, 0x8eba0d9, 655405410, 530201346,
    46666667,  483443712, 269736844, 594771246, 915584422, 625806456,
    929487186, 343949047, 601265827, 685534596, 856250006, 962732926,
    561728399, 0x6f2a1c2, 664634151, 587878792, 42168675,  5988024,
    5952381,   0xe75d620, 335294120, 795321643, 98837210,  791907520,
    626436786, 325714288, 51136364,  683615824, 0xc63c552, 435754193,
    0xc408765, 933701664, 82417583,  562841534, 92391305,  524324328,
    521505380, 577540111, 601063834, 338624341, 615789478, 439790579,
    380208336, 694300523, 634020623, 343589746, 862244904, 969543154,
    823232329, 507537692, 285000002, 0xda40fab, 470297033, 0x675a971,
    946078438, 0x7d9b1b6, 286407769, 526570052, 0xbbfbdfa, 832535891,
    604761909, 90047394,  514150947, 32863850,  612149537, 79069768,
    671296301, 875576043, 4587156,   470319638, 440909094, 950226251,
    436936940, 0x77be6db, 754464291, 364444447, 446902658, 35242291,
    846491234, 711790398, 73913044,  277056279, 969827593, 90128756,
    619658124, 880851070, 512711868, 67510549,  0xe466a78, 280334730,
    904166673, 406639007, 0xd0dcd0a, 707818935, 922131154, 89795919,
    443089434, 0x9e4d5e0, 391129035, 28112450,  428000003, 912350604,
    3968254,   339920951, 0xe50832a, 556862749, 285156252, 70038911,
    399224809, 517374521, 757692313, 417624524, 95419848,  836501907,
    367424245, 611320759, 582706771, 0x842838c, 421641794, 743494429,
    0x82b04ee, 450184505, 0xc7d9d29, 388278391, 529197084, 752727278,
    394927539, 0xf1002ff, 802158279, 681003589, 0xc2240e6, 718861215,
    67375887,  650176683, 524647891, 77192983,  416083919, 808362375,
    0xf1bade0, 961937723, 575862073, 756013751, 852739732, 522184304,
    574829936, 0xc86ee95, 327702705, 0xcd816d9, 0xfcd1d81, 441471575,
    523333337, 770764125, 0xe686200, 646864691, 0x809edc6, 0x83535d7,
    297385623, 749185673, 457792211, 857605184, 312903228, 787781356,
    464743593, 492012783, 671974527, 403174606, 800632917, 652996850,
    342767298, 614420067, 428125003, 741433027, 481366463, 597523224,
    780864203, 406153849, 58282209,  3058104,   832317079, 343465048,
    293939396, 631419944, 521084341, 624624629, 2994012,   737313438,
    502976194, 41543027,  0x73aeb10, 631268441, 0x9fe1754, 284457480,
    897660825, 0xc56865e, 49418605,  715942034, 395953760, 985590785,
    313218393, 521489975, 0x9b500b8, 413105416, 25568182,  0xa780393,
    341807912, 19718310,  0x631e2a9, 826330538, 717877100, 713091927,
    602777782, 0x6c4fe20, 466850832, 812672182, 541208795, 882191787,
    281420767, 376021801, 546195656, 295392956, 0xfa046f4, 436657685,
    0xf8ac532, 0xf5731f,  788770059, 618666671, 300531917, 0xca5f079,
    669312174, 0xba349e5, 307894739, 0x98b021c, 719895293, 0xa4573b1,
    0xb54c268, 966233773, 847150265, 932816544, 817010315, 951156819,
    0xa3d61b9, 0x619005f, 431122452, 63613232,  484771577, 840506335,
    911616168, 760705295, 0xf20348e, 55137845,  0x87e60a1, 855361602,
    614427865, 779156333, 735148520, 424691361, 554187196, 0xe349d98,
    473039219, 0xb38ae7c, 65853659,  352798056, 643203888, 578692498,
    0xfb16922, 16867470,  98557693,  534772186, 916267949, 844868741,
    802380958, 966745850, 45023697,  44917258,  757075477, 0x7fe7910,
    0xfabb35,  526932088, 806074772, 610722615, 39534884,  761020887,
    835648154, 614318711, 937788025, 50574713,  2293578,   354691078,
    0xe04410b, 642369025, 0xd23de93, 716553293, 975113129, 88036118,
    0xd059076, 83146068,  562780273, 0xa88be56, 877232149, 285077953,
    682222227, 605321512, 0xd5198c1, 0x99aec00, 517621149, 432967036,
    423245617, 0xa4dbbda, 355895199, 0xbd129ba, 36956522,  321041217,
    638528143, 820734347, 984913800, 0xc6f0428, 45064378,  775160605,
    309829062, 0xe5c6cb8, 440425535, 447983018, 0xf47ae5e, 763213536,
    533755278, 646315794, 0x723353c, 0xd9ecf2c, 0x85ac8c5, 0xc51b20a,
    952083340, 355509358, 703319507, 654244311, 0x686e685, 653608252,
    853909471, 607802879, 461065577, 38854806,  544897963, 641547866,
    0xd34810d, 632860045, 82995952,  529292933, 695564521, 0x95abd53,
    0xd67b21,  0xfe2f8cc, 714000005, 1996008,   456175302, 282306165,
    1984127,   588118816, 669960479, 747534522, 0x7284195, 491159139,
    778431378, 344422703, 0x87f91ce, 598440550, 535019459, 314563109,
    699612408, 400386850, 758687264, 597302509, 878846160, 0xb70c015,
    0xc7238e6, 921606125, 47709924,  441904765, 918250957, 301707782,
    683712126, 510396979, 805660383, 561205277, 791353389, 589118203,
    69288390,  844859819, 0xc90df21, 811918069, 871747218, 404452693,
    68518519,  60998152,  725092256, 311233888, 604779416, 801834868,
    694139199, 541133459, 0xfc5740e, 854280516, 376363639, 39927405,
    697463773, 457504524, 626353795, 0xa6ad9f8, 901079143, 457809698,
    840501798, 491949914, 0x6112073, 525846706, 859430611, 433392543,
    533687947, 578761066, 825088345, 446208116, 762323949, 732864680,
    538596495, 334500878, 708041963, 813263531, 904181191, 0xdaee323,
    0x78dd6f0, 771230508, 980968865, 898100179, 787931040, 869191056,
    878006879, 732418530, 426369866, 447863251, 0xf8ff338, 724020448,
    287414968, 585738544, 605084750, 656514387, 663851356, 0x98c7e7a,
    607744112, 95798320,  632550340, 835845902, 720735791, 410684477,
    761666672, 296173047, 885382066, 76285241,  0x7343100, 887603312,
    823432349, 729818786, 67434211,  36124795,  568852463, 492635028,
    648692815, 696574230, 874592840, 377235775, 728896109, 716369535,
    428802592, 953150249, 0x953431e, 842190022, 393890678, 630818624,
    732371800, 571200004, 746006395, 944178635, 835987267, 36565978,
    0xc03fa67, 438985740, 900316462, 30015798,  326498425, 696062997,
    0xa371b61, 880690744, 807210037, 677621288, 714062505, 720748835,
    870716517, 43545879,  740683235, 359689925, 298761612, 0x717f604,
    890432105, 640986137, 703076928, 291858681, 529141108, 29096478,
    1529052,   438167942, 916158543, 823439884, 0xa3c6e2c, 698027319,
    0x8c29462, 0xce511c2, 315709972, 983408755, 760542174, 33082707,
    812312318, 0x9bd90b4, 1497006,   41853513,  368656719, 62593145,
    0xefd6761, 493313525, 520771517, 454814818, 60650888,  320531760,
    815634224, 609720181, 83823530,  345080766, 0x87a3d04, 530014645,
    948830416, 411678835, 0x62b432f, 0xe245a6a, 524709306, 927431066,
    357971017, 444283650, 0xbcce330, 92352093,  992795396, 520863313,
    656609200, 862266864, 760744991, 696709590, 81428572,  489301002,
    0xc4fbe84, 85348507,  0xc311db,  626950359, 587818701, 991513444,
    0xa2fc994, 385049368, 9859155,   355836852, 551966296, 701262277,
    413165269, 366433569, 358938550, 93444910,  856545967, 318497916,
    301388891, 0xd64773f, 56786704,  802213007, 0xde9ca08, 630344832,
    406336091, 696011009, 770604401, 0xe10273d, 941095897, 729138172,
    640710387, 66848568,  688010904, 29931973,  273097828, 698778838,
    0x8cdab5e, 538565633, 0x7d0237a, 721997306, 718328846, 590847918,
    0x7c56299, 506040272, 508042899, 676037488, 894385033, 889185587,
    809333339, 0xcdb8281, 650265962, 304116868, 606100800, 896688748,
    334656087, 952443864, 597625334, 779973655, 653947373, 582128782,
    80052494,  1310616,   859947650, 518954252, 586161884, 850065195,
    95052084,  855656703, 983116890, 690012975, 923575136, 648124196,
    466408272, 525161294, 908505161, 839124845, 975578413, 613607193,
    585897440, 645326509, 551150899, 805874846, 0xcd9340a, 868789815,
    31806616,  419313853, 742385792, 278833969, 920253171, 841972193,
    455808084, 822194205, 880352651, 537106922, 0x7901a47, 877038902,
    527568926, 964956202, 571250004, 46192260,  427680801, 764632633,
    807213936, 592546588, 889578170, 581164812, 367574260, 0x61d7cd6,
    712345684, 755856972, 277093598, 816728173, 0x71a4ecc, 0xd4f7bf5,
    736519613, 73439413,  94132030,  462759466, 532926833, 618757617,
    0xa83a2b4, 52247874,  321601944, 917575764, 289346249, 617896014,
    0x7d8b491, 712907122, 8433735,   84235861,  549278850, 496998803,
    0xfeffced, 601197609, 958133978, 560334532, 922434374, 696066751,
    401190479, 853745547, 483372925, 0xe485135, 522511852, 848520716,
    22458629,  348288078, 878537742, 0xceaf839, 67058824,  722679206,
    508215966, 690504108, 0xfb42c3c, 359064330, 403037386, 792298722,
    805361311, 67520373,  19767442,  269454125, 880510447, 718424107,
    417824077, 0x970b5c0, 807159359, 987312579, 968894016, 0xbef4507,
    525287360, 360505169, 1146789,   918671255, 0xa921403, 0xfcdc24b,
    617579913, 891676175, 821184516, 840728106, 610227277, 759364364,
    858276650, 612684036, 987556568, 736723169, 44018059,  559188279,
    0x682c83b, 497187855, 41573034,  738496077, 781390140, 705487127,
    88366891,  287150840, 938616078, 813823863, 642538980, 314794218,
    841111117, 591564932, 302660756, 0xf504f1f, 611725668, 786740337,
    80573952,  324145537, 758810578, 882288235, 0xce746be, 963776077,
    711622812, 371303398, 86433261,  712568311, 677947603, 741548533,
    99128541,  41349293,  18478261,  916395229, 660520612, 776814740,
    819264075, 304864867, 910367177, 952535066, 492456900, 0xf13ddae,
    0x6378214, 23630505,  22532189,  595927121, 887580306, 515508025,
    0x93bcee3, 0xf4455a,  0x72e365c, 0x9c681a5, 720212771, 568544106,
    0xd59d6d5, 0x6e3bdc4, 0x7a3d72f, 467724871, 381606768, 551214365,
    0xfe83ac7, 0xfa39f90, 323157897, 884332288, 59873950,  383001052,
    0x6cf6796, 687958120, 570083686, 0xc351a21, 0x628d905, 8342023,
    476041670, 746097820, 0xa985237, 580477678, 851659757, 338860106,
    827122159, 0xf886ff3, 554752070, 0xbdf2908, 326804126, 669412981,
    926954739, 943473799, 803901443, 468717952, 730532792, 584442174,
    19427403,  492339125, 772448985, 0xf8de8,   320773933, 399796544,
    610772362, 793908635, 816430026, 447821685, 41497976,  17189080,
    764646470, 0xa48f312, 847782264, 877139986, 578470829, 901507544,
    507028116, 911735212, 0x7f17c66, 874874881, 857000006};

// A hash function used to hash a pair of any kind
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2> &p) const {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);
    return hash1 != hash2 ? hash1 ^ hash2 : hash1;
  }
};

struct Solution {
  std::unordered_map<std::pair<int, int>, int, hash_pair> ctable;
  using VectorIt = std::vector<int>::iterator;

  int comb(int total, int n) {
    n = std::min(n, total - n);
    if (n == 0)
      return 1;
    auto [it, inserted] = ctable.emplace(std::make_pair(total, n), -1);

    if (!inserted)
      return it->second;

    int64_t r{1};
    int i{};
    while (i < n) {
      r = r * total-- % MOD;
      r = r * inv[++i] % MOD;
    }
    return it->second = (int)r;
  }

  int calc(VectorIt beg, VectorIt end) {
    int len = end - beg;
    if (len <= 2)
      return 1;
    int pivot = *beg++;
    VectorIt mid =
        std::stable_partition(beg, end, [=](int v) { return v < pivot; });
    int n_left{calc(beg, mid)}, n_right{calc(mid, end)},
        cnr{comb(len - 1, mid - beg)};
    return (int64_t)n_left * n_right % MOD * cnr % MOD;
  }

  int numOfWays(vector<int> &nums) {
    return calc(nums.begin(), nums.end()) - 1;
  }
};

int main() {
  std::vector<int> v{3, 1, 2, 5, 4, 6};
  int n{Solution().numOfWays(v)};
  DEBUG(n);
}
