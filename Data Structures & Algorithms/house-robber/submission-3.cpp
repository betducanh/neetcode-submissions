class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        dp[0] = nums[0];
        
        if (n == 1) return dp[0];
        if (n >= 2) dp[1] = max(nums[1], nums[0]);

        for (int i = 2; i <= n; i++) {
            if (i == n) {
                dp[i] = max(dp[i-1], dp[i-2]);
                break;
            }

            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n];
    }
};
