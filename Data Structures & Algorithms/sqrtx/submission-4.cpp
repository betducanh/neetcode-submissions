class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;
        int left = 1;
        int right = x;
        while (true) {
            int mid = (left + right) / 2;
            if (mid == x/mid || mid == left) return mid;
            if (mid > x/mid) right = mid;
            else if (mid < x/mid) left = mid;
        }
    }
};