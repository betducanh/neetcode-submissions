class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int pos = 0;
        int maxSize = 0;

        for (string s : strs) maxSize = max((int)s.size(), maxSize);

        while (pos < maxSize) {
            bool check = true;
            for (string s : strs) {
                if (s[pos] != strs[0][pos]) check = false;
            }
            if (check) {
                res.push_back(strs[0][pos]);
                pos++;
            }
            else break;
        }
        return res;
    }
};