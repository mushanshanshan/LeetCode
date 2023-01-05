/*
 * @Date: 2023-01-02 15:01:55
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2023-01-02 15:01:58
 * @FilePath: /LeetCode/520. Detect Capital.cpp
 */
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size()==1) return true;

        bool allUpper = false; 
        if (isupper(word[0]) && isupper(word[1])) {
            allUpper = true;
        }

        for (int i=1; i<word.size(); i++) {
            if (allUpper? islower(word[i]) : isupper(word[i])) {
                return false;
            }
        }

        return true;
    }
};