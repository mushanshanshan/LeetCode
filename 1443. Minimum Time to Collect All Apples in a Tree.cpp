class Solution {
private:
    vector<vector<int>> child;

    int tr(int cur, int pre, vector<bool>& hasApple){
        int cost = 0, N = child[cur].size();
        for (int i = 0; i<N; i++) {
            if (child[cur][i] != pre) cost += tr(child[cur][i], cur, hasApple);
        }

        if (cur != 0 && (cost > 0 || hasApple[cur])) cost++;

        printf("%d:%d\n", cur, cost);

        return cost;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        child.resize(n);

        for (auto e: edges) {
            child[e[0]].push_back(e[1]);
            child[e[1]].push_back(e[0]);
        }

        return tr(0, -1, hasApple) * 2;
    }
};