class Solution {
public:
    int minLength(string s) {
        stack<char> sc;
        sc.push(' ');

        for (char c:s) {
            if (c == 'B' && sc.top() == 'A') {
                sc.pop();
            } else if (c == 'D' && sc.top() == 'C'){
                sc.pop();
            } else {
                sc.push(c);
            }
        }

        int res = -1;
        while (!sc.empty()) {
            sc.pop();
            res++;
        }

        return res;
    }
};