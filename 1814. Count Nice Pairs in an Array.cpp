class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int N = nums.size(), res = 0, MOD = 1e9+7;
        unordered_map<int, int> re_nums;

        for (int i=0; i<N; i++) {
            int temp = nums[i], re = 0;
            while (temp > 0) {
                re = re * 10 + temp % 10;
                temp /= 10;
            }
            res += re_nums[nums[i] - re];
            res %= MOD;
            re_nums[nums[i] - re]++;
        }

        return res;
    }
};