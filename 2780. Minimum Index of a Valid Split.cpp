class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int cur_dom = nums[0], cur_dom_count = 1;
            int N = nums.size();
    
            for (int i=1; i<N; i++) {
                if (nums[i] == cur_dom) cur_dom_count++;
                else cur_dom_count--;
                if (cur_dom_count < 0) {
                    cur_dom_count = 1;
                    cur_dom = nums[i];
                }
            }
    
            cur_dom_count = 0;
            for (int i: nums) if (i == cur_dom) cur_dom_count++;
    
            int sub_dom_count = 0;
            for (int i=0; i<N; i++) {
                if (nums[i] == cur_dom) sub_dom_count++;
                // printf("%d-%d-%d-%d\n", 2*sub_dom_count , i, 2*(cur_dom_count - sub_dom_count) , N-i);
                if (2*sub_dom_count > (i+1) && 2*(cur_dom_count - sub_dom_count) > (N-i-1)) return i;
            }
            
            return -1;
        }
    };