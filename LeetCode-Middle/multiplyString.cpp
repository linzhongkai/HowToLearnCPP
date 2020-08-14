class Solution {
public:
    string multiply(string num1, string num2) {
        string result1 = "", result2 = "";
        int carry =0;
        int count = 0;
        for(int i = num2.size() - 1; i >= 0; i--, count++){
            result1.clear();
            int carry =0;
            int y = num2[i] - '0';
            for(int j = num1.size() - 1; j >= 0; j--){
                int x = num1[j] - '0';
                int multi = x * y + carry;
                result1.push_back('0' + multi % 10);
                carry = multi / 10;
            }
            if(carry != 0){ //处理最后一个进位
                result1.push_back('0' + carry);
            }
            reverse(result1.begin(), result1.end());
            for(int k = 0; k < count; k++){ //移位
                result1.push_back('0');
            }
            result2 = addStrings(result2, result1);
        }
        if(result2[0] == '0'){ //处理结果为0的问题
            result2.clear();
            result2.push_back('0');
        }
        return result2;
    }

    string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int add = 0;
    int carry = 0;
    string result;
    while(i >= 0 || j >= 0){
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
