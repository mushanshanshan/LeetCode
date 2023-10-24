class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int res = 0;
        unordered_map<int, vector<int>> next_courses;
        vector<int> in_degree(n, 0);

        // Use a min heap, smaller time first
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {return a.first > b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (auto &r: relations) {
            next_courses[r[0]-1].push_back(r[1]-1); // 0-indexed
            in_degree[r[1]-1]++;
        }

        for (int i=0; i<n; i++) {
            if (in_degree[i] == 0) {
                pq.push({time[i], i});
            }
        }

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            res = max(res, cur.first);

            for (auto next: next_courses[cur.second]) {
                if (--in_degree[next] == 0) {
                    pq.push({res + time[next], next});
                }
            }
        }

        return res;
    }
};
