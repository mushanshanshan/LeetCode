class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> counter;
        int count = 0;
        
        for (int a: nums1){
            for (int b: nums2){
                counter[a + b] ++;
            }
        }
        
        for (int c: nums3){
            for (int d: nums4){
                if (counter.find(0-c-d) != counter.end()){
                    count += counter[0-c-d];
                }
            }
            
        }
        
        return count;
    }
};