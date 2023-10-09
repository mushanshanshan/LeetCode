class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c0 = 0, c1 = 0, n0 = -1, n1 = -2;
        vector<int> res;
        for (int n: nums) {
            if (n == n0) c0++;
            else if (n == n1) c1++;
            else if (c0 == 0) {n0 = n; c0++;}
            else if (c1 == 0) {n1 = n; c1++;}
            else {c0--; c1--;}
        }

        c0 = 0;
        c1 = 0;
        for (int n: nums) {
            if (n == n0) c0++;
            else if (n == n1) c1++;
        }

        if (c0 > nums.size()/3) res.push_back(n0);
        if (c1 > nums.size()/3) res.push_back(n1);

        return res;
    }
};