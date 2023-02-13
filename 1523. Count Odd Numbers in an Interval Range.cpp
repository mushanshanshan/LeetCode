class Solution {
private:
    int numOdds(int n) {
        return n / 2 + n % 2;
    }

public:
    int countOdds(int low, int high) {
        return high / 2 + high % 2 - low / 2;
    }
};