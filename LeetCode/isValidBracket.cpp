class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        if(s.size() % 2 != 0){ //非偶数就不可能对称
            return false;
        }
        stack<char> p;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '(' || c== '{' || c == '['){
                p.push(c); //将左半边加入栈
            }
            else{
                if(p.empty()){ //栈空就说明没有符合的左半边
                    return false;
                }
                if(p.top() == '(' && c != ')') return false;
                if(p.top() == '{' && c != '}') return false;
                if(p.top() == '[' && c != ']') return false;
                p.pop();
            }
        }
        return p.empty(); //栈空说明符合
    }
};
