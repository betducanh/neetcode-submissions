class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int cur = 1, prev = 0; cur < s.size(); cur++, prev++) {
            sum += abs(s[cur]-s[prev]);
        }
        return sum;
    }
};