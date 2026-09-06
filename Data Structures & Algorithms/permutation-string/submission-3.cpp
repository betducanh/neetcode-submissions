class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> checker;
        unordered_map<char, int> cur;
        bool gud = true;

        if (s2.size() < s1.size()) return false;

        for (char c : s1) checker[c]++;
        for (int i = 0; i < s1.size(); i++) {
            cur[s2[i]]++;
            if (cur[s2[i]] != checker[s2[i]]) gud = false;
        }

        if (gud) return true;

        for (int i = 1; i <= s2.size() - s1.size(); i++) {
            gud = true;
            cur[s2[i-1]]--;
            cur[s2[i+s1.size()-1]]++;

            for (int j = i; j < i+s1.size(); j++) {
                if (cur[s2[j]] != checker[s2[j]]) {
                    gud = false;
                    break;
                }
            }

            if (gud) return true;
        }

        return false;
    }
};
