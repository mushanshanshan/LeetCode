class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(2, 0);
        vector<int> counter(N+1, 0);

        for (int i: nums) {
            counter[i]++;
        }

        for (int i=1; i<N+1; i++) {
            if (counter[i] == 2) res[0] = i;
            else if (counter[i] == 0) res[1] = i;
        }

        return res;
    }
};