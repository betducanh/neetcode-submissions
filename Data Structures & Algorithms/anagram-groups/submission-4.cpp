class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> check;

        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            check[sorted].push_back(s);
        }

        for (auto pair : check) {
            res.push_back(pair.second);
        }

        return res;
    }
};
