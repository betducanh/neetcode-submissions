class Solution {
public:
    bool isSubsequence(string s, string t) {
        int posS = 0;
        int posT = 0;
        while (posS < s.size() && posT < t.size()) {
            if (s[posS] == t[posT]) posS++;
            posT++;
        }
        return posS == s.size();
    }
};