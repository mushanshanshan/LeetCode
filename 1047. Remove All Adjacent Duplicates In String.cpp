class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> temp;
        for (char c: s){
            if (!temp.empty() && temp.top() == c){
                temp.pop();
            }
            else{
                temp.push(c);
            }
            
        }
        string res = "";
        while(!temp.empty()){
            res += temp.top();
            temp.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};