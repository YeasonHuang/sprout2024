#pragma GCC optimize("O3, Ofast, unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define mod 1000000007
#define modify(x) (x%mod+mod)%mod

int N, a, b, K, dp[2][2005], res = 0;

void sec(int l, int r, int v, int id) {
    l = max(l, (long long)1);
    r = min(r, N);
    dp[(id+1)%2][l] = modify(dp[(id+1)%2][l] + v);
    dp[(id+1)%2][r+1] = modify(dp[(id+1)%2][r+1] - v);
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> N >> a >> b >> K;

    memset(dp,0,sizeof(dp));

    dp[0][a] = 1;
    for(int s = 0; s < K; ++s) {  
        for(int i = 1; i <= N; ++i) {
            int d = abs(b - i) - 1;
            sec(i-d, i-1, dp[s%2][i], s);
            sec(i+1, i+d, dp[s%2][i], s);
        }
        for(int i = 1; i <= N; ++i) {
            dp[(s+1)%2][i] += dp[(s+1)%2][i-1];
            dp[(s+1)%2][i] = modify(dp[(s+1)%2][i]);
        }
        for(int i = 1; i <= N; ++i) dp[(s)%2][i] = 0;
    }

    for(int i = 1; i <= N; ++i) {
        res += dp[K%2][i];
        res = modify(res);
    }

    cout << res <<'\n';
}