class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> dict;
        int res = 0;
        
        for (int i: nums) {
            dict[i]++;
        }
        
        for (int i: nums) {
            if (dict.count(i+1)) res = max(dict[i] + dict[i+1], res);
        }
        
        return res;
    }
};