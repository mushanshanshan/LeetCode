class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int N = nums.size(), min_num = 0;
        vector<vector<int>> res(N/3, vector<int>(3, 0));
        sort(nums.begin(), nums.end());

        for (int i=0; i<N; i++) {
            int c = i % 3;
            int r = i / 3;

            if (c == 0) min_num = nums[i];
            else if (c == 2 && nums[i] - min_num > k) return {};

            res[r][c] = nums[i];
        }

        return res;
    }
};