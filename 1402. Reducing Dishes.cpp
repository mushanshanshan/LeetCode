class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0, N = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int cur_sum = 0, pre_sum = 0, cur_res = 0;

        for (int i=N-1; i>=0; i--) {
            cur_sum = pre_sum + satisfaction[i];
            cur_res += cur_sum;
            if (cur_res <= 0) break;
            res = max(res, cur_res);
            pre_sum = cur_sum;
        }

        return res;
    }
};