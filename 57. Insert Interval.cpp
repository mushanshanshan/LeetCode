class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N = intervals.size(), i = 0, left = newInterval[0], right = newInterval[1];
        vector<vector<int>> res;
        int state = 0;

        while (i < N && intervals[i][1] < left) res.push_back(intervals[i++]);

        while (i < N && intervals[i][0] <= right) {
            left = min(intervals[i][0], left);
            right = max(intervals[i++][1], right);
        }

        res.push_back({left, right});
        
        while (i < N) res.push_back(intervals[i++]);

        return res;

    }
};