class Solution {
private:
    long com(long a, long b) {
        return a * INT_MAX + b;
    }

    int gcd(int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0, N = points.size();

        if (N == 1) return 1;

        for (int i=0; i<N-res; i++) {
            unordered_map<long, int> count;
            int dup = 1, ix = points[i][0], iy = points[i][1];

            for (int j=i+1; j<N; j++) {
                int jx = points[j][0], jy = points[j][1];
                if (ix == jx && iy == jy) dup++;
                else {
                    int dx = jx - ix, dy = jy - iy, g = gcd(dx, dy);
                    count[com((long)dx/g, (long)dy/g)]++;
                }
            }

            for (auto it: count) res = max(res, it.second + dup);
        }
        
        return res;
    }
};