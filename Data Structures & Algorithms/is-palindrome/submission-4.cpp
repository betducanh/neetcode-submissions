class Solution {
public:
    bool isPalindrome(string s) {
        string initial = "";

        for (int i = 0; i < (int)s.size(); i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z' || (s[i] >= '0' && s[i] <= '9'))) {
                if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a'-'A';
                initial.push_back(s[i]);
            }
        }

        for (int i = 0; i < (int)initial.size(); i++) {
            if (initial[i] != initial[(int)initial.size()-i-1]) return false;
        }

        return true;
    }
};
