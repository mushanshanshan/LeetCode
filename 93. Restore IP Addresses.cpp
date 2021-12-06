class Solution {
public:
    vector<string> result{};
    
    
    bool isValid(string& s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && start != end) {
            return false;
        }
        
        int temp = 0;
        for (int i=start; i<=end; i++) {
            if (s[i] <'0' || s[i]>'9') {
                return false;
            }
            temp = temp * 10 + s[i] - '0';
            if (temp > 255) {
                return false;
            }
        }
        return true;
        
    }
    
    void backtrack(string& s, int start, int time) {
        if (time == 3) {
            if (isValid(s, start, s.size()-1)) {
                result.push_back(s);
            }
            return;
        }
        
        for (int i=start; i<s.size(); i++) {
            if (isValid(s, start, i)) {
                s.insert(i+1, ".");
                time ++;
                backtrack(s, i+2, time);
                time --;
                s.erase(i+1, 1);
            } else break;
            
        }
        
        return;
        
        
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0);
        return result;
    }
};