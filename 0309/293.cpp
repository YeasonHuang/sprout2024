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

int t;
vector<int> Edge[100005];
bool visit[100005];

struct Node{
    int sum;
    int maxn;
}node[100005];

int dfs(int id){
    ::visit[id] = true;
    int len = Edge[id].size();
    for(int i=0;i<len;i++){
        int temp = Edge[id][i];
        if(::visit[temp]==1)continue;
        int t = dfs(temp);
        node[id].sum += t;
        node[id].maxn = max(node[id].maxn,t);
    }
    return node[id].sum+1;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        int n;cin>>n;
        memset(::visit, 0, sizeof(::visit));
        
        for(int i=0;i<n;i++){
            Edge[i].clear();
            node[i].maxn = node[i].sum = 0;
        }
        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            Edge[a].push_back(b);
            Edge[b].push_back(a);
        }
        dfs(0);
        int ans = n,index = 0;
        for(int i=0;i<n;i++){
            int temp = max(node[i].maxn,n-node[i].sum-1);
            if(temp<ans){
                index = i;
                ans = temp;
            }
        }
        cout<<index<<'\n';
    }
}