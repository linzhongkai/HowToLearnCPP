//进位也可以放在循环判断

class Solution {
public:
    string addStrings(string num1, string num2) {
       int i = num1.size() - 1;
       int j = num2.size() - 1;
       int add = 0;
       int carry = 0;
       string result;
       while(i >= 0 || j >= 0){ //carry != 0
           int x = i >= 0 ? num1[i] - '0' : 0;
           int y = j >= 0 ? num2[j] - '0' : 0;
           add = x + y + carry;
           result.push_back('0' + add % 10);
           carry = add / 10;
           i--;
           j--;
       }
       if(carry != 0){ //处理最后一个进位
           result.push_back('0' + carry);
       }
       reverse(result.begin(), result.end()); //翻转
       return result;
    }
};
