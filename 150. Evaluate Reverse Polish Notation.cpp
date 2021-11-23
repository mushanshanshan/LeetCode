class Solution {
public:
   
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        int a, b;
        for (string s: tokens){
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                b = temp.top();
                temp.pop();
                a = temp.top();
                temp.pop();
                if (s == "+") {temp.push(a+b);}
                if (s == "-") {temp.push(a-b);}
                if (s == "*") {temp.push(a*b);}
                if (s == "/") {temp.push(a/b);}
                
            } else {
                temp.push(stoi(s));
            }
        }
        return temp.top();
    }
};