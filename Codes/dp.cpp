#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minLearningCost(vector<int>& costs, vector<int>& times, int n, int T) {
    vector<vector<int>> dp(n + 1, vector<int>(T + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int t = 0; t <= T; ++t) {
            dp[i][t] = dp[i-1][t];
            if (t >= times[i-1] && dp[i-1][t-times[i-1]] != INT_MAX) {
                dp[i][t] = min(dp[i][t], dp[i-1][t-times[i-1]] + costs[i-1]);
            }
        }
    }

    int minCost = INT_MAX;
    for (int t = 0; t <= T; ++t) {
        minCost = min(minCost, dp[n][t]);
    }

    return minCost;
}

int main() {
    vector<int> costs = {100, 200, 150};
    vector<int> times = {1, 2, 1};
    int T = 2;
    cout << "Minimum Learning Cost: " << minLearningCost(costs, times, costs.size(), T) << endl;
    return 0;
}
