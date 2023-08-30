class Solution {
public:
    int bestClosingTime(string customers) {
        int plenty = 0, left = 0, right = 0, res = 0, N=customers.size();

        for (int i=0; i<N; i++) {
            if (customers[i] == 'Y') right++;
        }
        plenty = right;

        for (int i=0; i<N; i++) {
            if (customers[i] == 'Y') {
                left++;
                right--;
            }
            int cur = i+1-left + right;

            if (cur < plenty) {
                plenty = cur;
                res = i+1;
            }
        }

        return res;
    }
};