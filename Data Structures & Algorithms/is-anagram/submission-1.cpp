class Solution {
public:
    bool isAnagram(string s, string t) {
        int sizeS = s.size(), sizeT = t.size();
        multiset<char> setS, setT;
        if (sizeS != sizeT) return false;

        for (char c : s) setS.insert(c);
        for (char c : t) setT.insert(c);

        for (char c : s) if (setS.count(c) != setT.count(c)) return false;

        return true;
    }
};
