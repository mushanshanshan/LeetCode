class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<int, int> diff_counter;
        int N = nums.size();

        for (int i=0; i<N; i++) {
            res += i;
            res -= diff_counter[nums[i] - i];
            diff_counter[nums[i] - i]++;
        }

        return res;
    }
};