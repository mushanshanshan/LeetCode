class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);

        for (int i=0; i<temperatures.size(); i++) {
            if (st.empty()) {
                st.push(i);
            } else {
                while (!st.empty() && temperatures[i]>temperatures[st.top()]) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }

        return res;

    }
};