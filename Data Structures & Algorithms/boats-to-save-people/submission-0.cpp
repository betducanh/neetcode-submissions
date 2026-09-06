class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0, right = people.size()-1;
        int total = 0;
        while (right >= left) {
            if (people[right] + people[left] <= limit) left++;
            right--;
            total++;
        }

        return total;
    }
};