class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 1, cur = nums[0], N = nums.size();

        for (int i=1; i<N; i++) {
            if (counter == 0) {
                counter = 1;
                cur = nums[i];
            } else {
                counter += cur == nums[i]? 1: -1;
            }
        }

        return cur;
    }
};