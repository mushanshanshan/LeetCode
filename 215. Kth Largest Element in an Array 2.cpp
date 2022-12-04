class Solution {
public:
    class cmp {
        public:
            bool operator() (int a, int b) {
                return a > b;
            }    
    };
    
    
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        
        for (int i: nums) {
            if (pq.size() == k) {
                if (i > pq.top()) {
                    pq.pop();
                    pq.push(i);
                }
            } else {
                pq.push(i);
            }
        }
        return pq.top();
    }
};