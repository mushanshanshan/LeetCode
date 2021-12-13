class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> in(nums.size()+1, true);
        vector<int> res;
        
        for (int& i:nums) {
            in[i] = false;
        }
        
        for (int i=1; i<in.size(); i++) {
            if (in[i]) res.push_back(i);
        }
        
        return res;
    }
};