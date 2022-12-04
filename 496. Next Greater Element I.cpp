class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        
        for (int i=0; i<nums1.size(); i++) {
            dict[nums1[i]] = i;
        }
        
        stack<int> s;
        vector<int> res(nums1.size(), -1);
        
        for (int i=0; i<nums2.size(); i++) {
            if (s.empty() || s.top() >= nums2[i]) {
                s.push(nums2[i]);
            } else{
                while (!s.empty() && s.top() < nums2[i]) {
                    if (dict.find(s.top()) != dict.end()) {
                        res[dict[s.top()]] = nums2[i];
                    }
                    s.pop();
                }
                s.push(nums2[i]);
            }
        }
        return res;
    }
};