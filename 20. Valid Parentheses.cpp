class Solution {
public:
    bool isValid(string s) {
        stack<int> counter;
        for (char c: s){
            if (c == '('){
                counter.push(')');
            }
            else if (c == '['){
                counter.push(']');
            }
            else if (c == '{'){
                counter.push('}');
            }
            else if (counter.empty() || c!= counter.top()){
                return false;
            }
            else {
                counter.pop();
            }
        }
        
        return counter.empty();
    }
};