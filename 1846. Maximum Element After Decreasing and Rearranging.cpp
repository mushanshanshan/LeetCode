class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int N = arr.size(), res = 1;
        sort(arr.begin(), arr.end());
        for (int i=0; i<N; i++) {
            if (arr[i] >= res) res++;
        }

        return res-1;
    }
};