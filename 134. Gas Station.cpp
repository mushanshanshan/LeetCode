class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumG = 0, sumC = 0, s = 0, res = 0;
        
        for (int i=0; i <gas.size(); i++) {
            sumG += gas[i];
            sumC += cost[i];
            s += gas[i] - cost[i];
            if (s<0) {
                s=0;
                res = i+1;
            }
        }
        
        if (sumG<sumC) {
            return -1;
        }
        return res;
    }
};