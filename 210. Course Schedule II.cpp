class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        vector<int> indegree(numCourses, 0);
        vector<int> res;
        
        for (auto& i: prerequisites) {
            graph[i[0]][i[1]] = true;
            indegree[i[0]]++;
        }
        
        queue<int> q;
        
        for (int i=0; i<indegree.size(); i++) {
            if (!indegree[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            
            for (int i=0; i<numCourses; i++) {
                if (graph[i][cur]) {
                    indegree[i]--;
                    if (!indegree[i]) {
                        q.push(i);
                    }
                }
                
            }
        }
        
        for (int &i: indegree) {
            if (i) return vector<int>();
        }
        
        return res;
        
    }
};