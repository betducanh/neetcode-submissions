class Solution {
public:
    int getPos(char& c, string& order) {
        for (int i = 0; i < order.size(); i++) {
            if (c == order[i]) return i;
        }
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 1; i < words.size(); i++) {
            string curWord = words[i];
            string prevWord = words[i-1];

            int pos = 0;
            while (pos < curWord.size() && pos < prevWord.size()) {
                if (curWord[pos] == prevWord[pos]) {
                    ++pos;
                    continue;
                }
                if (getPos(curWord[pos], order) < getPos(prevWord[pos], order))
                    return false;
                break;
            }
            if (pos == curWord.size() && curWord.size() < prevWord.size()) return false;
        }
        return true;
    }
};