class Solution {
public:
    int countBinarySubstrings(string s) {
       auto next{'.'};
       s += next; //增加一个符号
       auto pre{0}, cur{0}, total{0};

       for(auto c : s){
           if(next != c){
               next = c;
               total += min(pre, cur);
               pre = cur;
               cur = 0;
           }
           cur++;
       }
       return total;
    }
};
