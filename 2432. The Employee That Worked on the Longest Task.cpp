class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max_time = 0, res = 0, pre = 0;

        for (auto a: logs) {
            if (a[1] - pre > max_time) {
                max_time = a[1] - pre;
                res = a[0];
            } else if (a[1] - pre == max_time) {
                res = min(res, a[0]);
            }
            pre = a[1];
        }

        return res;

    }
};