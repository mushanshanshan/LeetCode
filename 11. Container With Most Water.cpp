class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = min(height[left], height[right]) * (right - left);
        
        while (left < right) {
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
            
            res = max(res, min(height[left], height[right]) * (right - left));
        }
        
        return res;
        
    }
};