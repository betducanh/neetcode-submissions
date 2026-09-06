class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        multiset<int> hihi;
        for (int i : nums) hihi.insert(i);
        for (int i : nums) if (hihi.count(i) > 1) return true;
        return false;
    }
};