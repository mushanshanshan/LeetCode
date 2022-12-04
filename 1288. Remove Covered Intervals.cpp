class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0]? a[1] > b[1]: a[0] < b[0];
    }
    
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), res = n, right = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        
        for (auto &v: intervals) {
            if (v[1] <= right) res--;
            else right = max(right, v[1]);
        }
        
        return res;
    }
};