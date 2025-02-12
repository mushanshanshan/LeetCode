class Solution {

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> sum_map;
        int N = nums.size(), res = -1;

        for (int n: nums) {
            int s = 0, backup = n;
            while (n) {
                s += n % 10;
                n /= 10;
            }
            if (sum_map[s].size() == 0) sum_map[s].push_back(backup);
            else if (sum_map[s].size() == 1) {
                sum_map[s].push_back(sum_map[s][0]);
                if (backup > sum_map[s][0]) sum_map[s][0] = backup;
                else sum_map[s][1] = backup;
            } else {
                if (backup <= sum_map[s][1]) continue;
                if (backup <= sum_map[s][0]) sum_map[s][1] = backup;
                else {
                    sum_map[s][1] = sum_map[s][0];
                    sum_map[s][0] = backup;
                }
            }
        }

        for (auto& [k, v]:sum_map) {
            if (v.size() == 2) res = max(res, v[0] + v[1]);
        }

        return res;
    }
};