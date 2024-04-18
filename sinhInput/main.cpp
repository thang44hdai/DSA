#include <bits/stdc++.h>
#include <random>
#define fi first
#define se second
using namespace std;

random_device rd;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// sinh 1 so nguyen bat ki trong doan [l, r].
long long CreLL(long long l, long long r)
{
    return rng() % (r - l + 1) + l;
}

string s = "qwertyuiopasdfghjklzxcvbnm1234567890 ,./;!@#$%^&*()_+ ";
string as[15] = {"abcba", "abccba", "aba", "acbca", "abcdedcba", "abba", "aaaaa", "non", "abababa", "acacaca", "youoy", "ToT", "bob", "tototot", "abcacba"};
string arrString[500] = {"gYntv", "WEGVg", "kMREa", "fBhfX", "EWbsB", "VZivM", "CPLLO", "MGgln", "cxVXa", "MlaSs", "JgIQS", "rDUUY", "DfStS", "WYgKA", "BHqqU", "VsrVj", "fKtAo", "fAGdc", "zDBcW", "mdnif", "BXvqO", "Pywwb", "dAhfg", "btZHV", "HxSDR", "WKaNL", "vAQBz", "vabUj", "Kique", "KeqAo", "lGInV", "PoBUz", "fYlUy", "YGwZg", "eCgWX", "nAHUU", "hYCAp", "ahUKX", "iLVID", "sDWmI", "PXqgH", "CdRYi", "YIzJe", "TkvMY", "Qirfz", "dyhQj", "OIGTI", "jWYtw", "owQqT", "aMdHC", "VyZbZ", "JkOVi", "DoHXV", "blFEV", "pORIw", "Ooyef", "IaejA", "vpytd", "Ltgtq", "ETjEW", "mkSgs", "NrhDA", "GOhaC", "gcdge", "uISbe", "NKbKY", "OZFUf", "aAqMS", "haiIP", "tlKZo", "ZyKmw", "mbats", "mjpgZ", "udIdF", "sOCKJ", "EBrwC", "RBXzm", "LGCrN", "GOUAR", "xPfWb", "raCcF", "hYfLu", "NulNg", "YQEmg", "YWVeZ", "wKfBP", "lrtPT", "jVHBV", "XTrHa", "rffAK", "QzoJM", "YDBpV", "NmEEQ", "ycOrb", "QhydP", "yHFAh", "KZFks", "QBvln", "mgUto", "vUIyx", "iODWD", "mlCRz", "pOqyH", "Pdzqg", "oWspz", "GLvZv", "rNLhq", "ajeWp", "pgkrU", "Vzicr", "Iydpl", "LqGWp", "GjnTu", "lsyyp", "Nhklv", "bcxIx", "eCQnd", "ZKsBg", "Wlusv", "tZeOV", "HeCsd", "YXcbq", "SnDSM", "SitOk", "sWPeF", "EGbAB", "axpQi", "hfEAb", "LMCuW", "Fqqaq", "ctBZj", "BtOTi", "JfLXN", "RTuSh", "nAqes", "AaOPB", "qHQNX", "Wbkbg", "vFleA", "VoEMt", "GTymm", "EOgbl", "rJEdT", "VAwLJ", "UqrKO", "pDZab", "joUNs", "zgZuW", "OpKay", "FUlZS", "tLFVn", "adXNG", "RpNUQ", "BIliy", "EMiGS", "uWuBd", "MosuC", "vAQAL", "hlSQq", "xznDm", "zVaQU", "ArxDH", "QpgcE", "yZIvH", "XJVqH", "nDFCB", "TzCvZ", "BOINT", "ONtXz", "qXiAj", "imvLp", "PyrJL", "VWsVG", "HidUO", "cKpVz", "fjSWz", "vYGwb", "bGcfK", "ipkLv", "eCESH", "kCFbz", "RQqFu", "zlgVz", "pCfTU", "zbjsk", "sHquv", "qKjwG", "tzCEd", "gDHDn", "efjHA", "zSfjd", "TSBrp", "wnsDm", "nPOnL", "kiFdr", "qkHiS", "gawfb", "mYPgg", "BCVRK", "QjGNp", "mniGC", "VrvxE", "YkJTV", "cWbyG", "cqNIT", "fVgHk", "rICfW", "VEBws", "IJDFX", "iNgMw", "MTlkP", "JbaoF", "iKbxt", "alSFU", "zKIIs", "WnvXY", "jULZC", "Hxajj", "aqnxo", "vLXTa", "hPLhy", "ZnIFS", "NrkIa", "QNAkf", "atenR", "USjbZ", "CDpNc", "BMqiU", "KirPP", "eRWKL", "gpeOG", "gxIMT", "fcrOF", "OWpsJ", "DIoGj", "HTIEO", "ttdcm", "GOeHM", "kfoFa", "VQuEd", "DyGbL", "JNuJu", "VMgEB", "zmxxD", "jkrCw", "FdiIX", "JOGTs", "MgYny", "wWIZd", "rGeQh", "TaSLh", "hYkAe", "gMYHo", "YZyRy", "nWMPv", "tlDQh", "mGWVP", "RzdOS", "iSCgh", "YYJzm", "PVmar", "GPkEF", "dKBkz", "jxJpY", "olyvo", "jNlTv", "myAmA", "jylEC", "JqZMA", "GijPw", "YylDG", "ppwXf", "gpJVw", "cgCDs", "ovJei", "uRFUJ", "itunp", "BXkDx", "Frtyk", "LMdtm", "pshis", "IXPWn", "feWmN", "rlPyL", "mgHKF", "AZsZK", "aawZk", "bUIDt", "qnhAB", "pLpLW", "WRfMx", "DxaRm", "kmvdT", "sIzlN", "yeaxf", "azmXa", "OmSfO", "zRWmT", "wLknV", "RhdsS", "MGcEn", "MJjOE", "ISWcU", "tcmff", "OZBla", "LcPhw", "xpiMX", "dsyye", "zjvWr", "dSqqv", "uKpxs", "yrrRV", "GLbzS", "FejON", "eJYsx", "KSeki", "XOWko", "WiStO", "xAcwZ", "GACWH", "qtCmy", "xKPVc", "chpco", "mBWTS", "RgLSi", "aNTqn", "PiDRk", "PxpMk", "gwKIq", "tGtiq", "qKiVM", "yJNdQ", "RoqLs", "EabUq", "qGFQi", "deVig", "hjluc", "JtZko", "ChxME", "cwEPB", "uKlLw", "aMIfq", "qTwZP", "hsmru", "pLWpr", "xYtVW", "weNiI", "DHvAB", "QUCbE", "EDaVP", "ydcjc", "RNqSR", "sgdJq", "MIKAG", "wKEUQ", "EHpwP", "KJWtN", "VSohD", "LgPmz", "VWccm", "NgYrd", "MWjIo", "IApSd", "ioerY", "JveKX", "xQeAy", "oWuyQ", "IOvsj", "orwZj", "vNjsy", "mSTYO", "GZiAf", "OMzHy", "ATDjv", "NHakm", "bVnSU", "uFbXY", "ISnhm", "pLUTK", "wblqW", "WIxXG", "yQdfA", "jyZVd", "IJZYQ", "PSeaV", "NkefP", "LdLtp", "CZZLJ", "HIVwv", "dRrBc", "FqqMP", "zFSVJ", "plGqf", "Tofvu", "mrUpH", "yPmSz", "jdzzb", "LeZkm", "lUzhC", "rNStx", "axwEa", "QlKow", "iOYDi", "UEQNT", "nKiwV", "IFZVi", "hibyt", "cOHrU", "eLtOb", "IhMls", "MTRMe", "QRaFq", "RyBUW", "WagED", "XVDEV", "Jfljn", "hgWpg", "VfKXJ", "hoodV", "qtFvF", "TWRvT", "OMpLG", "ITDjE", "seziU", "XRmWp", "VCqMb", "Ismur", "sFPlh", "mMynM", "frDfP", "kIQnP", "cfYLt", "qigFQ", "fGfUr", "UojGb", "vCdXI", "pMlNG", "ojgjy", "cpymX", "cfJon", "ASAZv", "nHzXE", "UjFMg", "LrkUu", "SUxwb", "KFSZZ", "ShJcX", "vNWae", "aUSuU", "RQvdM", "WADhv", "hTeCG", "gTQwZ", "Faexp", "duWDX", "IDmKl", "Yhckv", "xJPyG", "rsDWZ", "lBjYZ", "XfBYH", "rZtub", "GcCVq", "gkkEO", "mAYQi", "TWZzI", "BsgIF", "iUuaJ", "SEmaB", "voMKj", "wDcAp", "kqJjJ", "qlzUB", "cuDUm", "QjadP", "jcUEd", "MEpJS", "qADKF", "DdigA", "nIkIe", "arLGY", "aYpZY", "duUuf", "vKsRX", "gLJbL", "iHatX", "sTgNw", "IUygW", "BvKpG", "HjXbn", "oXUmM", "PIoBd", "soXkR", "cmFoB", "slZPZ", "BzpDR", "HWCRN", "JxtvA", "wSuRJ", "AqrAf"};
// int len = s.size() - 1;
int a[] = {1999999973, 1999999943, 1999999927, 1999999913, 1999999873, 1999999871, 1999999861, 1999999853, 1999999829, 1999999817, 1999999811, 1999999777, 1999999763, 1999999747, 1999999657, 1999999649, 1999999643, 1999999621, 1999999613, 1999999609, 1999999571, 1999999559, 1999999553, 1999999499, 1999999439, 1999999423, 1999999373, 1999999321, 1999999271, 1999999219, 1999999207, 1999999171, 1999999151, 1999999121, 1999999117, 1999999097, 1999999093, 1999999087, 1999999081, 1999999061, 1999999049, 1999999013, 1999999003, 1999998961, 1999998947, 1999998941, 1999998907, 1999998899, 1999998893, 1999998857, 1999998827, 1999998823, 1999998809, 1999998799, 1999998797, 1999998773, 1999998769, 1999998761, 1999998743, 1999998733, 1999998719, 1999998701, 1999998641, 1999998631, 1999998617, 1999998551, 1999998527, 1999998493, 1999998479, 1999998457, 1999998443, 1999998421, 1999998401, 1999998389, 1999998383, 1999998359, 1999998347, 1999998313, 1999998239, 1999998193, 1999998181, 1999998149, 1999998103, 1999998047, 1999998029, 1999997981, 1999997971, 1999997957, 1999997941, 1999997903, 1999997887, 1999997873, 1999997849, 1999997807, 1999997777, 1999997773, 1999997719, 1999997711, 1999997689, 1999997663, 1999997641};

int thuanNguyenTo[100] = {777777773, 777777577, 777777227, 777775577, 777775553, 777775373, 777775333, 777773753, 777773333, 777755753, 777753773, 777753377, 777752237, 777737533, 777737353, 777737333, 777735733, 777735557, 777735373, 777733757, 777733573, 777733373, 777732727, 777732523, 777732253, 777727277, 777727273, 777725527, 777723253, 777722557, 777722537, 777722357, 777722353, 777577733, 777577373, 777575353, 777575333, 777573737, 777573553, 777573373, 777557533, 777557353, 777555553, 777555223, 777553373, 777553223, 777552277, 777537737, 777537557, 777537533, 777537373, 777537337, 777535757, 777535373, 777535333, 777533357, 777532277, 777532237, 777527273, 777525523, 777525257, 777525233, 777523723, 777522533, 777377357, 777375733, 777375373, 777373537, 777373357, 777372727, 777357733, 777357353, 777357337, 777357223, 777353377, 777352327, 777352273, 777337357, 777337333, 777335777, 777335737, 777333373, 777332527, 777332323, 777332233, 777325727, 777325723, 777325327, 777323257, 777322373, 777277253, 777275327, 777275273, 777273727, 777272533, 777272227, 777255527, 777255257, 777255233, 777253727};

int thuanNguyenToNho[100] = {777277, 775273, 775237, 773723, 773273, 772573, 772537, 772333, 757327, 755273, 755257, 755233, 753527, 753257, 737327, 733277, 733273, 733237, 732533, 732373, 727777, 727733, 725737, 725537, 725357, 723553, 723353, 723337, 723227, 722723, 722273, 722257, 722237, 577523, 577327, 575723, 575257, 573527, 573523, 573277, 573253, 572573, 572357, 572333, 557273, 555523, 555277, 555257, 555253, 553727, 553277, 553253, 552757, 552553, 552353, 537527, 537233, 535727, 535523, 535273, 535237, 533723, 533327, 533257, 533237, 532757, 532733, 532537, 532373, 532333, 527753, 527557, 527533, 527377, 527353, 527333, 525773, 525533, 525377, 525373, 525353, 523777, 523577, 523573, 523553, 523357, 523333, 522523, 522323, 522233, 377527, 377327, 377257, 375527, 375523, 375257, 375253, 375233, 373327, 373273};

int nguyenToNho[100] = {999983, 999979, 999961, 999959, 999953, 999931, 999917, 999907, 999883, 999863, 999853, 999809, 999773, 999769, 999763, 999749, 999727, 999721, 999683, 999671, 999667, 999653, 999631, 999623, 999613, 999611, 999599, 999563, 999553, 999541, 999529, 999521, 999499, 999491, 999451, 999437, 999433, 999431, 999389, 999377, 999371, 999359, 999331, 999329, 999307, 999287, 999269, 999239, 999233, 999221, 999217, 999199, 999181, 999169, 999149, 999133, 999101, 999091, 999083, 999067, 999049, 999043, 999029, 999023, 999007, 998989, 998983, 998969, 998957, 998951, 998947, 998941, 998927, 998917, 998909, 998897, 998861, 998857, 998843, 998839, 998831, 998819, 998813, 998779, 998759, 998749, 998743, 998737, 998717, 998689, 998687, 998681, 998653, 998651, 998633, 998629, 998623, 998617, 998561, 998551};

bool notPrime[1000006] = {};
int MAX = 1e6, sqr = sqrt(MAX);
vector<int> primeNum;

void sieve()
{
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i <= sqr; ++i)
        if (!notPrime[i])
            for (int j = i * i; j <= MAX; j += i)
                notPrime[j] = 1;
    for (int i = 2; i <= 5e3; ++i)
        if (!notPrime[i])
            primeNum.push_back(i);
}

long long Fibo[95];

void Fibonacci()
{
    Fibo[0] = 0;
    Fibo[1] = Fibo[2] = 1;
    for (int i = 3; i <= 92; ++i)
        Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
}

// sinh

void MIX(vector<int> &v)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    shuffle(v.begin(), v.end(), e);
}

// sinh test nho
void createTest(ofstream &fout)
{
    int t = CreLL(1, 100);
    fout << t << "\n";
    while (t--)
    {
        int n = CreLL(1, 100);
        for (int i = 1; i <= n; i++)
        {
            char x = 'a';
            int cnt = CreLL(0, 25);
            fout << (char)(x + cnt);
        }
        fout << endl;
    }
}

// sinh test vua
void createTest2(ofstream &fout)
{
    int t = CreLL(100, 1000);
    fout << t << "\n";
    while (t--)
    {
        int n = CreLL(100, 5000);
        for (int i = 1; i <= n; i++)
        {
            char x = 'a';
            int cnt = CreLL(0, 25);
            fout << (char)(x + cnt);
        }
        fout << endl;
    }
}

// sinh test lon
void createTest3(ofstream &fout)
{
    int t = CreLL(1000, 10000);
    fout << t << "\n";
    while (t--)
    {
        int n = CreLL(5000, 100000);
        for (int i = 1; i <= n; i++)
        {
            char x = 'a';
            int cnt = CreLL(0, 25);
            fout << (char)(x + cnt);
        }
        fout << endl;
    }
}

// sinh test vo cung lon
void createTest4(ofstream &fout)
{
}

// cho nay khong can sua
int main()
{
    srand(time(NULL));
    int N = 75;
    for (int i = 0; i < N; i++)
    {
        string a;
        a = to_string(i);
        string input = "test/" + a + ".in";
        ofstream fout(input.c_str());
        if (i < 25)
            createTest(fout);
        else if (i < 50)
            createTest2(fout);
        else if (i < 95)
            createTest3(fout);
        else if (i < 100)
            createTest4(fout);
        fout.close();
    }
    return 0;
}
