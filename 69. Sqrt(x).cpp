class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, mid;
        
        while (left < right) {
            mid = left + (right-left)/2;
            if (x/mid < mid) {
                right = mid-1;
            } else if (x/mid > mid) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        
        if (left!=0 && x/left<left) return left-1;
        return left;
        
        
    }
};