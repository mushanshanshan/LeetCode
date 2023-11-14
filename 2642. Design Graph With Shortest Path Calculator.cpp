class Graph {
private:
    vector<vector<int>> G;
    int N;

public:
    Graph(int n, vector<vector<int>>& edges): G(n, vector<int>(n, -1)) {
        N = n;
        for (auto e: edges) G[e[0]][e[1]] = e[2];
    }
    
    void addEdge(vector<int> e) {
        G[e[0]][e[1]] = e[2];
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> visited(N, false);
        auto comp = [](pair<int, int> &a, pair<int, int>&b) {return a.first > b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.push({0, node1});

        while (!pq.empty()) {
            auto cur = pq.top();
            visited[cur.second] = true;
            // printf("%d-%d\n", cur.first,cur.second);
            if (cur.second == node2) return cur.first;
            pq.pop();
            for (int i=0; i<N; i++) {
                if (!visited[i] && G[cur.second][i] != -1) {
                    pq.push({cur.first + G[cur.second][i], i});
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */