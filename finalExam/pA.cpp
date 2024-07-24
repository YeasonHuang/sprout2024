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
#define mat vector<vector<ll>>

mat merge(mat a, mat b) {
    ll N = a.size();
    vector<vector<ll>> res(N, vector<ll>(N));
    for(ll i = 0;i < N; ++i) {
        for(ll j = 0;j < N; ++j) {
            res[i][j] = LONG_LONG_MIN;
            for(ll k = 0;k < N; ++k) {
                if(a[i][k] == LONG_LONG_MIN || b[k][j] == LONG_LONG_MIN) continue;
                res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
                //res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

mat pow(mat a, ll x) {
    if(a.size() != a[0].size()) return{{-1}};
    ll N = a.size();
    mat res = a;
    --x;
    while(x) {
        if(x&1) res = merge(res, a);
        a = merge(a, a);
        x >>= 1;
    }
    return res;
}

void print(mat a) {
    int N = a.size();
    for(int i = 0;i < N; ++i) {
        for(int j = 0;j < N; ++j) {
            if(a[i][j] == LONG_LONG_MIN) cout << "x ";
            else cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}


signed main() {
    fastIO();
    ll T, N, M, K, a, b, c;
    cin >> T;
    while(T--) {
        cin >> N >> M >> K;
        vector<vector<ll>> A(N, vector<ll>(N));
        for(ll i = 0;i < N; ++i) {
            fill(all(A[i]), LONG_LONG_MIN);
        }
        for(ll i = 0;i < M; ++i) {
            cin >> a >> b >> c;
            A[a-1][b-1] = c;
        }

        //print(A);

        print(pow(A, K-1));
    }

    return 0;
}
