class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<char,int> hash_map;
        vector<int> int_words(words.size(), 0);
        vector<bool> du(26, true);
        int max_res = 0;
        
        hash_map['a'] = 1;
        for (int i=1; i<26; i++) {
            hash_map[char('a'+i)] = (hash_map[char('a'+i-1)] << 1);
        }
        for (int i=0; i<words.size(); i++) {
            std::fill(du.begin(), du.end(), true);
            for (char c: words[i]) {
                if (du[c - 'a']) {
                    int_words[i] += hash_map[c];
                    du[c - 'a'] = false;
                }
            }
        }
        
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words.size(); j++) {
                if (i == j) continue;
                
                if ((int_words[i] & int_words[j]) == 0) {
                    int len = words[i].size() * words[j].size();
                    max_res = std::max(len, max_res);
                }
            }
        }
        
        
        return max_res;
    }
};