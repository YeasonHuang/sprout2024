#pragma GCC optimize("O3,Ofast")

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define ff first.first
#define ss first.second
#define tt second

using namespace __gnu_pbds;
using namespace std;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int N, M, my, mx, q, t, x, y, T = 0, flag = 0;
    int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
    char ch;
    cin >> N >> M;

    bool _mp[N][M];
    map<int,queue<piii>> cats;

    for(int i = 0;i < N; ++i) {
        for(int j = 0;j < M; ++j) {
            cin >> ch;
            _mp[i][j] = (ch != '#');
            if(ch == '@') my = i, mx = j;
            else if(ch == 'K') cats[0].push({{i,j},0});
        }
    }

    cin >> q;
    bool mp[q+1][N][M];
    for(int i = 0;i < N; ++i) {for(int j = 0;j < M; ++j) { for(int k = 0;k <= q; ++k){mp[k][i][j] = _mp[i][j];}}}
    for(int i = 1; i <= q; ++i) {
        cin >> t >> y >> x;
        cats[t].push({{y,x},i});
    }



    queue<piii> Q, QQ;//, del;

    while(!Q.empty()) {


        while(!Q.empty()) {
            QQ.push(Q.front());
            Q.pop();
        }


        while(!QQ.empty()) {

            int yy = QQ.front().ff, xx = QQ.front().ss, qq = QQ.front().tt;

            /*cout << yy << ' ' << xx << '\n';
            for(int i = 0;i < N; ++i) {
                for(int j = 0;j < M; ++j) {
                    cout << mp[i][j];
                }
                cout << '\n';
            }
            cout << '\n';*/

            if(yy == my && xx == mx) {
                flag = 1;
                break;
            }

            for(int dir = 0; dir < 4 ; ++dir) {
                if(mp[qq][yy+dy[dir]][xx+dx[dir]]) {
                    Q.push({{yy+dy[dir], xx+dx[dir]},qq});
                    //del.push({yy+dy[dir], xx+dx[dir]});
                    mp[qq][yy+dy[dir]][xx+dx[dir]] = 0;
                }
            }
            QQ.pop();
        }

        //while(!del.empty()) {
        //    mp[del.front().ff][del.front().ss] = 0;
        //    del.pop();
        //}

        if(flag) break;

        while(!cats[T].empty()) {
            if(mp[cats[T].front().tt][cats[T].front().ff][cats[T].front().ss]) Q.push(cats[T].front());
            cats[T].pop();
        }
        ++T;
    }

    if(flag) cout << T << '\n';
    else cout << "= =\"\n";

    return 0;
}
