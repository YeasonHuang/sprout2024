#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define fastIO() cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(),x.end()
#define FORSN(i,s,e) for(int i = s;i < e; ++i)
#define FORN(i,e) for(int i = 0;i < e; ++i)

using namespace __gnu_pbds;
using namespace std;

signed main() {
    fastIO();

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> tr;
    for(int i = 0;i < N; ++i) {
        cin >> A[i];
        cout << tr.order_of_key(A[i]) << " ";
        tr.insert(A[i]);
    }
    return 0;
}
