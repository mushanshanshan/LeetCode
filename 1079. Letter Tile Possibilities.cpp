class Solution {
    private:
        int res = 0;
    
        void recursive(vector<int>& counter) {
            for (int i=0; i<26; i++) {
                if (counter[i] > 0) {
                    res++;
                    counter[i]--;
                    recursive(counter);
                    counter[i]++;
                }
            }
        }
    
    public:
        int numTilePossibilities(string tiles) {
            vector<int> counter(26, 0);
            for (char c: tiles) counter[c - 'A']++;
            recursive(counter);
    
            return res;
        }
    };