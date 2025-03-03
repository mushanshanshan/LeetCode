class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int N = nums.size();
    
            for (int i=0; i<N-1; i++) {
                if (nums[i] == nums[i+1]) {
                    nums[i] *= 2;
                    nums[i+1] = 0;
                }
            }
    
            int j = 0;
            for (int i=0; i<N; i++) {
                if (nums[i] != 0) nums[j++] = nums[i];
            }
    
            for (; j<N; j++) nums[j] = 0;
    
            return nums;
        }
    };