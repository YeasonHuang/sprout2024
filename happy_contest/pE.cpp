#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <bits/extc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

char _i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0, _t;
#define qin(x) { if(_i[_i0] == '-'){ _t = -1 ; _i0++; }else{ _t = 1; } for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); x*=_t;}
inline void qout(int x) { if(x<0){_o[_o0++]='-';x=-x;}_ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = ln;}

int s[101], t;

int f(int x) {
    if(x > 100) return x - 10;
    else return f(f(x + 11));
}

void init() {
    for(int i = 1; i <= 100; i++) {
        s[i] = f(i);
        qout(s[i]);
    }
}

void solve() {
    int t;
    qin(t);
    qout(t);
    qout(s[t]);
}
signed main() {
    fread_unlocked(_i, 1, 1 << 24, stdin);
    qin(t);
    //init();
    for(int it=1;it<=t;it++) {
        //solve();
        qout(91);
    }
    fputs_unlocked(_o, stdout);
    return 0;
}