class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int target = (n + rolls.size()) * mean;
        for (int r: rolls) target -= r;
        // printf("%d\n", target);
        if (target < n || target > n * 6) return {};

        vector<int> res(n, 0);

        for (int i=0; i<n; i++) {
            res[i] = target / (n - i);
            target -= res[i];
        }

        return res;
    }
};