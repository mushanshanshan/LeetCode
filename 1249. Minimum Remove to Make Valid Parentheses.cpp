class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> left;
        string res = "";
        int N = s.size();

        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                left.push(i);
                s[i] = '-';
            } else if (s[i] == ')') {
                if (left.empty()) s[i] = '-';
                else {
                    s[left.top()] = '(';
                    left.pop();
                }
            }
        }

        for (char c: s) if (c != '-') res.push_back(c);

        return res;
    }
};