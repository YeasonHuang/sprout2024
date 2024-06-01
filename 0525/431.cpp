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
#define N 200005

ll n, m, q;

vp64 edge[2][N];

v64 Dijkstra(ll start, ll end, bool is_nor){
    bool visit[N];
    memset(visit, 0, sizeof(visit));
    v64 dis(n+2, 1e15);
    __gnu_pbds::priority_queue<p64, greater<p64>, pairing_heap_tag> pq;
    dis[start] = 0;
    pq.push({0,start});
    
    while(!pq.empty()){
        ll cur = pq.top().second;
        pq.pop();
        if(visit[cur])continue;
        
        visit[cur] = 1;
        for(auto i : edge[is_nor][cur]){
            ll next = i.first,weight = i.second;
            if(dis[next] > dis[cur] + weight){
                dis[next] = dis[cur] + weight;
                pq.push({dis[next],next});
            }
        }
    }
    return dis;
}

void solve() {
    cin >> n >> m >> q;
    forn(i, m) {
        ll a, b, w;
        cin >> a >> b >> w;
        edge[0][a].push_back({b,w});
        edge[1][b].push_back({a,w});
    }
    
    v64 normal, opposite;
    normal = Dijkstra(1, n, 0);
    opposite = Dijkstra(n, 1, 1);
    
    while(q--) {
        ll a, b;
        cin >> a >> b;
        cout << min(normal[a] + opposite[b] + 1, normal[n]) << ln;
    }
}
signed main() {
    fast_cin();
    solve();
    return 0;
}