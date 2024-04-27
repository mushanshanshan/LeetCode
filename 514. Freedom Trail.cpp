class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> char_map;
        unordered_map<int, int> cur_step;
        vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>());
        int res = INT_MAX, r_size = ring.size();

        dp[1].push_back({0, 0});

        for (int i=0; i<ring.size(); i++) char_map[ring[i]].push_back(i);

        for (int i=0; i<key.size(); i++) {
            int cur_dp = i % 2;
            int pre_dp = (i + 1) % 2;
            dp[cur_dp].clear();
            cur_step.clear();
            for (auto& pre: dp[pre_dp]) {
                int pre_pos = pre.first;
                int pre_step = pre.second;
                for (int next: char_map[key[i]]) {
                    int temp_dis = max(next, pre_pos) - min(next, pre_pos);
                    int cur_dis = min(temp_dis, r_size - temp_dis) + pre_step;
                    if (cur_step.count(next) >= 1 && cur_step[next] <= cur_dis) continue;
                    else cur_step[next] = cur_dis;
                }
            }

            for (auto& it: cur_step) {
                // printf("%d: %d-%d\n", i, it.first, it.second);
                if (i < key.size() - 1) dp[cur_dp].push_back({it.first, it.second});
                else res = min(res, it.second);
            }
        }

        return res + key.size();
    }
};