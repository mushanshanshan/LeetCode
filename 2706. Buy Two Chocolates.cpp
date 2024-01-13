class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int c0 = 100, c1 = 100;

        for (int p: prices) {
            if (p < c1) {
                if (p < c0) {c1 = c0; c0 = p;}
                else c1 = p;
            }
        }

        return c0 + c1 > money? money: money - c0 - c1;
    }
};