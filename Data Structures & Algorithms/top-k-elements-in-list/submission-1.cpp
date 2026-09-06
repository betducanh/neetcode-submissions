class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> frequency;
        int bestFrequency = 0;

        for (int i : nums) {
            frequency[i]++;
            if (frequency[i] > bestFrequency) bestFrequency = frequency[i];
        }

        vector<int> result;
        int count = 0;

        while (bestFrequency && count < k) {
            for (int i = 0; i < nums.size(); i++) if (count < k) {
                int current = nums[i];
                
                if (frequency[current] == bestFrequency) {
                    count++;
                    result.push_back(current);
                    while(nums[i] == current) i++;
                    i--;
                }
            }
            bestFrequency--;
        }
        return result;
    }
};
