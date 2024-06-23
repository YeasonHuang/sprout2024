#include <vector>
#include <algorithm>

#define MOD 1e9+7
#define ll long long

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