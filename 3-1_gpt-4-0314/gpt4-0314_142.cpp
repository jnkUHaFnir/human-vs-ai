#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

const int MAX_N = 1010;
int n, arr[MAX_N];
int dp[MAX_N][MAX_N]; // cache for DP
int circularSum(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += arr[k];
        sum %= 100;
    }
    return sum;
}
int minMergeCost(int i, int j) {
    if (i == j) return 0; // base case: 1 element
    
    if (dp[i][j] != -1) {
        return dp[i][j]; // DP: retrieve precomputed cost
    }
    
    int cost = INT_MAX;
    for (int k = i; k < j; k++) {
        int tempCost = minMergeCost(i, k) + minMergeCost(k + 1, j) + circularSum(i, k) * circularSum(k + 1, j);
        cost = min(cost, tempCost);
    }
    
    dp[i][j] = cost;
    return cost;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp)); // reset DP cache
        cout << minMergeCost(0, n - 1) << endl;
    }
    return 0;
}
