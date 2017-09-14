class Solution {
public:
    stack<int> data;
    stack<int> min_stk;
    void push(int value) {
        data.push(value);
        if(min_stk.empty() || value <= min_stk.top()){
            min_stk.push(value);
        }else{
            min_stk.push(min_stk.top());
        }
    }
    void pop() {
        data.pop();
        min_stk.pop();
        return;
    }
    int top() {
        return data.top();
    }
    int min() {
        return min_stk.top();
    }
};
