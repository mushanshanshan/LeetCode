class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> dep;
        vector<bool> res;
        
        for (auto& a: prerequisites) dep[a[1]].push_back(a[0]);

        for (auto& a: queries) {
            unordered_set<int> visited;
            queue<int> q;
            bool cur_res = false;

            q.push(a[1]);
            visited.insert(a[1]);
            while (!q.empty() && !cur_res) {
                auto& pre = dep[q.front()];
                q.pop();

                for (int p: pre) {
                    if (p == a[0]) {
                        cur_res = true;
                        break;
                    }
                    if (!visited.contains(p)) {
                        q.push(p);
                        visited.insert(p);
                    }
                }
            }
            res.push_back(cur_res);
        }

        return res;
    }
};