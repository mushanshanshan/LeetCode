class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int l = 0, r = 1e7;
            while (l < r) {
                long long s = 0;
                long m = (l + r + 1) / 2;
                for (int c: candies) s += c / m;
                if (s < k) r = m - 1;
                else l = m;
            }
    
            return l;
        }
    };