class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l = 0;
        if (str1 + str2 == str2 + str1) {
            l = gcd(str1.size(), str2.size());
        }
        return str1.substr(0, l);
    }
};