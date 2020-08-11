class Solution {
public:
    int countBinarySubstrings(string s) {
        int right{0}, left{0}, ans{0};
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] != s[i+1]){
                left = i;
                right = i + 1;
                while(left > 0 && right < s.size() - 1){
                      if(s[left-1] != s[left] || s[right] != s[right + 1]){
                          break;
                      }
                      left--;
                      right++;
                  }
                ans += right - i;
                i = right - 1;
            }
        }
        return ans;
    }
};
