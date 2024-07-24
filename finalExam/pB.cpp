#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define fastIO() cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(),x.end()
#define FORSN(i,s,e) for(int i = s;i < e; ++i)
#define FORN(i,e) for(int i = 0;i < e; ++i)
#define pii pair<int,int>
#define fi first
#define se second

using namespace __gnu_pbds;
using namespace std;

vector<int> father, ans, checked;// , _rank;
vector<pii> wars, querys;
//map<pii, int> querys;

int find(int x) {
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

void merge(int x, int y) {
    int X = find(x), Y = find(y);
    //if(_rank[X] < _rank[Y]) {
    //    father[X] = Y;
    //}
    //else {
    if(X != Y) {
        father[Y] = X;
    }
    else {
        if(y == Y) {
            father[y] = father[x] = x;
        }
    }
    //}
}
signed main() {
    fastIO();
    int N, M, Q, c, d;
    cin >> N >> M;

    father.resize(N+1), wars.resize(M);//, _rank.resize(N+1);
    for(int i = 1;i <= N; ++i) {
        father[i] = i;
        //_rank[i] = 1;
    }
    for(int i = 0;i < M; ++i) cin >> wars[i].first >> wars[i].second;
    cin >> Q, querys.resize(Q), ans.resize(Q), checked.resize(Q);
    for(int i = 0;i < Q; ++i) {
        cin >> c >> d;
        querys[i] = {c, d};
        ans[i] = checked[i] = 0;
    }

    for(int i = 0;i < M; ++i) {
        merge(wars[i].first, wars[i].second);
        //for(int j = 1;j <= N; ++j) {
        //    cout << father[j] << " ";
        //}
        //cout << "\n";
        for(int j = 0;j < Q; ++j) {
            if(checked[j]) continue;
            if(find(querys[j].first) == find(querys[j].second)) {
                ans[j] = (ans[j] ? ans[j] : find(querys[j].first));
                checked[j] = 1;
            }
        }
    }

    for(int i = 0;i < Q; ++i) cout << ans[i] << "\n";

    return 0;
}
