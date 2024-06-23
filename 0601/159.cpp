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


void solve() {
    int N, M; 
    cin >> N >> M;

    vector<int> C(N); 
    vector<int> K(N); 
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> K[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0, k; j <= M; ++j) {
            int LIM = min(j / C[i - 1], K[i - 1]);
            //dp[i][j] = dp[i][j] || dp[i - 1][j];
            for (k = 1; k <= LIM; k <<= 1) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - k * C[i - 1]];
            }
            dp[i][j] = dp[i][j] || dp[i - 1][j - (LIM - k) * C[i - 1]];
        }
    }

    cout << (dp[N][M] ? "Yes" : "No") << ln;
    //for (int i = 1; i <= N; ++i) {
    //    for (int j = 0, k; j <= M; ++j) {
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << ln;
    //}
    //cout << ln;
}
signed main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}