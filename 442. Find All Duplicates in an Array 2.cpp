class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int TH = 1e5;
        vector<int> res;

        for (int n: nums) {
            nums[n % TH - 1] += TH;
        }

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 2*TH) res.push_back(i+1);
        }

        return res;
    }
};