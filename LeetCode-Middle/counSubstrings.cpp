//超傻瓜写法，时间复杂度太高了
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        string temp = "";
        for(int j = 0; j < s.size(); j++){
            temp.clear();
            temp.push_back(s[j]);
            for(int k = j; k < s.size();){
                if(isPalindrome(temp)){
                    count++;
                }
                temp.push_back(s[++k]);
            }
        }
        return count;
    }

    bool isPalindrome(string s){
        int i;
        stack<char> stk;
        for(i = 0; i < (s.size() / 2); i++){
            stk.push(s[i]);
        }
        if(s.size() % 2 != 0){
            i++;
        }
        while(i < s.size()){
            if(stk.top() != s[i]){
                return false;
            }
            stk.pop();
            i++;
        }
        return stk.empty();
    }
};

//一种简单的中心扩展方法
class Solution {
public:
    int countSubstrings(string s) {
        int l = 0, r = 0, count = 0;
        for(int i = 0; i < 2 * s.size() - 1; i++){ //需要遍历2*n - 1次
            l = i / 2;
            r = i / 2 + i % 2;
            while(l >= 0 && r <= s.size() && s[l] == s[r]){
                l--;
                r++;
                count++;
            }
        }
        return count;
    }
};
