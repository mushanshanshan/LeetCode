class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        stack<int> index_stack;

        for (int i=0; i<N; i++) {
            while(!index_stack.empty() && prices[index_stack.top()] >= prices[i]) {
                prices[index_stack.top()] -= prices[i];
                index_stack.pop();
            }
            index_stack.push(i);
        }

        return prices;
    }
};