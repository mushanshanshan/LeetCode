class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int N = nums.size(), s = nums[0];
        vector<int> res(N, 0);

        for (int i: nums) {
            res[0] += i - s;
        }

        for (int i=1; i<N; i++) {
            int g = nums[i] - nums[i-1];
            res[i] = res[i-1] + i * g - (N - i) * g;
        }

        return res;
    }
};