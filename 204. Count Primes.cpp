class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<bool> prime(n, true);
        int count = n-2, temp;
        for (int i=2; i<sqrt(n); i++) {
            if (prime[i]) {
                temp = i * i;
                while (temp < n) {
                    if (prime[temp]) {
                        prime[temp] = false;
                        count--;
                    }
                    temp += i;
                }
            }
        }
        
        return count;
    }
};