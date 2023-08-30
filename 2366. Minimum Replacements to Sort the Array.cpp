class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int N = nums.size() - 1, upper = nums[N];

        for (int i=N-1; i>=0; i--) {
            int op = (nums[i] + upper - 1) / upper;
            upper = nums[i] / op;
            res += op - 1;
        }

        return res;
    }
};