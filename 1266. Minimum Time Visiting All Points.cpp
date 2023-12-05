class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0, x = points[0][0], y = points[0][1];

        for (auto p: points) {
            res += max(abs(p[0]-x), abs(p[1]-y));
            x = p[0];
            y = p[1];
        }

        return res;
    }
};