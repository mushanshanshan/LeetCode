class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int les = 0, los = 0, res = 0, ros = 0, count = 0;
        bool odd = nums.size() % 2;
        
        for (int i=1; i<nums.size(); i+= 2) {
            res += nums[i-1];
            ros += nums[i];
        }
        if (odd) res += nums[nums.size()-1];
        
        for (int i=0; i<nums.size(); i++) {
            if (i % 2 == 0) {
                res -= nums[i];
                if (les + ros == los + res) count++;
                les += nums[i];
            } else {
                ros -= nums[i];
                if (les + ros == los + res) count++;
                los += nums[i];
            }
        }
        
        return count;
    }
};