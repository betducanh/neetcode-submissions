class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res(n, 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < n; i++) {
            int t = temperatures[i];

            while (!stack.empty() && t > stack.top().first) {
                int hihi = stack.top().second;
                stack.pop();
                res[hihi] = i - hihi;
            }

            stack.push({t, i});
        }
        return res;
    }
};
