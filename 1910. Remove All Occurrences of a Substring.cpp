class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ds = s;
        int N = s.size(), M = part.size();
        int i=0, j=0;

        for (; j<N; j++) {
            ds[i++] = s[j];
            if (i >= M && ds.substr(i - M, M) == part) i-= M;
        }

        return ds.substr(0, i);
    }
};class Solution {

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
                    sum_map[s][1] = backup;
                }
            }
        }

        for (auto& [k, v]:sum_map) {
            if (v.size() == 2) res = max(res, v[0] + v[1]);
        }

        return res;
    }
};