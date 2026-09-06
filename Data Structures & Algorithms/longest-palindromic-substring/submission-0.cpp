class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string res = "";

        for (int l = 0; l < s.size(); l++) {
            for (int r = s.size() - 1; r >= l; r--) {
                if (r - l + 1 <= res.size()) break;

                string cur = s.substr(l, r - l + 1);
                if (isPalindrome(cur)) {
                    res = cur;
                    break;
                }
            }
        }

        return res;
    }
};
