class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int top = 0, bot = row-1;
        int midRow = (top+bot)/2;

        while (top <= bot) {
            midRow = (top+bot)/2;

            if (matrix[midRow][0] <= target && matrix[midRow][col-1] >= target) break;

            else if (matrix[midRow][0] > target) {
                bot = midRow-1;
                continue;
            }

            else if (matrix[midRow][col-1] < target) {
                top = midRow+1;
                continue;
            }
        }

        int left = 0, right = col-1;
        int midCol = (left+right)/2;

        while (left <= right) {
            midCol = (left+right)/2;

            if (matrix[midRow][midCol] == target) return true;

            else if (matrix[midRow][midCol] > target) {
                right = midCol-1;
                continue;
            }

            else if (matrix[midRow][midCol] < target) {
                left = midCol+1;
                continue;
            }
        }
        return false;
    }
};
