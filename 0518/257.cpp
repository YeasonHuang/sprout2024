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

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void updateRange(int left, int right, int value) {
        updateRange(1, 0, n - 1, left, right, value);
    }

    int query(int left, int right) {
        return queryCount(1, 0, n - 1, left, right);
    }

private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2 * node, start, mid);
            build(nums, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateRange(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return;
        }
        if (left <= start && right >= end) {
            tree[node] += (end - start + 1);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, left, right, value);
        updateRange(2 * node + 1, mid + 1, end, left, right, value);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int queryCount(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && right >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftCount = queryCount(2 * node, start, mid, left, right);
        int rightCount = queryCount(2 * node + 1, mid + 1, end, left, right);
        return leftCount + rightCount;
    }
};

void solve() {
    int N, M, A, B;
    string op;
    
    cin >> N >> M;
    vector<int> v(N, 1);
    SegmentTree tr(v);

    while(M--) {
        cin >> op >> A >> B;
        if(op == "TURN") {

        }
        else if(op == "RESET") {
        
        }
        else if(op == "COUNT") {

        }
    }
}
signed main() {
    fast_cin();
    solve();
    return 0;
}