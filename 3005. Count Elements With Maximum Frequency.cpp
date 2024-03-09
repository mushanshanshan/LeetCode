class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> counter(101, 0);
        for (int i: nums) counter[i]++;
        int max_frq = 0, res = 0;
        for (int i: counter) {
            if (i > max_frq) {res = i; max_frq = i;}
            else if (i == max_frq) res += i;
        }
        return res;
    }
};