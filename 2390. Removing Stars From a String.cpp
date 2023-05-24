class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string res = "";

        for (char c: s) {
            if (c == '*') st.pop();
            else st.push(c);
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};