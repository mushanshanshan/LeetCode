class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0;
        long long m = n;
        vector<int> degree(n, 0);

        for (auto &r: roads) {
            degree[r[0]]++;
            degree[r[1]]++;
        }

        sort(degree.begin(), degree.end(), greater<int>());

        for (int d: degree) {
            res += m-- * d;
        }

        return res;
    }
};