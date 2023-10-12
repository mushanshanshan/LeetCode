class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size(), res = N, r = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(begin(nums), end(nums)), end(nums));

        

        for (int l=0; l<nums.size(); l++) {
            while (r < nums.size() && nums[r] < nums[l] + N) r++;
            res = min(res, N - (r - l));
        }

        return res;
    }
};