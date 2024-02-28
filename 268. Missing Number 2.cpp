class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = 0, N = nums.size();
        for (int i=0; i<=N; i++) n += i;
        for (int i: nums) n -= i;
        return n;
    }
};