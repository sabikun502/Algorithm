#include<bits/stdc++.h>
using namespace std;
int knapsack(int values[], int weights[], int W, int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    int values[n], weights[n];
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    int maxValue = knapsack(values, weights, W, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}
