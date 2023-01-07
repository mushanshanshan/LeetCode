class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remain_gas = 0, total_remian_gas = 0;
        int start = 0;
        int N = gas.size();

        for (int i=0; i<N; i++) {
            if (remain_gas < 0) {
                start = i;
                remain_gas = 0;
            }
            total_remian_gas += gas[i] - cost[i];
            remain_gas += gas[i] - cost[i];
        }

        return total_remian_gas >= 0? start: -1;
    }
};