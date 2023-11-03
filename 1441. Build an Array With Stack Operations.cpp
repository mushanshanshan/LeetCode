class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 0, N = target.size();
        vector<string> res;

        for (int i=1; i<=n; i++) {
            res.push_back("Push");
            if (i == target[cur]) {
                cur++;
                if (cur == N) return res;
            } else {
                res.push_back("Pop");
            }
        }

        return res;
    }
};