class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s, index;
        vector<int> res(temperatures.size(), 0);
        
        for (int i=0; i<temperatures.size(); i++) {
            if (s.empty() || s.top()>=temperatures[i]) {
                s.push(temperatures[i]);
                index.push(i);
            } else {
                while (!s.empty() && s.top() < temperatures[i]) {
                    s.pop();
                    res[index.top()] = i - index.top();
                    index.pop();
                }
                s.push(temperatures[i]);
                index.push(i);
            }
        }
        
        return res;
        
    }
};