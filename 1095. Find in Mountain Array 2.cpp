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
    int findInMountainArray(int target, MountainArray &m) {
        int N = m.length();
        int peak = 0, l = 0, r = N-1, mid;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (m.get(mid) < m.get(mid+1)) l = mid + 1;
            else r = mid - 1;
        }

        peak = l;
        l = 0;
        r = peak;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (m.get(mid) < target) l = mid + 1;
            else if (m.get(mid) > target) r = mid - 1;
            else return mid;
        }

        l = peak;
        r = N-1;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (m.get(mid) < target) r = mid - 1;
            else if (m.get(mid) > target) l = mid + 1;
            else return mid;
        }

        return -1;
    }
};