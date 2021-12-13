class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> with(prices.size(),0), without(prices.size(),0);
        with[0] = -1 * prices[0];
        without[0] = 0;
        
        for (int i=1; i<prices.size(); i++) {
            with[i] = max(with[i-1], without[i-1]-prices[i]);
            without[i] = max(without[i-1], with[i-1]+prices[i]);
        }
        
        return without[prices.size()-1];
    }
};