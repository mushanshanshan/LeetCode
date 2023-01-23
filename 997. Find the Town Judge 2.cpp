class Solution {
private:
    vector<int> in;
    vector<int> out;

public:
    int findJudge(int n, vector<vector<int>>& trust) {
        in.resize(n+1, 0);
        out.resize(n+1, 0);

        for (auto t: trust) {
            in[t[1]]++;
            out[t[0]]++;
        }

        for (int i=1; i<=n; i++) {
            if (out[i] == 0 && in[i] == n-1) return i;
        }
        
        return -1;
    }
};