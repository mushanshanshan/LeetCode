class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cnt(1001,0);
        int s = 0;
        
        for (auto & trip: trips) {
            cnt[trip[1]] += trip[0];
            cnt[trip[2]] -= trip[0];
        }
        
        for (int & i: cnt) {
            s += i;
            if (s > capacity) return false;
        }
        
        return true;
        
    }
};