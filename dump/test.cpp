#include <bits/stdc++.h>
using namespace std;

#define C 26

map<int, vector<string>> mp[6];

inline int pw(int x, int n) {
    int res = 1;
    while(n) {
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int H(string s) {
    int n = s.size();
    int curr = pw(C, n);
    int temp = 0;
    for(int i = 1;i <= n; ++i) {
        temp += (s[i-1] - 'a') * pw(C, n-i);
    }
    return temp;
}

void dp(int x, string s, int n) {
    if(x == 0) {
        mp[n][H(s)].push_back(s);
        if(mp[n][H(s)].size() > 3) {
            for(auto i : mp[n][H(s)]) {
                cout << i << " ";
            }
            cout << '\n';
        }
        return;
    }
    for(int i = 0; i < C; ++i) {
        dp(x-1, s + char('a' + i), n);
    }
}
int main(){
    for(int i = 1;i <= 6; ++i) {
        dp(i, "", i);
    }
}