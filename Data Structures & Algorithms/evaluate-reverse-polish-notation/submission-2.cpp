class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ourStack;

        for (string strs : tokens) {
            if (strs == "+" || strs == "-" || strs == "*" || strs == "/") {
                int num1 = ourStack.top();
                ourStack.pop();
                int num2 = ourStack.top();
                ourStack.pop();
                if (strs == "+") {
                    ourStack.push(num2+num1);
                }
                else if (strs == "-") {
                    ourStack.push(num2-num1);
                }
                else if (strs == "*") {
                    ourStack.push(num2*num1);
                }
                else if (strs == "/") {
                    ourStack.push(num2/num1);
                }
            } else {
                ourStack.push(stoi(strs));
            }
        }

        return ourStack.top();
    }
};
