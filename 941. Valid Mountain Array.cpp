class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int n = arr.size()-1, left=0, right = n;
        
        while (left < n-1 && arr[left] < arr[left+1]) left++;
        while (right > 0 && arr[right-1] > arr[right]) right--;
        
        if (left == right && left != 0 && left != arr.size()-1) return true;
        return false;
    }
};