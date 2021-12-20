class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name[0] != typed[0]) return false;
        
        int slow = 1, fast = 1, l = typed.size(), n = name.size();
        
        while (fast < l) {
            if (slow < n && name[slow] == typed[fast]) {
                slow++;
                fast++;
            } else if (name[slow-1] == typed[fast]) {
                fast++;
            } else return false;
        }
        
        if (slow < name.size()) return false;
        
        return true;
    }
};