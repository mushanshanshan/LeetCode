class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adjlist(n);
        vector<bool> removed(n, false);
        queue<int> cur_round;
        vector<int> res;
        int counter = n;

        for (auto& e:edges) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        while (counter > 2) {
            for (int i=0; i<n; i++) {
                if (indegree[i] == 1) {
                    cur_round.push(i);
                }
            }

            while (!cur_round.empty()) {
                int i = cur_round.front();
                cur_round.pop();
                for (int a: adjlist[i]) {
                    indegree[a]--;
                }
                counter--;
                indegree[i] = 0;
                removed[i] = true;
            }
        }

        for (int i=0; i<n; i++) {
            if (!removed[i]) res.push_back(i);
        }

        return res;

    }
};