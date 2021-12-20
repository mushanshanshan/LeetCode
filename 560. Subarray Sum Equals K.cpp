class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int res = 0, temp = 0;
        
        hash[0] = 1;
        
        for (int& i: nums) {
            temp += i;
            res += hash[temp - k];
            hash[temp]++;
            
        }
        
        return res;
    }
};