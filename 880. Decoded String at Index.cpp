class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long exp = 0, cur = 0;

        while (exp < k) {
            if (isdigit(s[cur])) {
                exp *= (s[cur] - '0');
            } else {
                exp++;
            }
            cur++;
        }

        while (cur--) {
            if (isdigit(s[cur])) {
                exp /= (s[cur] - '0');
                k %= exp;
            } else if (k % exp-- == 0) {
                return string(1, s[cur]);
            }
                
        }



        return "test";
    }
};