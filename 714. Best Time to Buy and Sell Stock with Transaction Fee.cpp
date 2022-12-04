class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int withS = prices[0] * -1, withoutS = 0, temp;
        
        for (int i=0; i<prices.size(); i++) {
            temp = withS;
            withS = max(withS, withoutS - prices[i]);
            withoutS = max(temp + prices[i] - fee, withoutS);
        }
        
        return withoutS;
    }
};