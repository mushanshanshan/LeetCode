class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cur_max = 0, res = 0;
        int N = arr.size();

        for (int i=0; i<N; i++) {
            if (arr[i] > cur_max) cur_max = arr[i];
            if (cur_max == i) res++;
        }

        return res;
    }
};