class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<bool> visited(numCourses, false);
        vector<vector<int>> G(numCourses, vector<int>());

        for (auto &q: prerequisites) {
            G[q[0]].push_back(q[1]);
            indegree[q[1]]++;
        }

        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;

            for (int j: G[cur]) {
                if (--indegree[j] == 0) q.push(j);
            }
        }

        for (bool b: visited) {
            if (!b) return false;
        }
        return true;

    }
};