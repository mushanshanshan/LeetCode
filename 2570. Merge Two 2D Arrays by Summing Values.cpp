class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> res;
    
            int i=0, j=0;
            int N = nums1.size(), M = nums2.size();
    
            while (i < N || j < M) {
                printf("%d-%d\n", i, j);
                if (i == N) res.push_back(nums2[j++]);
                else if (j == M) res.push_back(nums1[i++]);
                else if (nums1[i][0] < nums2[j][0]) res.push_back(nums1[i++]);
                else if (nums1[i][0] > nums2[j][0]) res.push_back(nums2[j++]);
                else {
                    res.push_back({nums1[i][0], nums1[i++][1] + nums2[j++][1]});
                }
            }
    
            return res;
        }
    };