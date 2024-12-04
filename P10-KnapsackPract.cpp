#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Maximum value that can be obtained
}

int main() {
    int W = 7; // Maximum weight
    vector<int> weights = {1, 3, 4, 5}; // Weights of items
    vector<int> values = {1, 4, 5, 7}; // Values of items
    int n = weights.size();

    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
