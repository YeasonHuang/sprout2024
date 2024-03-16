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
struct binary_tree {
    int data;
    binary_tree* left;//binary_tree* left= nullptr;
    binary_tree* right;//binary_tree* right= nullptr;
};
void preorder(binary_tree* top, int num) {
    if(num > top->data){
        if(top->right == nullptr) {
            top->right = new binary_tree;
            top->right->data = num;
            top->right->left = nullptr;
            top->right->right = nullptr;
        }
        else {
            preorder(top->right, num);
        }
    }
    else if(num < top->data) {
        if(top->left == nullptr) {
            top->left = new binary_tree;
            top->left->data = num;
            top->left->left = nullptr;
            top->left->right = nullptr;
        }
        else {
            preorder(top->left, num);
        }
    }
}

void lastorder(binary_tree* top){
    if(top->left != nullptr) {
        lastorder(top->left);
    }
    if(top->right != nullptr) {
        lastorder(top->right);
    }
    cout << top->data << ln;
}

signed main() {
    fast_cin();
    int num, N;
    binary_tree* tr = new binary_tree;
    tr->left = nullptr;
    tr->right = nullptr;

    cin >> N >> num;
    tr->data = num;
    while(--N) cin >> num, preorder(tr, num);
    lastorder(tr);

    return 0;
}