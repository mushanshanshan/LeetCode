// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r = 49;
        
        while (r > 40) {
            r = (rand7() - 1) * 7 + rand7();
        }
        
        return r % 10 + 1;
    }
};