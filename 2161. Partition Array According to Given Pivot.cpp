class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int small = 0, equal = 0, larger = 0;
            int N = nums.size();
    
            for (int i: nums) {
                if (i > pivot) larger++;
                else if (i < pivot) small++;
                else equal++;
            }
    
            vector<int> res(N);
            int k = 0, j = small + equal;
            for (int i: nums) {
                if (i < pivot) res[k++] = i;
                else if (i == pivot) res[small++] = i;
                else res[j++] = i;
            }
    
            return res;
        }
    };