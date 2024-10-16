class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int N = s.size(), counter = 0;

        for (int i=0; i<N; i++) {
            if (s[i] == '1') counter++;
            else res += counter;
        }

        return res;
    }
};