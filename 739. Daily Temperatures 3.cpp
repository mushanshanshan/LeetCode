class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int N = temperatures.size();
        vector<int> res(N, 0);

        for (int i=0; i<N;) {
            if (st.empty() || temperatures[i] <= st.top().second) {
                st.push({i, temperatures[i]});
                i++;
            } else {
                while (!st.empty() && st.top().second < temperatures[i]) {
                    res[st.top().first] = i - st.top().first;
                    st.pop();
                }
            }
        }

        return res;
    }
};