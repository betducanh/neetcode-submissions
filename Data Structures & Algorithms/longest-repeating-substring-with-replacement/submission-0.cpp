class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n <= 1) return n;

        int best = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            int currentBest = 0;

            for (int j = i; j < n; j++) {
                char c = s[j];
                freq[c]++;
                currentBest = max(freq[c], currentBest);
                if ((j-i+1)-currentBest <= k) {
                    best = max(best, j-i+1);
                }
            }
        }
        
        return best;
    }
};
