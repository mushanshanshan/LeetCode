class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> cur = {0,0};
        int d = 0;
        
        for (int i=0; i<4; i++) {
            for (char c: instructions) {
                if (c == 'G') {
                    cur[0] += dir[d][0];
                    cur[1] += dir[d][1];
                } else if (c == 'R') {
                    d = (d + 1) % 4;
                } else {
                    d -= 1;
                    if (d < 0) d = 3;
                }
            }
            if (cur[0] == 0 && cur[1] == 0) return true;
        }
        
        return false;
    }
};