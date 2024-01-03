class MinStack {
public:
    vector<int> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        reverse(stack.begin(),stack.end());
        int res = stack[0];
        reverse(stack.begin(), stack.end());
        return res;
    }
    
    int getMin() {
        vector<int> tempStack = stack;
        sort(tempStack.begin(),tempStack.end());
        return tempStack[0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */