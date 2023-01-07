class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;

        for (int i: costs) {
            if (coins >= i) {
                res++;
                coins -= i;
            } else break;
        }

        return res;
    }
};