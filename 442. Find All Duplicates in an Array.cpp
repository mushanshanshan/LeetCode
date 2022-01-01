class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size() , m = n + 1, c = 2 * m;
        
        for (int i=0; i<n; i++) {
            nums[nums[i] % m - 1] += m;
        }
        
        for (int i=0; i<n; i++) {
            if (nums[i] > c) res.push_back(i+1);
        }
        
        return res;
    }
};