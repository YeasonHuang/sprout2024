#include <iostream>
#include <vector>

bool foundCombination = false;

void printCombinations(std::vector<int>& items, int target, std::vector<int>& current, std::vector<std::vector<bool>>& dp, int i, int j) {
    if (foundCombination) {
        return; 
    }

    if (i == 0 || j == 0) {
        for (int k : current) {
            Report(k);
        }
        Report(-1);
        foundCombination = true; 
        return;
    }

    if (dp[i - 1][j]) {
        printCombinations(items, target, current, dp, i - 1, j);
    }

    if (j >= items[i - 1] && dp[i - 1][j - items[i - 1]]) {
        current.push_back(i - 1); 
        printCombinations(items, target, current, dp, i - 1, j - items[i - 1]);
        current.pop_back();
    }
}

void findCombinations(std::vector<int>& items, int target, std::vector<int>& current, int index) {
    std::vector<std::vector<bool>> dp(items.size() + 1, std::vector<bool>(target + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= items.size(); i++) {
        dp[i][0] = true;
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= items[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - items[i - 1]];
            }
        }
    }

    if (dp[items.size()][target]) {
        printCombinations(items, target, current, dp, items.size(), target);
    }
}

void solve(int N, long long K, long long A[]) {
    std::vector<int> items;
    for (int i = 0; i < N; i++) {
        items.push_back(A[i]);
    }

    std::vector<int> current;
    findCombinations(items, K, current, 0);
}


/*
int main() {
    std::vector<int> items = {6, 8, 9};
    int K = 17;

    std::vector<int> current;
    findCombinations(items, K, current, 0);

    return 0;
}
*/