class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0;

        for (int left = 0; left < prices.size(); left++) {
            for (int right = prices.size()-1; right > left; right--) {
                if (prices[right] - prices[left] > best) best = prices[right] - prices[left];
            }
        }

        return best;
    }
};
