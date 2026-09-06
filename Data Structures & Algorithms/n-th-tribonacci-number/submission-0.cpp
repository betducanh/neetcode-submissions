class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i <= 2) dp[i] = 1;
            else {
                dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
            }
        }
        return dp[n];
    }
};