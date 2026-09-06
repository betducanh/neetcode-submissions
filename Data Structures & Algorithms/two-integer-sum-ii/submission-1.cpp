class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; 
        int right = numbers.size()-1;

        while (right > left) {
            int sum = numbers[right]+numbers[left];
            
            if (sum > target) {
                right--;
                continue;
            }

            if (sum < target) {
                left++;
                continue;
            }

            if (sum == target) {
                return {++left, ++right};
            }
        }
    }
};
