class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& t: tokens) {
            if (t == "+" || t == "*" || t == "-" || t == "/") {
                int n = st.top();
                st.pop();
                if (t == "+") n = st.top() + n;
                if (t == "-") n = st.top() - n;
                if (t == "*") n = st.top() * n;
                if (t == "/") n = st.top() / n;
                st.pop();
                st.push(n);
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};