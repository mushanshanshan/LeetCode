class Solution {
public:
    string reverseParentheses(string s) {
        queue<char> q;
        deque<char> dq;
        string res = "";

        for (char c: s) {
            if (c == '(') {
                dq.push_back(c);
            } else if (c == ')') {
                while (dq.back() != '(') {
                    q.push(dq.back());
                    dq.pop_back();
                }
                dq.pop_back();
                while (!q.empty()) {
                    dq.push_back(q.front());
                    q.pop();
                }
            } else dq.push_back(c);
        }

        while (!dq.empty()) {
            res += dq.front();
            dq.pop_front();
        }

        return res;
    }
};