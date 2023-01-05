class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        int res = 0;
        long cur = (long)points[0][0]-1;

        for (auto a: points) {
            if (a[0] > cur) {
                res++;
                cur = a[1];
            }
        }

        return res;

    }
};