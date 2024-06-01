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

class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { std::swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int N;
	int M;
	std::cin >> N >> M;

	struct edge {
		int c1, c2;
		int cost;
	};
	vector<edge> edges(M);
	for (edge &r : edges) {
		std::cin >> r.c1 >> r.c2 >> r.cost;
		r.c1--;
		r.c2--;
	}
	std::sort(edges.begin(), edges.end(), [&](const edge &e1, const edge &e2) {
		return e1.cost < e2.cost;
	});

	DisjointSets cities(N);
	long long min_cost = 0;
	int added = 0;
	for (edge &r : edges) {
		bool status = cities.unite(r.c1, r.c2);
		min_cost += status * r.cost;
		added += status;
	}

	if (added != N - 1) {
		cout << "IMPOSSIBLE" << ln;
	} else {
		cout << min_cost << ln;
	}
}
signed main() {
    fast_cin();
    solve();
    return 0;
}