class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int res = 0, n = heights.size();
        
        for (int i=0; i<heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                int len = st.empty() ? i : i - st.top() - 1;
                res = max(res, heights[cur] * len);
            }
            st.push(i);
        }
        
        return res;
    }
};