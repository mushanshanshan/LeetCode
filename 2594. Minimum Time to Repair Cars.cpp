class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long l = 0, r = 1L * ranks[0] * cars * cars;
            
            while (l < r) {
                long long m = (l + r) / 2;
                long long fixed = 0;
    
                for (int r: ranks) {
                    fixed += (long long)sqrt(m / r);
                }
    
                if (fixed < cars) l = m + 1;
                else r = m;
            }
    
            return r;
    
        }
    };