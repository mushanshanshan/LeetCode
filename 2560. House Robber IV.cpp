class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int l = 0, r = 1e9;
            int N = nums.size();
    
            while (l < r) {
                int m = (l + r) / 2;
                int count = 0;
                for (int i=0; i<N; i++) {
                    if (nums[i] <= m) {
                        count++;
                        i++;
                    }
                }
                if (count >= k) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
    
            return l;
        }
    };