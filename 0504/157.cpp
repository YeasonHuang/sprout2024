#pragma GCC optimize("O3, Ofast")

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int w = W; w >= weights[i - 1]; w--) {
            dp[w] = max(values[i - 1] + dp[w - weights[i - 1]], dp[w]);
        }
    }

    return dp[W];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int T, N, M;
    cin >> T;

    while(T--) {
        cin >> N >> M;
        vector<int> weights(N), values(N);
        for(int i = 0; i < N; i++) cin >> weights[i] >> values[i];
        cout << knapsack(M, weights, values, N) << '\n';
    }

    return 0;
}