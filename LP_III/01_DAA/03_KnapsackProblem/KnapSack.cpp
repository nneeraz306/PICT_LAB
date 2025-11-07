#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization
    int rec(int i, vector<int> &val, vector<int> &wt, int W, vector<vector<int>>& dp) {
        // Base case: no more items
        if (i == wt.size()) return 0;

        // If already computed
        if (dp[i][W] != -1) return dp[i][W];

        // Option 1: Do not take the item
        int notTake = rec(i + 1, val, wt, W, dp);

        // Option 2: Take the item (if weight allows)
        int take = 0;
        if (wt[i] <= W) {
            take = val[i] + rec(i + 1, val, wt, W - wt[i], dp);
        }

        // Store and return the best of both choices
        return dp[i][W] = max(take, notTake);
    }

    // Function to initialize dp and start recursion
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int>(W + 1, -1));
        return rec(0, val, wt, W, dp);
    }
};

int main() {
    // Static test input
    int W = 4;                      // Maximum weight capacity
    vector<int> val = {1, 2, 3};    // Values of items
    vector<int> wt  = {4, 5, 1};    // Weights of items

    Solution obj;
    int maxValue = obj.knapsack(W, val, wt);

    cout << "Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]" << endl;
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
