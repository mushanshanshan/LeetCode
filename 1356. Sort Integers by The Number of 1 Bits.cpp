class Solution {
private:
    static int count1(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }

    static bool cmp(int a, int b) {
        int ca = count1(a);
        int cb = count1(b);

        return ca == cb? a <= b: ca < cb;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};