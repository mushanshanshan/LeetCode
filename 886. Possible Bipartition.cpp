class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(N + 1);
        for (auto dislike : dislikes) {
            g[dislike[0]].push_back(dislike[1]);
            g[dislike[1]].push_back(dislike[0]);
        }
        vector<int> colors(N + 1);
        for (int i = 1; i <= N; ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            while (!q.empty()) {
                int t = q.front(); q.pop();
                for (int cur : g[t]) {
                    if (colors[cur] == colors[t]) return false;
                    if (colors[cur] == 0) {
                        colors[cur] = -colors[t];
                        q.push(cur);
                    }
                }
            }
        }
        return true;
    }
};