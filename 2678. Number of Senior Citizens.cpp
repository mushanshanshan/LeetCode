class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;

        for (auto& a: details) {
            if (a[11] >= '6') {
                if (a[11] == '6' && a[12] == '0') continue;
                res++;
            }
        }

        return res;
    }
};