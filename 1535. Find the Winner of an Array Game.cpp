class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur_max = 0, cur_win = 0, N = arr.size(), cur = 1;

        if (k >= N) {
            auto max_it = max_element(arr.begin(), arr.end());
            return *max_it;
        }

        while (cur_win < k) {
            if (arr[cur_max] > arr[cur % N]) {
                cur_win++;
            } else if (arr[cur_max] < arr[cur % N]) {
                cur_max = cur % N;
                cur_win = 1;
            }
            cur++;
        }

        return arr[cur_max];
    }
};