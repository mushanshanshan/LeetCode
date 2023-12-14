class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1 = 0, p2 = 0, n1 = 0, n2 = 0;

        for (int i=0; i<nums.size(); i++) {
            int cur = nums[i]-1;
            if (cur > p2) {
                if (cur > p1) {p2 = p1; p1 = cur;}
                else p2 = cur;
            }

            if (cur < n2) {
                if (cur < n1) {n2 = n1; n1 = cur;}
                else n2 = cur;
            }
        }

        return max(p1*p2, n1*n2);
    }
};