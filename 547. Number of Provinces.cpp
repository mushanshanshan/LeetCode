class Solution {
public:
    void mark(vector<vector<int>>& isConnected, int index, vector<bool>&cityMarked) {
        if (cityMarked[index]) return;
        cityMarked[index] = true;
        for (int i=0; i<isConnected.size(); i++) {
            if (isConnected[index][i] == 1 && !cityMarked[i]) {
                mark(isConnected, i, cityMarked);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        vector<bool> cityMarked(isConnected.size(), false);
        for (int i=0; i<isConnected.size(); i++) {
            if (!cityMarked[i]) {
                result++;
                mark(isConnected, i, cityMarked);
            }
        }
        return result;
    }
};