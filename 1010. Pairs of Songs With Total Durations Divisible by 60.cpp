class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        int res = 0;
        
        for (int& i: time) {
            cnt[i%60]++;
        }
        
        res += max(0, cnt[0] * (cnt[0] - 1) / 2);
        res += max(0, cnt[30] * (cnt[30] - 1) / 2);
        
        for (int i=1; i<30; i++) {
            res += cnt[i] * cnt[60 - i];
        }
        
        return res;
        
    }
};