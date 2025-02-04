class Solution {
public:
    bool check(vector<int>& nums) {
        int N = nums.size();
        int decrease_count = 0;
        nums.push_back(nums[0]);

        for (int i=1; i<=N; i++) {
            if (nums[i] < nums[i-1]) decrease_count++;
        }

        return decrease_count < 2;
    }
};