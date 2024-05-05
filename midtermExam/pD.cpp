#pragma GCC optimize("O3,Ofast")

#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
#define pii pair<long long,long long>

using namespace __gnu_pbds;
using namespace std;

int N, W, ans = -1;
pii P[200005];

bool cmp(pii a, pii b) {
    return a.second == b.second ? a.first > b.first : a.second > b.second;
}

void dp(int x,int nMax, int cost, int cnt) {
    if(x == N) {
        ans = max(ans, cnt);
        return;
    }
    dp(x+1, nMax, cost, cnt);
    if(cnt <= min(nMax,P[x].second) && cost + P[x].first <= W) dp(x+1, min(nMax,P[x].second), cost + P[x].first, cnt+1);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> N >> W;
    for(int i = 0;i < N; ++i) cin >> P[i].first;
    for(int i = 0;i < N; ++i) cin >> P[i].second;
    sort(P, P+N, cmp);

    //for(int i = 0;i < N; ++i) cout << P[i].first << ' ' << P[i].second << '\n';
    dp(0, 200005, 0, 0);
    cout << ans << '\n';

    return 0;
}
