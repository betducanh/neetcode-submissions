class MinStack {
private:
    stack<int> stack;
    int min = INT_MAX;
    unordered_map<int, int> frequency;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        frequency[val]++;
        if (min > val) min = val;
    }
    
    void pop() {
        frequency[top()]--;

        if (!frequency[min]) {
            int temp = INT_MAX;
            for (auto pt = frequency.begin(); pt != frequency.end(); pt++) {
                if (pt->second && pt->first < temp) temp = pt->first;
            }
            min = temp;
        }
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min;
    }
};
