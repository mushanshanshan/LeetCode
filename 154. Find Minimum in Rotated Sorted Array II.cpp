class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid;
        
        while (l<r) {
            mid = l + (r - l) / 2;
            cout<<l<<'|'<<mid<<'|'<<r<<endl;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r--;
            }
        }
        
        return nums[r];

    }
};