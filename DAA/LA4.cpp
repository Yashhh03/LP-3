#include <iostream>
#include <vector>
using namespace std;

int knapsackDP(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }

    return dp[capacity];
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> values[i] >> weights[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = knapsackDP(capacity, weights, values, n);
    cout << "Maximum value that can be carried in the knapsack: " << maxValue << endl;

    return 0;
}
