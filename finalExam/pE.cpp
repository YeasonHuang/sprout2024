#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define fastIO() cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(),x.end()
#define FORSN(i,s,e) for(int i = s;i < e; ++i)
#define FORN(i,e) for(int i = 0;i < e; ++i)

using namespace __gnu_pbds;
using namespace std;

#define ll long long

signed main() {
    fastIO();

    ll N, Q, K, P, V, sum = 0, sub, x;
    cin >> N >> Q >> K;

    vector<ll> E(N), S(N);
    for(ll i = 0;i < N; ++i) {
        cin >> x;
        E[i] = x;
        sum += x;
        S[i] = sum;
    }


    while(Q--) {
        cin >> P >> V;
        sum += V - E[P-1];
        //E[P-1] = V;
        for(ll i = P-1;i < N; ++i) S[i] += V - E[P-1];
        //for(auto it : S) cout << it << " ";

        sub = S[K-1];
        for(ll i = K;i < N; ++i) sub = min(sub, S[i]-S[i-K]);

        cout << sum - sub << "\n";
    }

    return 0;
}
