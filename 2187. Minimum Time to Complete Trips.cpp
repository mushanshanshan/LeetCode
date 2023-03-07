class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        const auto [min, max] = std::minmax_element(time.begin(), time.end());

        
        long long l = (long long)totalTrips * *min / time.size();
        long long r = (long long)totalTrips * *max;
        // printf("%d,%d\n", l, r);
        while(l < r) {
            long long m = l + (r - l) / 2;
            long long cur_trip = 0;

            for (auto t: time) cur_trip += m / t;

            if (cur_trip >= totalTrips) r = m;
            else l = m + 1;
            // printf("%d,%d,%d\n", l, m, r);
        }

        return l;
    }
};