#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& nums) {
    for (int end=nums.size(); end>0;end--) {
        for (int i=0; i<end-1; i++) {
            if (nums[i] > nums[i+1]) {
                std::swap(nums[i], nums[i+1]);
            }
        }
    }

}


void selectionSort(std::vector<int>& nums) {
    int temp;
    for (int start=0; start<nums.size(); start++) {
        temp = start;
        for (int i=start; i<nums.size(); i++) {
            if (nums[temp] > nums[i]) {
                temp = i;
            }

        }
        std::swap(nums[start], nums[temp]);
    }
}


void insertionSort(std::vector<int>& nums) {
    int temp, j;
    
    for (int i=0; i<nums.size()-1; i++) {
        temp = nums[i+1];
        j = i;
        while (nums[j] > temp && j>=0) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }
}

void _quickSort(std::vector<int>& nums, int l, int r) {
    if (l < r) {
        int i = l, j = r-1, pivot = nums[i];
        
        while (i < j) {
            while (nums[j] >= pivot && j > i){
                j--;
            }
            nums[i] = nums[j];
            
            while (nums[i] <= pivot && i < j) {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        _quickSort(nums, l, i);
        _quickSort(nums, i+1, r);
        
    }
    
}

void quickSort(std::vector<int>& nums) {
    
    _quickSort(nums, 0, nums.size()-1);
}

void _mergeSort(std::vector<int>& nums, std::vector<int>& temp, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        _mergeSort(nums, temp, l, m);
        _mergeSort(nums, temp, m, r);
        
        int i = l, j = m, k = l;
        
        while (i < m || j < l) {
            if ((i < m && nums[i] <= nums[j]) || j >= l) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        for (i = l; i < r; i++) {
            nums[i] = temp[i];
        }
    }
    
    
}

void mergeSort(std::vector<int>& nums) {
    std::vector<int> temp(nums.size(), 0);
    _mergeSort(nums, temp, 0, nums.size()-1);
}



int main(int argc, char *argv[]) {
    std::vector<int> nums = {34,2134,62,32,6,234,6,7,8,4,5,7,8,3,45,9123};

    mergeSort(nums);

    for (int i=0; i<nums.size(); i++) {
        std::cout<<nums[i]<<',';

    }
}