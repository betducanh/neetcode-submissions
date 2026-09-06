class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;

        int totalWater = 0;
        int maxHeight = -1;

        for (int i : height) maxHeight = max(maxHeight, i);

        for (int h = 1; h <= maxHeight; h++) {
            int left = 0, right = 0;
            
            while (height[left] < h || (height[left] >= h && height[left+1] >= h)) {
                left++;
                if (left >= n-2) break;
            }

            if (left >= n-2) continue;
            else right = left+2;

            while (right < n) {
                if (height[right] >= h) {
                    totalWater += right-left-1;
                    while (right < n && height[right] >= h) right++;
                    if (right == n) break;
                    left = right-1;
                }

                else right++;
            }
        }

        return totalWater;
    }
};
