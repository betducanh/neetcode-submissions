class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size+1, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= size; i++) {
            if (i == size) {
                dp[i] = min(dp[i-1], dp[i-2]);
                break;
            }

            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return dp[size];
    }
};
