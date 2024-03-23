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
ld eps = 1e-12;
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
 
inline bool equal(ld a, ld b){return fabsl(a-b) <= eps;}

void solve(){
    int N;
    cin >> N;
    cout << fixed << setprecision(15);
    ld a[N], b[N], c[N], A, B, C, mn = INF;
    for(int i = 0;i < N; ++i) {
        cin >> A >> B >> C;
        a[i] = A;
        b[i] = A * B * (-2);
        c[i] = A * B * B + C;
    }

    for(int i = 0; i < N; ++i) {
        for(int j = i+1;j < N; ++j) {
            ld da = a[i]-a[j], db = b[i]-b[j], dc = c[i]-c[j], dd = sqrtl(db*db - (4)*da*dc), x1, x2;
            if(equal(da,0)) x1 = x2 = (-1) * dc / db;
            else x1 = ((-1)*db + dd) / (2 * da), x2 = ((-1)*db - dd) / (2 * da);
            //cout << da << ' ' << db << ' ' << dc << ' ' << dd << '\n';
            //cout << x1 << ' ' << x2 << '\n';
            if(0 <= x1 && x1 <= 300) {
                mn = min(a[i]*x1*x1 + b[i]*x1 + c[i], mn);
            }
            if(0 <= x2 && x2 <= 300) {
                mn = min(a[i]*x2*x2 + b[i]*x2 + c[i], mn);
            }
        }
    }

    cout << mn << '\n';
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