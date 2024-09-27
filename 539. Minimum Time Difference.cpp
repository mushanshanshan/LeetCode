class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int N = timePoints.size();
        vector<int> min_points(N);

        for (int i=0; i<N; i++) {
            min_points[i] = stoi(timePoints[i].substr(3, 2));
            min_points[i] += stoi(timePoints[i].substr(0, 2)) * 60;
        }

        sort(min_points.begin(), min_points.end());

        int res = min_points[0] + 1440 - min_points[N-1];
        for (int i=0; i<N-1; i++) res = min(min_points[i+1] - min_points[i], res);

        return res;
    }
};