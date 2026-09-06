class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> find;
        for (int i : nums) {
            find[i]++;
            if (find[i] > 1) return i;
        }
    }
};
