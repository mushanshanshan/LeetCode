class Solution {
private:
    vector<vector<int>> graph;
    vector<int> subTree;
    vector<int> res;
    int N;

    void postOrder(int cur, int pre) {
        for (int i: graph[cur]) {
            if (i == pre) continue;
            postOrder(i, cur);
            subTree[cur] += subTree[i];
            res[cur] += subTree[i] + res[i];
        }
    }

    void preOrder(int cur, int pre) {
        for (int i: graph[cur]) {
            if (i == pre) continue;
            res[i] = res[cur] - subTree[i] + N - subTree[i];
            preOrder(i, cur);
        }
    }


public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.assign(n, vector<int>());
        res.assign(n, 0);
        subTree.assign(n, 1);
        N = n;

        for (auto e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        postOrder(0, -1);
        preOrder(0, -1);

        return res;
    }
};