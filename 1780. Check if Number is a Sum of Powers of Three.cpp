class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n > 1 && n % 3 != 2) {
                if (n % 3 == 1) n--;
                n /= 3;
            }
    
            return n == 1;
        }
    };