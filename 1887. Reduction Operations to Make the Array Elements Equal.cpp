class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> counter;
        vector<int> keys;
        int res = 0, cuu = 0;

        for (int n: nums) counter[n]++;
        for (auto a: counter) keys.push_back(a.first);
        sort(keys.begin(), keys.end());
        int N = keys.size();

        for (int i=N-1; i>0; i--) {
            cuu += counter[keys[i]];
            res += cuu;
        }

        return res;
    }
};