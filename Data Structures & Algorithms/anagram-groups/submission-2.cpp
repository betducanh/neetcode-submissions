class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> seen;

        for (string s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            seen[sortedS].push_back(s);
        }

        for (auto& pair : seen) {
            result.push_back(pair.second);
        }

        return result;
    }
};
