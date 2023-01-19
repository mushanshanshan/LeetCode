class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        int prefix = 0, res = 0;
        count[0] = 1;

        for (int i: nums) {
            prefix += i;
            prefix = ((prefix % k) + k) % k;
            res += count[prefix]++;
        }

        return res;
    }
};