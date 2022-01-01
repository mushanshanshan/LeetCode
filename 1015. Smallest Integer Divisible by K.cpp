class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if ((k%10)%2 == 0) return -1;
        
        unordered_set<int> re;
        int mod = 0;
        
        for (int i=0; i<k; i++) {
            mod = (mod * 10 + 1) % k;
            if (mod == 0) return i+1;
            if (re.find(mod) != re.end()) return -1;
            re.insert(mod);
        }
        
        return -1;
        
    }
};