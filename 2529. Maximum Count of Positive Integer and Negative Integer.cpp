class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int N = nums.size(), i = 0;
            int count = 0;
            while (i < N && nums[i] <= 0) {
                if (nums[i] == 0) count++;
                i++;
            }
    
            return max(i-count, N-i);
        }
    };