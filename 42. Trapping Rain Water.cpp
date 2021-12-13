class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0), right(height.size(), 0);
        
        for (int i=1; i<height.size(); i++) {
            left[i] = max(left[i-1], height[i-1]);
        }
        
        for (int i=height.size()-2; i>-1; i--) {
            right[i] = max(right[i+1], height[i+1]);
        }
        
        int res = 0;
        for (int i=0; i<height.size(); i++) {
            res += max(0, min(left[i],right[i])-height[i]);
        }
        
        return res;
    }
};