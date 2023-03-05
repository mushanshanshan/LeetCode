class Solution {


public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> map;
        int N = arr.size();
        vector<bool> visited(N, false);
        queue<int> q;
        int res = 0;

        for (int i=0; i<N; i++) {
            map[arr[i]].push_back(i);
        }

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int cur_size = q.size();
            res++;

            for (size_t i=0; i<cur_size; i++) {
                int cur = q.front();
                q.pop();

                if (cur == N-1) return res - 1;

                if (cur > 0 && !visited[cur - 1]) {
                    q.push(cur - 1);
                    visited[cur - 1] = true;
                }

                if (cur < N - 1 && !visited[cur + 1]) {
                    q.push(cur + 1);
                    visited[cur + 1] = true;
                }

                for (int j: map[arr[cur]]) {
                    if (!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
                map[arr[cur]].clear();

            }
        }

        return 0;
    }
};