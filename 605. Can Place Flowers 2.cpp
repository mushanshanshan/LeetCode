class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c = 1;

        for (int i: flowerbed) {
            if (i == 0) {
                c++;
            } else {
                c = 0;
            }

            if (c == 3) {
                n--;
                c = 1;
            }
        }
        if (c == 2) n--;

        return n <= 0;
    }
};