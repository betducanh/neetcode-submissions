class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size()-1) {
                arr[i] = -1;
                break;
            }
            int maxElement = 0;
            for (int j = i+1; j < arr.size(); j++) maxElement = max(maxElement, arr[j]);
            arr[i] = maxElement;
        }
        return arr;
    }
};