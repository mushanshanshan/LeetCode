class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long wait_sum = 0, cur_wait = 0;

        for (auto a: customers) {
            cur_wait = max(cur_wait, long(a[0])) + a[1];
            wait_sum += cur_wait - a[0];
        }

        return double(wait_sum) / customers.size();
    }
};