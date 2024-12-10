class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), M = queries.size();
        vector<int> counter(N+1, 0);
        vector<bool> res(M, true);
        int cur = 0;

        for (int i=0; i<N-1; i++) {
            if ((nums[i] + nums[i+1]) % 2 == 0) cur++;
            counter[i+1] = cur;
        }

        for (int j=0; j<M; j++) {
            if (counter[queries[j][0]] != counter[queries[j][1]]) res[j] = false;
        }

        return res;        
    }
};