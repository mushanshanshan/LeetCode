class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int Q = queries.size(), N = nums.size();
            vector<int> cumulation(N + 1, 0);
            int cur_q = 0, cur_cummulation = 0;
    
            for (int i = 0; i < N; i++) {
                while (cur_cummulation + cumulation[i] < nums[i]) {
                    if (cur_q == Q) return -1;
                    int val = queries[cur_q][2];
                    if (queries[cur_q][1] < i) {
                        cur_q++;  
                        continue;
                    }
                    cumulation[max(i, queries[cur_q][0])] += val;
                    cumulation[queries[cur_q][1] + 1] -= val;
                    cur_q++;
                }
                cur_cummulation += cumulation[i];
            }
    
            return cur_q;
        }
    };
    