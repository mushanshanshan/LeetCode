class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int res = 0, pre = -1;
        for (auto& a: points){
            if (res != 0 && a[0] <= pre) continue;
            pre = a[1];
            res++;
        }

        return res;
    }
};