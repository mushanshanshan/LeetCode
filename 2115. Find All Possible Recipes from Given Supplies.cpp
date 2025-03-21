class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int R = recipes.size();
            vector<string> res;
    
            unordered_set<string> sups;
            for (auto& a: supplies) sups.insert(a);
            
            unordered_map<string, int> rec_in_degree;
            for (auto& a: recipes) rec_in_degree[a] = 0;
    
            unordered_map<string, vector<string>> rec_graph;
    
            for (int i=0; i<R; i++) {
                for (auto& a: ingredients[i]) {
                    if (sups.find(a) == sups.end()) {
                        rec_in_degree[recipes[i]]++;
                        rec_graph[a].push_back(recipes[i]);
                    }
                }
            }
    
            queue<string> q;
            for (auto& [k,v]: rec_in_degree) {
                if (v == 0) q.push(k);
            }
    
            while (!q.empty()) {
                string cur = q.front();
                q.pop();
                res.push_back(cur);
    
                for (auto& a:rec_graph[cur]) {
                    rec_in_degree[a]--;
                    if (!rec_in_degree[a]) q.push(a);
                }
    
            }
    
            return res;
        }
    };