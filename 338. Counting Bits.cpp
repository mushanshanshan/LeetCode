class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);

        for (int i=1; i<n+1; i++) {
            if (i % 2 == 0) res[i] = res[i/2];
            else res[i] = 1 + res[i-1];
        }

        return res;

    }
};