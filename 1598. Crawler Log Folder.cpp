class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;

        for (auto &s: logs) {
            if (s == "../") res = max(0, res-1);
            else if (s == "./") continue;
            else res++;
        }

        return res;
    }
};