class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size();
        int bestArea = 0;

        for (int l = 0; l < heights.size(); l++) {
            for (int r = l; r < heights.size(); r++) {
                int curArea = (r-l) * min(heights[l], heights[r]);
                if (curArea > bestArea) bestArea = curArea;
            }
        }
        return bestArea;
    }
};
