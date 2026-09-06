class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;

        for (int left = 0; left < s.size(); left++) {
            unordered_set<char> seen;

            for (int right = left; right < s.size(); right++) {
                if (seen.count(s[right])) {
                    break;
                }
                seen.insert(s[right]);
                best = max(best, right - left + 1);
            }
        }

        return best;
    }
};
