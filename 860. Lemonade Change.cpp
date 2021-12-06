class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash(2, 0);
        
        for (int i=0; i<bills.size(); i++) {
            if (bills[i]==5) {
                cash[0]++;
            } else if (bills[i]==10) {
                cash[1]++;
                cash[0]--;
                if (cash[0]<0) return false;
            } else {
                if (cash[1]>0) {
                    cash[1]--;
                    cash[0]--;
                } else {
                    cash[0] -= 3;
                }
                if (cash[0]<0 || cash[1]<0) return false;
            }
        }
        return true;
    }
};