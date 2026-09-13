class Solution {
public:
    int appendCharacters(string s, string t) {
        int posS = 0;
        int posT = 0;
        while (posS < s.size() && posT < t.size()) {
            if (s[posS] == t[posT]) posT++;
            posS++;
        }
        return t.size() - posT ;
    }
};