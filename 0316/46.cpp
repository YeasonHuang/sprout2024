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

int grid[1005][1005], dx[8] = {1,1,0,-1,-1,-1,0,1}, dy[8] = {0,-1,-1,-1,0,1,1,1};
int combine[8][8] = {
  // X R Y B O G P D
  // 0 1 2 3 4 5 6 7
    {0,0,0,0,0,0,0,0},
    {0,1,4,6,4,7,6,7},
    {0,4,2,5,4,5,7,7},
    {0,6,5,3,7,5,6,7},
    {0,4,4,7,4,7,7,7},
    {0,7,5,5,7,5,7,7},
    {0,6,7,6,7,7,6,7},
    {0,7,7,7,7,7,7,7},
};

int c2n(char ch){return (ch == 'R' ? 1 : (ch == 'Y' ? 2 : (ch == 'B' ? 3 : (ch == 'O' ? 4 : (ch == 'G' ? 5 : (ch == 'P' ? 6 : (ch == 'D' ? 7 : 0)))))));}

bool inbound(int y, int x, int n) {return y>=0 && y<n && x>=0 && x<n;}

void solve() {
    int N, y, x, cnt[8] = {0, 1, 1, 1, 0, 0, 0, 0};
    char ch;
    cin >> N;

    for(int i = 0;i < N; ++i) fill(grid[i], grid[i] + N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> ch >> y >> x;
        grid[y][x] = c2n(ch);
    }
    cin >> ch;

    while(cnt[7] < N*N) {
        for(int y = 0;y < N; ++y) {
            for(int x = 0;x < N; ++x) {
                for(int k = 0;k < 8; ++k) {
                    int yp = y+dy[k], xp = x+dx[k];
                    if(!inbound(yp, xp)) continue;
                    cnt[grid[y][x]]--;
                    grid[y][x]
                }
            }
        }
    }
}

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;++it) {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}