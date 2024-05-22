#pragma GCC optimize("O3, Ofast")

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> &weights, vector<int> &values, int n, int K) {
    vector<vector<int>> dp(W + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = W; w >= weights[i - 1]; w--) {
            for(int k = K; k > 0; k--) {
                dp[w][k] = max(values[i - 1] + dp[w - weights[i - 1]][k - 1], dp[w][k]);
            }
        }
    }

    return dp[W][K];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, N, M, K;
    cin >> T;

    while (T--) {
        cin >> N >> M >> K;
        vector<int> weights(N), values(N);
        for (int i = 0; i < N; i++)
            cin >> weights[i] >> values[i];
        cout << knapsack(M, weights, values, N, K) << '\n';
    }

    return 0;
}