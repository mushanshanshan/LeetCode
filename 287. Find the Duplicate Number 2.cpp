class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        for (int i=0; i<N; i++) {
            int idx = (nums[i]-1) % 100000;
            if (nums[idx] > 100000) return idx+1;

            nums[idx] += 100000;
        }

        return -1;
    }
};1658. Minimum Operations to Reduce X to Zero