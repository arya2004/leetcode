#include <iostream>
#include <vector>
using namespace std;

int maxSumNonAdjacent(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    
    // dp[i] represents the maximum sum possible up to index i
    vector<int> dp(n, 0);
    
    // Base cases
    dp[0] = arr[0];  // Take the first element
    dp[1] = max(arr[0], arr[1]);  // Take the maximum of first or second element
    
    // Fill the dp array
    for (int i = 2; i < n; i++) {
        // For each position, we can either:
        // 1. Skip the current element and take dp[i-1]
        // 2. Take the current element and add it to dp[i-2] (since we can't take adjacent elements)
        dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
    }
    
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;  // Read the size of the array
    vector<int> arr(n);
    
    // Read the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = maxSumNonAdjacent(arr);
    cout << result << endl;  // Print the maximum sum
    
    return 0;
}