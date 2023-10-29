#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Memoization table to store results of subproblems
vector<vector<int>> memo;

// Function to solve the 0/1 knapsack problem
int knapsack(vector<int>& values, vector<int>& weights, int n, int weight_left) {
    // Base case
    if (n == 0 || weight_left == 0) {
        return 0;
    }

    // If the result is already memoized, return it
    if (memo[n][weight_left] != -1) {
        return memo[n][weight_left];
    }

    // If the current item's weight exceeds the remaining capacity, skip it
    if (weights[n - 1] > weight_left) {
        memo[n][weight_left] = knapsack(values, weights, n - 1, weight_left);
    } else {
        // Maximize value by either including or excluding the current item
        int include_item = values[n - 1] + knapsack(values, weights, n - 1, weight_left - weights[n - 1]);
        int exclude_item = knapsack(values, weights, n - 1, weight_left);
        memo[n][weight_left] = max(include_item, exclude_item);
    }

    return memo[n][weight_left];
}

int main() {
    int n; // Number of items
    cin >> n;

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int weight_capacity;
    cin >> weight_capacity; // Knapsack weight capacity

    // Initialize memoization table
    memo.assign(n + 1, vector<int>(weight_capacity + 1, -1));

    int max_value = knapsack(values, weights, n, weight_capacity);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}
