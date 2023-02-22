class Solution {
private:
    int checkShip(vector<int>& weights, int capacity) {
        int nShip = 1, curShip = 0;

        for (int i: weights) {
            curShip += i;
            if (curShip > capacity) {
                nShip++;
                curShip = i;
            }
        }

        return nShip;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;

        for (int w: weights) {
            l = max(l, w);
            r += w;
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            if (checkShip(weights, m) > days) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;

    }
};