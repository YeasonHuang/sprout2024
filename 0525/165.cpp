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
    int n, m, a, b, ind = 0;
    int ans[100005], deg[100005];
    memset(deg, 0, sizeof(deg));
    memset(ans, 0, sizeof(ans));
    vector<int> edge[100005];
    cin >> n >> m;
    forn(i, m) {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        ++deg[b];
    }
    std::priority_queue<int, vector<int>, greater<int>> qq;
    forn(i, n) {
        if(deg[i] == 0) qq.push(i);
    }
    while(!qq.empty()){
        int cur = qq.top();
        qq.pop();
        ans[ind++] = cur;
        int len = edge[cur].size();
        forn(i, len) {
            deg[edge[cur][i]]--;
            if(deg[edge[cur][i]] == 0) qq.push(edge[cur][i]);
        }
    }
    if(ind == n) {
        cout << ans[0];
        forsn(i, 1, n) cout << " " << ans[i];
        cout << ln;
    }
    else cout << "QAQ\n";
}
signed main() {
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}