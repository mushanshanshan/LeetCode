class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;

        for (int n: nums) k ^= n;
        
        while (k) {
            res += k & 1;
            k >>= 1;
        }

        return res;
    }
};