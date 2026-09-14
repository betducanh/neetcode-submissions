class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            int cur = i;
            while (cur > 0) {
                if (cur % 2) count++;
                cur /= 2;
            }
            res.push_back(count);
        }
        return res;
    }
};
