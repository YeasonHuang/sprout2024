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
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define int long long

void solve() {
    string S;
    char ch;
    cin >> S;

    int N = S.size(), idx = 0, hS = 0, hT = 0, base = 1;

    for(int i = 0;i < N; ++i) {
        hS = (hS * 27) % MOD;
        hS += (S[i]-'a'+1);
        base = (base * 27) % MOD;
    }
    base /= 27;
    cout << hS << ' ' << base << ln;

    for(int i = 0;i < N-1; ++i) {
        cin >> ch;
        hT = (hT * 27) % MOD;
        hT += (ch-'a'+1) ;
    }

    while(cin >> ch) {
        hT = (hT * 27) % MOD;
        hT += (ch-'a'+1);
        cout << hT << ln;
        if(hT == hS) cout << idx << ' ';
        hT = (hT - (base * (ch-'a'+1)) % MOD + MOD) % MOD;
        ++idx;
    }

    return;
}
signed main() {
    fast_cin();
    solve();
    return 0;
}