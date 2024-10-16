class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> all_nums;
        int N = nums.size(), contain = 0;
        vector<int> counter(N, 0);
        vector<int> res = {0, INT_MAX};

        for (int i=0; i<N; i++) {
            for (int n: nums[i]) {
                all_nums.push_back({n, i});
            }
        }

        sort(all_nums.begin(), all_nums.end(), [](pair<int, int>& p1, pair<int, int>& p2) {return p1.first < p2.first;});
        int M = all_nums.size();
        int l = 0, r = 0;
        printf("%d\n", N);

        while (r < M) {
            counter[all_nums[r].second]++;
            if (counter[all_nums[r].second] == 1) {
                contain++;
            }

            // printf("%d-%d\n", all_nums[r].first, contain);

   
            while (contain >= N && l <= r) {
                if (all_nums[r].first - all_nums[l].first < res[1] - res[0]) {
                    // printf("%d/%d\n", l, r);
                    res[0] = all_nums[l].first;
                    res[1] = all_nums[r].first;
                }
                counter[all_nums[l].second]--;
                if (counter[all_nums[l].second] == 0) contain--;
                l++;
            }


            r++;
        }

        return res;
    }
};