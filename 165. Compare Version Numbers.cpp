class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cur1 = 0, cur2 = 0, ver1 = version1.size(), ver2 = version2.size();
        
        while (cur1<ver1 || cur2<ver2) {
            int n1 = 0, n2 = 0;
            
            while (cur1<ver1 && version1[cur1]!='.') {
                n1 = n1*10 + (version1[cur1] - '0');
                cur1++;
            }
            cur1++;
            
            while (cur2<ver2 && version2[cur2]!='.') {
                n2 = n2*10 + (version2[cur2] - '0');
                cur2++;
            }
            cur2++;
            
            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
        }
        
        return 0;
    }
};