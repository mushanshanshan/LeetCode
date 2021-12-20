class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, 0);
        queue<int> q;
        
        for (int i=0; i<n; i++) {
            if (color[i]) continue;
            
            color[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int k : graph[cur]) {
                    if (color[k] == 0) {
                        q.push(k);
                        color[k] = color[cur] == 1? 2 : 1;
                    } else if (color[k] == color[cur]) {
                        return false;
                    }

                }
            }
        }
        return true;
        
    }
};