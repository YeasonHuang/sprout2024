#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;
int n,T;

bool visited[100005],color[100005];
vector<int> edge[100005];

bool dfs(int id, bool col){
    visited[id] = 1;
    color[id] = col;
    int len = edge[id].size();
    for(int i=0;i<len;i++){
        int temp = edge[id][i];
        if(visited[temp]){
            if(color[temp]==col)return 0;
            else continue;
        }
        if(!dfs(temp, !col))return 0;
    }
    return 1;
}
signed main(){
    ios;
    cin>>T;
    while(T--){
        int m;cin>>n>>m;
        for(int i=0;i<n;i++)edge[i].clear();
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        while(m--){
            int a,b;cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        bool f = 1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!dfs(i, 0)){
                    f = 0;
                    break;
                }
            }
        }
        if(f)cout<<"NORMAL."<<endl;
        else cout<<"RAINBOW."<<endl;
    }
}