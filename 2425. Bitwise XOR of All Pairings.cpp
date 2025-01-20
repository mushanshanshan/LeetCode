class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size(), M = nums2.size();
        int n1 = 0, n2 = 0;

        if (M % 2) {
            for (int i: nums1) n1 ^= i;
        }

        if (N % 2) {
            for (int i: nums2) n2 ^= i;
        }

        return n1 ^ n2;
    }
};