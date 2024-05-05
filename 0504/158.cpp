#pragma GCC optimize("O3, Ofast")

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int N, int M, int K, vector<int>& weights, vector<int>& values) {
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        int weight = weights[i - 1];
        int value = values[i - 1];
        int count = min(K, M / weight);

        for (int j = M; j >= weight; j--) {
            for (int k = 1; k <= count; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * weight] + k * value);
            }
        }
    }

    return dp[N][M];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int T, N, M, K;
    cin >> T;

    while(T--) {
        cin >> N >> M >> K;
        vector<int> weights(N), values(N);
        for(int i = 0; i < N; i++) cin >> weights[i] >> values[i];

        cout << knapsack(N, M, K, weights, values) << '\n';
    }

    return 0;
}