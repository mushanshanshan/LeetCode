class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size(), max_len = 0, max_idx = 0;
        vector<pair<int, int>> dp(N, {1, -1});
        vector<int> res;
        sort(nums.begin(), nums.end());

        for (int i=1; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i].first < dp[j].first + 1) {
                        dp[i] = {dp[j].first + 1, j};
                    }
                }
            }
        }

        for (int i=0; i<N; i++) {
            if (dp[i].first > max_len) {
                max_len = dp[i].first;
                max_idx = i;
            }
        }

        // printf("%d-%d\n", max_len, max_idx);

        // for (int i=0; i<N; i++) {
        //     printf("%d:%d,", dp[i].first, dp[i].second);
        // }

        while (max_idx != -1) {
            res.push_back(nums[max_idx]);
            max_idx = dp[max_idx].second;
        }

        return res;
    }
};