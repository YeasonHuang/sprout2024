#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <bits/extc++.h>
 
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
ll MOD = 1e9 + 7;
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


struct mat{
    vector<vector<ll>> a;
    ll N, M, mod = MOD;

    mat(ll N, ll M) {
        this->N = N;
        this->M = M;
        a.resize(N, vector<ll>(M, 0));
    }

    mat(const vector<vector<ll>> &b){
        N = b.size();
        M = b[0].size();
        a.resize(N, vector<ll>(M, 0));
        copy(b.begin(), b.end(), back_inserter(a));
    }

    mat operator * (const mat &b)const{
        mat ret(N, b.M);
        for (ll i = 0; i < N; ++i){
            for (ll j = 0; j < M; ++j){
                for (ll k = 0; k < M; ++k){
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return ret;
    }

    mat operator ^ (const int &p)const{
        if(p == 1) return *this;
        mat ret = *this ^ (p >> 1);
        ret = ret * ret;
        if(p & 1) ret = ret * (*this);
        return ret;
    }

    void print() {
        for(ll i = 0; i < N; i++){
            cout << a[i][0];
            for(ll j = 1; j < M; j++){
                cout << " " << a[i][j];
            }
            cout << ln;
        }
    }
};

void solve() {
    ll N, M, L;
    cin >> N >> M >> L;
    
    mat A(N, N);

    for(ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        A.a[--a][--b] = 1;
    }

    A = A ^ L;
    A.print();
}
signed main() {
    fast_cin();
    solve();
    return 0;
}