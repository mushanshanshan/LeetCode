class Solution {
public:
    vector<string> result{};
    string s = "";
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
    };
    
    void backtrack(string input, int index) {
        if (s.length() == input.size()){
            result.push_back(s);
            return;
        }
        
        string t = letterMap[input[index] - '0'];
        for (char c: t) {
            s.push_back(c);
            backtrack(input, index+1);
            s.pop_back();
            
        }
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return result;
        backtrack(digits, 0);
        return result;
    }
};