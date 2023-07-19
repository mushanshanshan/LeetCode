class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int end = - 60000, cur = 0;

        sort(intervals.begin(), intervals.end(), cmp);

        for (auto &i: intervals) {
            if (i[0] >= end) {
                cur++;
                end = i[1];
            }
        }

        return intervals.size() - cur;
    }
};