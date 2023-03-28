class Solution {
private:
    vector<int> color;

    void dfs(int cur, int c, unordered_map<int, vector<int>>& g) {
        if (color[cur] != -1) return;
        color[cur] = c;
        for (int i: g[cur]) {
            dfs(i, c, g);
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int cur_color = 1;
        long long res = 0;
        color.resize(n, -1);
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> cc;

        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for (int i=0; i<n; i++) {
            if (color[i] == -1) {
                dfs(i, cur_color, g);
                cur_color++;
            }
            
            cc[color[i]]++;
        }

        for (auto nc: cc) {
            res += (long long)nc.second * (n - nc.second);
        }

        return res/2;
    }
};