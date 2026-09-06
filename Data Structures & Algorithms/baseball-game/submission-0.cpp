class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> result;
        for (string input : operations) {
            int size = result.size();
            if (input != "C" && input != "D" && input != "+") {
                result.push_back(stoi(input));
            }

            else if (input == "+" && size >= 2) {
                result.push_back(result[size-1] + result[size-2]);
            }

            else if (input == "C" && size >= 1) {
                result.pop_back();
            }

            else if (input == "D" && size >= 1) {
                result.push_back(result[size-1]*2);
            }
        }

        int sum = 0;
        for (int i : result) sum += i;
        return sum;
    }
};