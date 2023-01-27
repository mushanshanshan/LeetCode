class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> set;
        vector<string> res;

        for (auto s: words) set.insert(s);

        for (auto s: words) {
            int l = s.size();
            vector<int> sub(l+1, 0);
            sub[0] = 1;

            for (int i=0; i<l; i++) {
                if (!sub[i]) continue;
                
                for (int j=1; j<=l-i; j++) {
                    if (!(i==0 && j == l) && set.count(s.substr(i, j))) {
                        sub[i+j] = 1;
                    }
                }

                if (sub[l]) {
                    res.push_back(s);
                    break;
                }
            }


        }
        return res;
    }
};