class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());

        while (stones.size() > 0) {
            int size = stones.size();
            if (stones.size() == 1) return stones[0];
            
            if (stones[size-1] == stones[size-2]) {
                stones.pop_back();
                stones.pop_back();
            } else {
                int temp = abs(stones[size-1]-stones[size-2]);
                stones.pop_back();
                stones.pop_back();
                stones.push_back(temp);
            }

            sort(stones.begin(), stones.end());
        }

        return 0;
    }
};
