class Solution {
private:
    long long res = 0;
    int N;
    long long SEATS;
    vector<vector<int>> graph;

    long long backtracking(unordered_map<int, vector<int>> &graph, int cur, int pre) {
        if (graph[cur].size() == 1 && graph[cur][0] == pre) {
            res++;
            return 1;
        }


        long long num_re = 1;

        for (auto next: graph[cur]) {
            if (next == pre) continue;
            num_re += backtracking(graph, next, cur);
        }

        if (cur != 0) {
            res += num_re / SEATS;
            if (num_re % SEATS) res++;
        }
        // printf("%d: %d-%d\n", cur, num_re, ceil(float(num_re) / SEATS));

        return num_re;
    }





public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        N = roads.size();
        SEATS = seats;
        unordered_map<int, vector<int>> graph;

        for (auto r: roads) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }

        backtracking(graph, 0, -1);
        
        return res;
    }
};