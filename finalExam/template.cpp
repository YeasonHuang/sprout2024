#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define fastIO() cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(),x.end()
#define FORSN(i,s,e) for(int i = s;i < e; ++i)
#define FORN(i,e) for(int i = 0;i < e; ++i)

using namespace __gnu_pbds;
using namespace std;

#define mat vector<vector<int>>


mat merge(mat a, mat b) {
    if(a[0].size() != b.size()) return {{-1}};
    int N = a.size(), M = b.size(), K = b[0].size();
    vector<vector<int>> res(N, vector<int>(K));
    for(int i = 0;i < N; ++i) {
        for(int j = 0;j < K; ++j) {
            res[i][j] = -2147483647;
            for(int k = 0;k < M; ++k) {
                res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
                //res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

mat merge2(mat a, mat b) {
    int N = a.size();
    vector<vector<int>> res(N, vector<int>(N));
    for(int i = 0;i < N; ++i) {
        for(int j = 0;j < N; ++j) {
            res[i][j] = -2147483647;
            for(int k = 0;k < N; ++k) {
                if(a[i][k] == 0 || b[k][j] == 0) continue;
                res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
                //res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

mat pow(mat a, int x) {
    if(a.size() != a[0].size()) return{{-1}};
    int N = a.size();
    mat res = a;
    --x;
    while(x) {
        if(x&1) res = merge(res, a);
        a = merge(a, a);
        x >>= 1;
    }
    return res;
}

signed main() {
    fastIO();
    int N, M, K, x;

    cin >> N >> M /*>> K */>> x;
    vector<vector<int>> A(N, vector<int>(M));
    //vector<vector<int>> B(M, vector<int>(K));
    vector<vector<int>> C(N, vector<int>(K));

    for(int i = 0;i < N; ++i) {
        for(int j = 0;j < M; ++j) {
            cin >> A[i][j];
        }
    }

    /*
    for(int i = 0;i < M; ++i) {
        for(int j = 0;j < K; ++j) {
            cin >> B[i][j];
        }
    }
    */

    A = merge2(A, A);

    //C = merge(A, B);

    for(int i = 0;i < N; ++i) {
        for(int j = 0;j < M; ++j) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
