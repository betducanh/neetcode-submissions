class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> change;
        for (int bill : bills) {
            if (bill == 5)
                change[5]++;
            else if (bill == 10) {
                if (change[5] <= 0) return false;
                else {
                    change[5]--;
                    change[10]++;
                }
            }
            else {
                if ((change[5] < 3) && !(change[10] >= 1 && change[5] >= 1)) return false;
                else {
                    if (change[10] >= 1 && change[5] >= 1) {
                        change[10]--;
                        change[5]--;
                    } else change[5] = change[5] - 3;
                }
            }
        }
        return true;
    }
};