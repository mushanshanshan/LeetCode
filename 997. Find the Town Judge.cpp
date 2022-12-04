class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n+1, 0);
        
        for (auto & a: trust) {
            cnt[a[1]]++;
            cnt[a[0]]--;
        }
        
        for (int i=1; i<n+1; i++) if (cnt[i] == n - 1) return i;
        
        return -1;
    }
};