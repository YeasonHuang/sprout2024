#pragma GCC optimize("O3,Ofast")

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int N, x, idx=0;
    cin >> N;
    int v[N];
    for(int i=0;i<2*N;++i){
        cin >> x;
        if(x>0) v[idx++]=x;
    }
    cout << "1\n";
    for(int &it :v) cout << it << ' ';
    return 0;
}
