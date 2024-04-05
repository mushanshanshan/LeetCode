class Solution {
private:
    int diff = abs('A' - 'a');

public:
    string makeGood(string s) {
        stack<char> st;
        string res = "";

        for (char c: s) {
            if (st.empty() || abs(st.top() - c) != diff) {
                st.push(c);
            } else {
                st.pop();
            }
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};