class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N = nums.size(), p = 0, n = 0, i = 0;
        vector<int> res(N, 0);

        while (p != N && n != N) {
            while(nums[p] < 0) p++;
            res[i++] = nums[p++];
            while(nums[n] > 0) n++;
            res[i++] = nums[n++];
        }

        return res;
    }
};