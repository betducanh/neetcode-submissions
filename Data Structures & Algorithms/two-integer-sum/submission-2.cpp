class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ahihi;
        for (int i = 0; i < (int)nums.size(); i++) {
            int need = target - nums[i];
            if (ahihi.count(need)) return {ahihi[need], i};
            ahihi[nums[i]] = i;
        }
        return {};
    }
};
