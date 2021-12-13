class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long mask = 0;
        vector<int> res(2,0);
        
        for (int i: nums) {
            mask ^= i;
        }
        
        mask &= -mask;
        
        for (int i: nums) {
            if (i & mask) {
                res[0] ^= i;
            } else {
                res[1] ^= i;
            }
        }
        
        return res;
    }
};