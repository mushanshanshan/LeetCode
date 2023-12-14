class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cur = 1, n = arr.size() / 4;

        for (int i=1; i<arr.size(); i++) {
            if (arr[i] == arr[i-1]) cur++;
            else cur = 1;
            if (cur > n) return arr[i];
        }

        return arr[0];
    }
};