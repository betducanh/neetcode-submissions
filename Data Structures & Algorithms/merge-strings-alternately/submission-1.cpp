class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int pos1 = 0, pos2 = 0;
        string res;
        while (pos1 < word1.size() || pos2 < word2.size()) {
            if (pos1 < word1.size()) res.push_back(word1[pos1]);
            if (pos2 < word2.size()) res.push_back(word2[pos2]);
            pos1++; pos2++;
        }
        return res;
    }
};