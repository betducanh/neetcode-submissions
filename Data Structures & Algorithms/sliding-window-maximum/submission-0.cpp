class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int maxPos = -1;

        for (int l = 0; l+k-1 < nums.size(); l++){
            if (l > maxPos) {
                int tempPos = l;
                for (int i = l; i < l+k; i++)
                    if (nums[i] > nums[tempPos]) tempPos = i;
                maxPos = tempPos;
                res.push_back(nums[maxPos]);
                continue;
            }

            if (nums[l+k-1] > nums[maxPos]) {
                maxPos = l+k-1;
                res.push_back(nums[maxPos]);
                continue;
            }

            res.push_back(nums[maxPos]);
        }

        return res;
    }
};
