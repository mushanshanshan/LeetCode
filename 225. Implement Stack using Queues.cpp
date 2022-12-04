class MyStack {
public:
    queue<int> m;
    queue<int> t;
    
    MyStack() {
        
    }
    
    void push(int x) {
        m.push(x);
    }
    
    int pop() {
        int s = m.size();
        for (int i=0; i< s-1; i++){
            t.push(m.front());
            m.pop();
        }
        int temp = m.front();
        m.pop();
        while (!t.empty()){
            m.push(t.front());
            t.pop();
        }
        return temp;
    }
    
    int top() {
        return m.back();
    }
    
    bool empty() {
        return m.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */