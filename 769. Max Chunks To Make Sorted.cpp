class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m = -1, count = 0;
        
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] > m) m = arr[i];
            if (i == m) count++;
        }
        
        return count;
    }
};