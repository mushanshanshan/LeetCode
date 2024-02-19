class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> high_diff;
        int res = 0, cur = 0, N = heights.size();


        while (bricks >= 0 && ladders >= 0 && cur < N-1) {
            if (ladders > 0) {
                high_diff.push(max(0, heights[cur+1] - heights[cur]));
                ladders--;
                cur++;
                res++;
            } else {
                high_diff.push(max(0, heights[cur+1] - heights[cur]));
                // printf("%d-%d-%d\n", cur, bricks, high_diff.top());
                if (bricks >= high_diff.top()) {
                    bricks -= high_diff.top();
                    high_diff.pop();
                    cur++;
                    res++;
                } else break;
            }
        }

        return res;
    }
};