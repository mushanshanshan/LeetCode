class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        vector<int> res;
        unordered_map<int, int> counter;
        for (int n: nums1) counter[n]++;

        for (int i: nums2) {
            if (counter.find(i) != counter.end() && counter[i] > 0) {
                res.push_back(i);
                counter[i] = -1;
            } 
        }

        return res;

    }
};