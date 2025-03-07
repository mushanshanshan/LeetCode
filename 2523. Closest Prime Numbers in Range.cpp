class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<bool> isPrime(right+1, true);
    
            for (int i=2; i<right; i++) {
                if (i * i > right) break;
    
                if (isPrime[i]) {
                    int j = i + i;
                    while (j <= right) {
                        isPrime[j] = false;
                        j += i;
                    }
                }
            }
    
            int min_dist = INT_MAX, pre_prime = -1;
            vector<int> res = {-1, -1};
    
            for (int i=max(2, left); i<=right; i++) {
                if (isPrime[i]) {
                    if (pre_prime >= 0 && i - pre_prime < min_dist) {
                        min_dist = i - pre_prime;
                        res[1] = i;
                        res[0] = pre_prime;
                    }
                    pre_prime = i;
                }
            }
    
            return res;
        }
    };