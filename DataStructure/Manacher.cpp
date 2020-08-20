//马拉车算法寻找最长回文子串，见leetcode第五题的题解部分
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ManacherForStr(string s){
    int size = s.size();
    if(size < 2){
        return s;
    }
    //预处理字符串
    string str = "#";
    for(int i = 0; i < size; i++){
        str += s[i];
        str += "#";
    }
    //int strSize = str.size();
    int strSize = 2 * size -1;
    //记录回文字串长度，不算中心，扩展的步数
    vector<int> p(strSize, 0); //初始化
    //中心指针和右边界指针
    int maxRight = 0;
    int center = 0;
    //最长回文子串长度
    int maxLen = 1;
    //最长回文子串起始位置
    int start = 0;

    for(int i = 0; i < strSize; i++){
        if(i < maxRight){ //manacher核心步骤
            int mirror = 2*center - 1;
            p[i] = min(maxRight - i, p[mirror]);
        }
        //更新左右起点
        int left = i - (1 + p[i]);
        int right = i + (1 + p[i]);
        while(left >= 0 && right <= strSize && str[left] == str[right]){
            //扩展以计算回文子串长度
            p[i]++; left--; right++;
        }
        if(i + p[i] > maxRight){ //尝试更新右边界和中心
            maxRight = i + p[i];
            center = i;
        }
        if(p[i] > maxLen){ //更新最大子串长度和起点
            maxLen = p[i];
            start = (i - maxLen) / 2;
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    string str{"abbacd"};
    cout << ManacherForStr(str) << endl;
    return 0;
}


