class Solution {
public:
    string minWindow(string s, string t) {
        int bestStart = 0;
        int bestLength = INT_MAX;
        unordered_map<char,int> tChar;
        for (char c : t) tChar[c]++;

        int l = 0, r = 0;
        unordered_map<char,int> sChar;
        int valid = 0;

        while (r < s.size()) {
            sChar[s[r]]++;
            if (tChar.count(s[r]) && sChar[s[r]] <= tChar[s[r]]) valid++;

            while (valid == t.size()) {
                if (r-l+1 < bestLength) {
                    bestStart = l;
                    bestLength = r-l+1;
                }
                sChar[s[l]]--;
                if (sChar[s[l]] < tChar[s[l]]) valid--;
                l++;
            }

            r++;
        }

        return bestLength == INT_MAX ? "" : s.substr(bestStart, bestLength);
    }
};
