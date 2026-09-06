class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = right;

        while (right >= left) {
            int speed = (right+left)/2;
            long long total = 0;
            for (int p : piles) total += (p+speed-1)/speed;

            if (total <= h) {
                res = speed;
                right = (right+left)/2-1;
            } else {
                left = (right+left)/2+1;
            }
        }

        return res;
    }
};
