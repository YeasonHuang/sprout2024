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
#define N 105

void solve() {
    ll n, m, s, e, f, dis[N];
    bool visit[N];
    vp64 edge[N];
    
    cin >> n >> m >> s >> e >> f;
    fill(dis, dis+N, LONG_LONG_MAX);
    
    memset(visit, 0, sizeof(visit));
    
    forn(i, m){
        ll a, b, c, d, e, val;
        cin >> a >> b >> c >> d >> e;
        val = (f>d ? c*d+e*(f-d) : c*f);
        edge[a].push_back({b,val});
    }

    std::priority_queue<p64, vp64, greater<p64>> pq;
    pq.push({0,s});
    dis[s] = 0;
    
    while(!pq.empty()) {
        ll cur = pq.top().second;
        pq.pop();
        if(visit[cur]) continue;
        
        for(auto i:edge[cur]){
            ll next = i.first, weight = i.second;
            if(dis[cur] + weight < dis[next]) {
                dis[next] = dis[cur] + weight;
                pq.push({dis[next],next});
            }
        }
        visit[cur] = 1;
    }
    cout << dis[e] << ln;
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