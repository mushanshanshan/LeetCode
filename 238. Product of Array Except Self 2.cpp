class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size(), temp = 1;
        vector<int> l(N, 1);
        vector<int> r(N, 1);

        for (int i=1; i<N; i++) {
            temp *= nums[i-1];
            l[i] = temp;
        }

        temp = 1;
        for (int i = N-2; i>=0; i--) {
            temp *= nums[i+1];
            r[i] = temp;
        }

        for (int i=0; i<N; i++) {
            l[i] = l[i] * r[i];
        }

        return l;
    }
};