class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> check;
        for (int i : nums) {
            check[i]++;
            if (check[i] > size/2) return i;
        }

    }
};