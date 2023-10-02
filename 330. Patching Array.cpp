class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long max_reach = 0;
        int res = 0, i = 0;

        while (max_reach < n) {

            if (i < nums.size() && max_reach + 1 >= nums[i]) {
                max_reach += nums[i++];
            } else {
                max_reach += (max_reach + 1);
                res++;
            }
        }

        return res;
    }
};