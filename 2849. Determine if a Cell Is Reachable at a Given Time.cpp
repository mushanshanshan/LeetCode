class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dist = max(abs(fx - sx), abs(fy - sy));
        if (dist == 0) return t != 1;
        else return dist - t <= 0;
    }
};