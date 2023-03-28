class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cost(366, 0);
        int i = 1, j = 0;

        for (; i < 366; i++) {
            if (i == days[j]) {
                j++;
                cost[i] = min(min(cost[i-1] + costs[0], (i > 7? cost[i-7]: 0) + costs[1]), (i > 30? cost[i-30]: 0) + costs[2]);
            } else cost[i] = cost[i-1];
            if (j == days.size()) return cost[i];
        }

        return cost[365];
    }
};