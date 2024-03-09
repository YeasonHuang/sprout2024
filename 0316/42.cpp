#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <bits/extc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

bool mpp[1005][1005];
int T,N,M,cnt,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
inline bool inbound(int y,int x){return x>=0 && y>=0 && x<M && y<N;}
void dfs(int y,int x){
    if(!inbound(y,x)) return;
    //cout<<y<<' '<<x<<'\n';
    mpp[y][x]=0;
    for(int i = 0;i < 4; ++i) {
        if(mpp[y+dy[i]][x+dx[i]]) dfs(y+dy[i], x+dx[i]);
    }
}
int main(){
    fast_cin();
    char ch;
    cin >> T;
    while(T--) {
        cnt=0;
        cin >> N >> M;
        for(int i = 0;i < N; ++i) {
            for(int j = 0;j < M; ++j) {
                cin >> ch;
                mpp[i][j]=(ch=='.');
            }
        }
        for(int i = 0;i < N; ++i) {
            for(int j = 0;j < M; ++j) {
                if(mpp[i][j]) dfs(i,j), ++cnt;
            }
        }
        cout<<cnt<<'\n';
    }
}