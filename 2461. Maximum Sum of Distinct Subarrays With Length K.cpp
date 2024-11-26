class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, mres = 0;
        unordered_map<int, int> counter;
        int repeat_counter = 0, N = nums.size();

        for (int i=0; i<k; i++) {
            res += nums[i];
            counter[nums[i]]++;
            if (counter[nums[i]] == 2) repeat_counter++;
        }

        for (int i=k; i<N; i++) {
            if (repeat_counter == 0) mres = max(mres, res);
            res -= nums[i-k];
            res += nums[i];
            
            counter[nums[i]]++;
            if (counter[nums[i]] == 2) repeat_counter++;

            counter[nums[i-k]]--;
            if (counter[nums[i-k]] == 1) repeat_counter--;
        }

        if (repeat_counter == 0) mres = max(mres, res);

        return mres;
    }
};