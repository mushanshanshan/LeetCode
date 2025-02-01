class Solution {

public:
    bool isArraySpecial(vector<int>& nums) {
        int pre = -1;
        for (int n: nums) {
            if (pre == n % 2) return false;
            pre = n % 2;
        }

        return true;
    }
};