class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.size()*2);
        for (int i = 0; i < nums.size(); i++) {
            res[i] = nums[i];
        }

        for (int i = nums.size(); i < nums.size()*2; i++) {
            res[i] = nums[i-nums.size()];
        }
        return res;
    }
};