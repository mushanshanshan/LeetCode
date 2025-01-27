class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_set<int> terminal;
        int N = graph.size();
        queue<int> q;

        for (int i=0; i<N; i++) {
            if (graph[i].size() == 0) terminal.insert(i);
            else q.push(i);
        }

        while (!q.empty()) {
            int init_q_size = q.size();
            
            for (int i=0; i<init_q_size; i++) {
                int cur = q.front(), out = 0;
                q.pop();
                for (int j: graph[cur]) if (!terminal.contains(j)) out++;
                if (out == 0) terminal.insert(cur);
                else q.push(cur);
            }
            if (q.size() == init_q_size) break;
        }

        vector<int> res(terminal.begin(), terminal.end());
        sort(res.begin(), res.end());

        return res;
    }
};