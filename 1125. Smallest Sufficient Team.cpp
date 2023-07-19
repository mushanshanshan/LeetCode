class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skill_idx;
        int N = req_skills.size();
        for (int i=0; i<N; i++) {
            skill_idx[req_skills[i]] = i;
        }

        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << N);
        dp[0] = {};

        for (int i=0; i<people.size(); i++) {
            int cur_people = 0;
            for (auto &s: people[i]) {
                cur_people |= 1 << skill_idx[s];
            }
            for (auto it=dp.begin(); it!=dp.end(); it++) {
                int cur_skills = it->first | cur_people;
                if (dp.find(cur_skills) == dp.end() || dp[cur_skills].size() > dp[it->first].size() + 1) {
                    dp[cur_skills] = it->second;
                    dp[cur_skills].push_back(i);
                }
            }
        }

        return dp[(1 << N) - 1];
    }
};