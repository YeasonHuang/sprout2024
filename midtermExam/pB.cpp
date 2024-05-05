#pragma GCC optimize("O3,Ofast")

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long

using namespace __gnu_pbds;
using namespace std;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int Q, K, op, x, s = 0;
    cin >> Q >> K;

    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> tr;

    while(Q--) {
        cin >> op;
        if(op == 1) {
            cin >> x;
            tr.insert(x-s);
        }
        else if(op == 2) {
            cin >> x;
            s += x;
        }
        else if(op == 3) {
            if(tr.size() < K) cout << "No solution\n";
            else cout << *tr.find_by_order(K-1) + s << '\n';
        }
    }

    return 0;
}
