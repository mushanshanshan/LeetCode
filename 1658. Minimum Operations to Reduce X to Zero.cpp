class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0) - x;
        int N = nums.size();

        if (sum == 0) return N;
        if (sum < 0) return -1;

        int end = 0, start = 0;
        int cur = 0, res = -1;

        for (; end < N; end++) {
            if (cur < sum) cur += nums[end];

            while (cur >= sum) {
                if (cur == sum) res = max(res, end - start + 1);
                cur -= nums[start++];
            }
        }

        return res == -1? res: N - res;
    }
};1093. Statistics from a Large Sample