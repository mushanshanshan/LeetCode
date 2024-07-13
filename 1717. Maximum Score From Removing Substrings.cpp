class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        stack<char> sa, sb;
        pair<char, char> pior{'a', 'b'};

        if (y > x) {
            swap(pior.first, pior.second);
            swap(x, y);
        }

        for (char c: s) {
            if (c == pior.second && !sa.empty() && sa.top() == pior.first) {
                res += x;
                sa.pop();
            } else sa.push(c);
        }

        swap(pior.first, pior.second);

        while (!sa.empty()) {
            while (!sa.empty() && !sb.empty() && sa.top() == pior.first && sb.top() == pior.second) {
                res += y;
                sa.pop();
                sb.pop();
            }
            if (!sa.empty()) {
                sb.push(sa.top());
                sa.pop();
            }
        }

        return res;
    }
};