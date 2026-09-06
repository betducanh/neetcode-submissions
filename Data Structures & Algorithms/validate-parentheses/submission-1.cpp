class Solution {
public:
    bool isValid(string s) {
        vector<char> count;
        unordered_map<char, char> hihi = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for (char c : s) {
            if (c == ')' || c == '}' || c == ']') {
                if (!count.size() || count.back() != hihi[c] ) return false;
                else count.pop_back();
            }

            else {
                count.push_back(c);
            }
        }

        return count.size() == 0;
    }
};
