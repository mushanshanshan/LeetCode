
class Solution {

public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> remain;
        int res = 0;

        for (int i: tasks) {
            remain[i] += 1;
            if (remain[i] == 5) {
                remain[i] -= 3;
                res++;
            }
        }

        for (auto it: remain) {
            if (it.second == 4) {
                res += 2;
            } else if (it.second == 1) {
                return -1;
            } else {
                res += 1;
            }
        }

        return res;
    }
};