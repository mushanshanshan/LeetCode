class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(int i: nums) counter[i]++;

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (counter[a] == counter[b]) return a > b;
            return counter[a] < counter[b];
        });

        return nums;
    }
};