class Solution {
public:
    string largestGoodInteger(string num) {
        int con = 0, N = num.size(), maxn = -1, end = 0;
        string maxs = "";

        for (int i=1; i<N; i++) {
            if (num[i] == num[i-1]) {
                if (con > 0) {
                    string ms = num.substr(i-2, 3);
                    if (ms > maxs) {
                        maxs = ms;
                    }
                } else con++;
            } else con = 0;
        }

        return maxs;
    }
};