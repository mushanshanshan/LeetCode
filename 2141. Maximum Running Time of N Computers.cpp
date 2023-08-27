class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end(), std::greater<int>());
        long long sum = accumulate(batteries.begin(), batteries.end(), 0L);
        int cur = 0;
        while (batteries[cur] > (sum / n)) {
            sum -= batteries[cur];
            cur++;
            n--;
        }

        return sum / n;
    }
};