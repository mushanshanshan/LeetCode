class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int low_digit = 0, high_digit = 0;
        int temp = low;
        while (temp > 0) {
            low_digit++;
            temp /= 10;
        }
        temp = high;
        while (temp > 0) {
            high_digit++;
            temp /= 10;
        }

        for (int i=low_digit; i<=high_digit; i++) {
            for (int s=1; s<=10-i; s++) {
                temp = 0;
                int c = s;
                for (int j=i; j>0; j--) {
                    temp += c * pow(10, j-1);
                    c++;
                }

                if (temp >= low && temp <= high) res.push_back(temp);
            }
        }

        return res;
    }
};