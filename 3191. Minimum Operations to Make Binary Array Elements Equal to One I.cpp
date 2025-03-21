class Solution {


    public:
        int minOperations(vector<int>& nums) {
            int N = nums.size();
            int res = 0;
    
            for (int i=0; i<N; i++) {
                if (nums[i] == 0) {
                    if (i >= N-2) return -1;
                    else {
                        res++;
                        for (int j=0; j<3; j++) {
                            nums[i+j] = !nums[i+j];
                        }
                    }
    
                    // for (int n: nums) printf("%d-", n);
                    // printf("\n");
                }
            }
    
            return res;
        }
    };