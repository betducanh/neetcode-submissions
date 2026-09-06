class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1 || !nums.size()) return nums.size();

        sort(nums.begin(), nums.end());

        int leftValue = nums[0];
        int rightValue = nums[0];

        int prev = nums[0];
        int best = 1;

        for (int i : nums) {
            rightValue = i;
            if (rightValue == prev) continue;

            else if (rightValue - prev == 1) {
                if (rightValue-leftValue+1 > best) best = rightValue-leftValue+1;
                prev = rightValue;
                continue;
            }

            else {
                leftValue = rightValue;
                prev = rightValue;
                continue;
            }
        }

        return best;
    }
};
