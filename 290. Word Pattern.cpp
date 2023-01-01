/*
 * @Date: 2023-01-01 16:28:30
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2023-01-01 16:28:34
 * @FilePath: /LeetCode/290. Word Pattern.cpp
 */
class Solution {

public:
    bool wordPattern(string pattern, string s) {

        vector<string> words(26, "");
        int patIndex = 0;
        stringstream ss;
        ss << s;
        string temps;

        while (ss >> temps) {
            
            if (patIndex == pattern.size()) return false;

            if (words[pattern[patIndex]-'a'] == "") {
                if (find(words.begin(), words.end(), temps) != words.end()) return false;
                words[pattern[patIndex]-'a'] = temps;
            }
            else {
                if (temps != words[pattern[patIndex]-'a']) return false;
            }
            patIndex++;
            
        }

        if (patIndex < pattern.size()) return false;

        return true;
    }
};