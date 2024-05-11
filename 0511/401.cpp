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
 
using namespace std;
 
struct pt{
    int x,y;
    bool operator < (pt b){
        if(x == b.x)return y < b.y;
        return x < b.x;
    }
    bool operator > (pt b){
        if(x == b.x)return y > b.y;
        return x > b.x;
    }
    bool operator == (pt b){
        if(x-b.x<=eps && y-b.y<=eps)return true;
        return false;
    }
    pt operator+(pt b) {return {x + b.x, y + b.y};} //向量相加
    pt operator-(pt b) {return {x - b.x, y - b.y};} //向量相減
    int operator^(pt b) {return x * b.y - y * b.x;} //向量外積cross
    int operator*(pt b) {return x * b.x + y * b.y;} //向量內積dot
};

vector<pt> point(4);
int n, t;

int dir(pt a, pt b, pt o) {
    int cross = (a - o) ^ (b - o);
    if(fabs(cross) <= eps) return 0;
    else if(cross > 0) return 1;
    else return -1;
}
bool onseg(pt a, pt b, pt o) {
    int cross = (a - o) ^ (b - o); 
    int dot = (a - o) * (b - o);
    return ((cross == 0) && (dot <= 0));
}
 
bool Intersection(pt a, pt b, pt c, pt d) {
    if(onseg(a,b,c) || onseg(a,b,d)) return true;
    if(onseg(c,d,a) || onseg(c,d,b)) return true;
    if(dir(a,b,c)*dir(a,b,d)==-1 && dir(c,d,a)*dir(c,d,b)==-1) return true;                                
    return false;
}

void solve(){
    forsn(i,0,4) cin >> point[i].x >> point[i].y;
    if(Intersection(point[0],point[1],point[2],point[3])) cout<<"Yes\n";
    else cout<<"No\n";
}
 
signed main(){
    fast_cin();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}