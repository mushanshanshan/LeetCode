class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if (map.find(nums[i]) == map.end()){
                map[target - nums[i]] = i;
            }else {
                result.push_back(map[nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};