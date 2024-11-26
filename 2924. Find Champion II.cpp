class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n, 0);
        int res = -1;

        for (auto &e: edges) {
            in_degree[e[1]]++;
        }

        for (int i=0; i<n; i++) {
            if (in_degree[i] == 0) {
                if (res == -1) res = i;
                else return -1;
            }
        }

        return res;
    }
};