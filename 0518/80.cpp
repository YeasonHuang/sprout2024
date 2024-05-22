#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <bits/extc++.h>
//#include "segment_tree.h"
 
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

    void update(int index, int value) {
        update(1, 0, n - 1, index, value);
    }

    int query(int left, int right) {
        return queryMin(1, 0, n - 1, left, right);
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
            tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int index, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(2 * node, start, mid, index, value);
            } else {
                update(2 * node + 1, mid + 1, end, index, value);
            }
            tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
        }
    }

    int queryMin(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return INT_MAX;
        }
        if (left <= start && right >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = queryMin(2 * node, start, mid, left, right);
        int rightMin = queryMin(2 * node + 1, mid + 1, end, left, right);
        return std::min(leftMin, rightMin);
    }
};


void solve(){
    int T, N, op, x, y;
    cin >> T >> N;

    vector<int> v(N);
    for(int &it : v) cin >> it;
    SegmentTree tr(v);

    while(T--) {
        cin >> op >> x >> y;
        if(op == 1) cout << tr.query(x, y) << ln;
        else tr.update(x, y);
    }

}
int main() {
    fast_cin();
    solve();
    return 0;
}