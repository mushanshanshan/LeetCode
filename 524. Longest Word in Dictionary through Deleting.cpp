class Solution {
public:
    int valid(string s, string t) {
        int p1=0, p2=0;
        
        while (p1<s.size() && p2<t.size()) {
            if (s[p1] == t[p2]) {
                p1++;
                p2++;
            } else {
                p1++;
            }
        }
        if (p2 == t.size()) return p2;
        return -1;
    }
    
    bool checkOrder(string s, string t) {
        int p=0;
        
        while (p<s.size()) {
            if (s[p]>t[p]) {
                return true;
            } else if (s[p]<t[p]) {
                return false;
            }
            p++;
        }
        return false;
    }
    
    
    string findLongestWord(string s, vector<string>& dictionary) {
        int len = -1, index = -1;
        for (int i=0; i<dictionary.size(); i++) {
            int temp = valid(s, dictionary[i]);
            if (temp > len || (temp>0 && temp==len && checkOrder(dictionary[index], dictionary[i])) ) {
                len = temp;
                index = i;
            }
        }
        if (index != -1) {
            return dictionary[index];
        }
        return "";
        
    }
};