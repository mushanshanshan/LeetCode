class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>> pq;

        for (int i: costs) {
            if (i <= coins) {
                pq.push(i);
                coins -= i;

            } else if (!pq.empty() && i < pq.top()){
                coins += (pq.top() - i);
                pq.pop();
                pq.push(i); 
            }
        }
        return pq.size();
    }
};