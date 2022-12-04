class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> all;
        vector<int> res(2, nums[0][0]);
        unordered_map<int, int> dict;
        int  lenght = INT_MAX, k = nums.size();
        
        for (int i=0; i<nums.size(); i++) {
            for (int m: nums[i]) {
                all.push_back({m, i});
            }
        }
        
        int n = all.size(), left = 0, cnt = 0;
        
        sort(all.begin(), all.end());
        
        for (int right = 0; right<n; right++) {
            if (dict[all[right].second] == 0) cnt++;
            dict[all[right].second]++;
            while (left < right && cnt == k) {
                if (all[right].first - all[left].first < lenght) {
                    lenght = all[right].first - all[left].first;
                    res = {all[right].first , all[left].first};
                }
                dict[all[left].second]--;
                if (dict[all[left].second] == 0) cnt--;
                left++;
            }
        }
        
        return res;
    }
};