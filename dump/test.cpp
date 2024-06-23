#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; // number of coin types
    cin >> N;
    vector<int> C(N); // coin denominations
    vector<int> K(N); // number of coins
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> K[i];
    }
    int M; // target amount
    cin >> M;

    vector<int> dp(M + 1, INT_MAX); // dp[i] represents the minimum number of coins needed to make amount i
    dp[0] = 0; // base case, it takes 0 coins to make amount 0

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[j] != INT_MAX && j + C[i] <= M && dp[j] + 1 <= K[i]) {
                dp[j + C[i]] = min(dp[j + C[i]], dp[j] + 1);
            }
        }
    }

    if (dp[M] == INT_MAX) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}