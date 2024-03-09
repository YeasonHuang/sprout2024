#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
using namespace std;
struct point{
    int x;
    int y;
    
};
point makePoint(int y,int x){
        point P;
        P.y=y,P.x=x;
        return P;
    }
char mp[105][105];
int dis[105][105];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int N, M, minDist;
/*
void dfs(int y0, int x0) {
	if (mp[y0][x0] == '@') {
		minDist = min(minDist, dis[y0][x0]);
	}
	mp[y0][x0] = '#';
	for (int i = 0;i < 4; ++i ) {
		if (mp[y0 + dy[i]][x0 + dx[i]] != '#') {
			dis[y0 + dy[i]][x0 + dx[i]] = dis[y0][x0] + 1;
			dfs( y0 + dy[i], x0 + dx[i] );
		}
	}
}*/
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T, y0, x0;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(dis, 0, sizeof(dis));
		minDist = INT_MAX;
		point O;
		for (int i = 0;i < N;++i) {
			for (int j = 0;j < M;++j) {
				cin >> mp[i][j];
				if (mp[i][j] == 'K') O.y=i,O.x=j;
			}
		}/*
		dfs(y0, x0);
		*/
		queue<point> Q;
		Q.push(O);
		while (!Q.empty()) {
			y0 = Q.front().y, x0 = Q.front().x;
			for (int i = 0;i < 4;++i) {
			    if (mp[y0 + dy[i]][x0 + dx[i]] == '@') {
				    minDist = min(minDist, dis[y0][x0]+1);
			    }
				if (mp[y0 + dy[i]][x0 + dx[i]] != '#') {
				    mp[y0 + dy[i]][x0 + dx[i]] = '#';
					Q.push(makePoint( y0 + dy[i], x0 + dx[i] ));
					dis[y0 + dy[i]][x0 + dx[i]] = dis[y0][x0] + 1;
				}
			}
			Q.pop();
		}
        /*
		for (int i = 0;i < N;++i) {
			for (int j = 0;j < M;++j)
				cout << dis[i][j];
			cout << '\n';
		}
        */
		if (minDist == INT_MAX) cout << "= =\"\n";
		else cout << minDist << '\n';
	}
}