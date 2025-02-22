class Solution {
    public:
        string smallestNumber(string pattern) {
            int l = -1, N = pattern.size();
            string res = "";
    
            for (int r=0; r<=N; r++) {
                if (r == N || pattern[r] == 'I') {
                    for (int i=r; i>l; i--) {
                        res.push_back('0' + i + 1);
                    }
                    l = r;
                }
            }
    
            return res;
        }
    };