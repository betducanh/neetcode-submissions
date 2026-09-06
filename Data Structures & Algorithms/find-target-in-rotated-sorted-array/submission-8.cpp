class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> hihi;
        for (int i = 0; i < nums.size(); i++) hihi[nums[i]] = i;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] == target) return hihi[nums[m]];
            else if (nums[m] < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};
