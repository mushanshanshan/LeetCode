class Solution {
public:
    int calculate(string s) {
        int res = 0, flag = 1, n = s.size();
        stack<int> st;
        
        for (int i=0; i<n; i++) {
            char c = s[i];
            if (c >= '0') {
                int cur = 0;
                while (i < n && s[i] >= '0') {
                    cur = cur * 10 + (s[i++] - '0');
                }
                res += flag * cur;
                i--;
            } else if (c == '+') {
                flag = 1;
            } else if (c == '-') {
                flag = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(flag);
                res = 0;
                flag = 1;
            } else if (c == ')') {
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        
        return res;
    }
};