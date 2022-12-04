/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n-1, peak, mid;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) left = mid + 1;
            else right = mid;
            
        }
        
        peak = left;
        left = 0;
        right = peak;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < target) left = mid + 1;
            else if (mountainArr.get(mid) > target) right = mid - 1;
            else return mid;
        }
        
        left = peak;
        
        right = n-1;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mountainArr.get(mid) > target) left = mid + 1;
            else if (mountainArr.get(mid) < target) right = mid - 1;
            else return mid;
        }
        
        return -1;
        
    }
};