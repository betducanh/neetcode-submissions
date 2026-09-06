class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) {
            if (nums[i] > 0) break;
            if (i && nums[i] == nums[i-1]) continue;
            
            int l = i+1;
            int r = nums.size()-1;

            while (r > l) {
                int sum = nums[i]+ nums[l] + nums[r];

                if (!sum) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while (r > l && nums[l] == nums[l-1]) l++;
                }

                else if (sum < 0) {
                    l++;
                    continue;
                }

                else {
                    r--;
                    continue;
                }
            }
        }

        return result;
    }
};
