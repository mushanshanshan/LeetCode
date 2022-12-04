class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[0] > b[0];
        else return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        
        int pre_end = -1001, count = 0;
        
        for (int i=0; i<pairs.size(); i++) {
            if (pairs[i][0] > pre_end) {
                count++;
                pre_end = pairs[i][1];
            }
        }
        
        return count;
    }
};