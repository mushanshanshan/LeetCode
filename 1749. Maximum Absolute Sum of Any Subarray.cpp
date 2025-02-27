class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int max_prefix = 0, max_prefix_idx = -1;
            int min_prefix = 0, min_prefix_idx = -1;
    
            int s = 0, N = nums.size();
            for (int i=0; i<N; i++) {
                s += nums[i];
                if (s > max_prefix) {
                    max_prefix = s;
                    max_prefix_idx = i;
                }
                if (s < min_prefix) {
                    min_prefix = s;
                    min_prefix_idx = i;
                }
            }
    
            if (min_prefix_idx == max_prefix_idx) return 0;
            else return max_prefix - min_prefix;
        }
    };