class Solution {
private:
    vector<pair<int, int>> step = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> obs;
        int res = 0, dir = 0;
        int x = 0, y = 0;


        for (auto &a: obstacles) {
            obs[a[0]].insert(a[1]);
        }

        for (int c: commands) {
            if (c == -1) {
                dir++;
                if (dir == 4) dir = 0;
            } else if (c == -2) {
                dir--;
                if (dir == -1) dir = 3;
            } else {
                for (int i=0; i<c; i++) {
                    x += step[dir].first;
                    y += step[dir].second;
                    if (obs[x].contains(y)) {
                        x -= step[dir].first;
                        y -= step[dir].second;
                        break;
                    }
                    res = max(res, x * x + y * y);
                    // printf("%d %d\n", x, y);
                }
            }
        }

        return res;
    }
};