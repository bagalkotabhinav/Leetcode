class MinStack {
public:
    stack<int> st, mst;
    MinStack() {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    }
    
    void push(int val) {
        st.push(val);
        if(!mst.empty()){
            val=min(val,mst.top());
            mst.push(val);
        }
        else{
            mst.push(val);
        }
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
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