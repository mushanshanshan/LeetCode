class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        res.push_back({rStart, cStart});

        int dx = 0, dy = 1;
        int x = rStart, y = cStart;
        int steps = 1, counter = 1;

        while (res.size() < rows * cols) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    x += dx;
                    y += dy;

                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        res.push_back({x, y});
                    }
                }

                swap(dx, dy);
                dy = -dy;
            }
            steps++;
        }

        return res;
    }
};
