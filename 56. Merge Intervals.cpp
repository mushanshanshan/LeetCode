class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return intervals;
        vector<vector<int>> result;
        int rIndex = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] <= result[rIndex][1]) {
                result[rIndex][1] = max(result[rIndex][1], intervals[i][1]);
            } else {
                rIndex++;
                result.push_back(intervals[i]);
            }
            
            
        }
        return result;
    }
};