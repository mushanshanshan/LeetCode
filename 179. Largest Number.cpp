class Solution {
public:
    static bool cmp(string& a, string& b) {
        return (a+b) > (b+a);
    }
    
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);
        int count = 0;
        for (int& i: nums) {
            if(!i) count++;
        } if (count == nums.size()) return "0";
        
        vector<string> snums(nums.size());
        string res;
        
        for (int i=0; i<nums.size(); i++) {
            snums[i] = to_string(nums[i]);
        }
        sort(snums.begin(), snums.end(), cmp);
        
        for (string& s: snums) {
            res += s;
        }
        
        return res;
    }
};