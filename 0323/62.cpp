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
//typedef vector<vector<int>(10)>(10) vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
//typedef vector<vector<vector<bool>(10)>(10)>(10) vvvb;
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
 
void dp(int y, int x, vector<vector<vector<bool>>> occ(10, vector<vector<bool>>(10, vector<bool>(10))), vector<vector<int>(10)>(10) mp){
    if(x == 9) {
        if(y == 8){
            for(int i = 0;i < 81; ++i) cout << mp[i/9][i%9];
            cout << '\n';
            return;
        }
        else{
            dp(y+1, 0, occ, mp);
        }
    }
    
    bool flag = 1;
    for(int num = 1;num <= 9; ++num) {
        if(!occ[y][x][num]) {
            flag = 0;
            
            vector<vector<vector<bool>(10)>(10)>(10) tocc;
            copy(all(occ), tocc.begin());
            vector<vector<int>(10)>(10) tmp;
            copy(all(mp), tmp.begin());
            
            int isec = y/3, jsec = x/3;
            tmp[y][x] = num;
            
            for(int k = 0;k < 9; ++k) tocc[y][x][k] = 1;

            for(int ii = 0; ii < 9; ++ii) {
                tocc[ii][x][num] = 1;
            }
            for(int jj = 0; jj < 9; ++jj) {
                tocc[y][jj][num] = 1;
            }

            for(int ii = 3*isec;ii < 3*(isec+1); ++ii) {
                for(int jj = 3*jsec;jj < 3*(jsec+1); ++jj) {
                    tocc[ii][jj][num] = 1;
                }
            }
            
            dp(y,x+1,tocc,tmp);
        }
    }

    if(flag){
        cout << "-1\n";
        return;
    }
}

void solve(){
    char ch;
    vector<vector<vector<bool>(10)>(10)>(10) occ;
    vector<vector<int>(10)>(10) mp;

    for(int i = 0; i < 9; ++i) {
        for(int j = 0;j < 9; ++j) {
            cin >> ch;
            if(ch == '.') continue;
            int num = ch - '0', isec = i/3, jsec = j/3;
            mp[i][j] = num;
            
            for(int k = 0;k < 9; ++k) occ[i][j][k] = 1;

            for(int ii = 0; ii < 9; ++ii) {
                occ[ii][j][num] = 1;
            }
            for(int jj = 0; jj < 9; ++jj) {
                occ[i][jj][num] = 1;
            }

            for(int ii = 3*isec;ii < 3*(isec+1); ++ii) {
                for(int jj = 3*jsec;jj < 3*(jsec+1); ++jj) {
                    occ[ii][jj][num] = 1;
                }
            }
        }
    }
}
int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}