class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        long counter = 0 , res = 0;
        sort(usageLimits.begin(), usageLimits.end());

        for (int i=0; i<usageLimits.size(); i++) {
            counter += usageLimits[i];
            if (counter >= ((res+1) * (res+2) / 2)) res++;
        }

        return res;
    }
};