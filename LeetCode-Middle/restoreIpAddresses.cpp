class Solution{
public:
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return result;
    }
    
    void dfs(string s, int segId, int start){
        if (segId == SEG_COUNT) { //找到4段了
            if (start == s.size()) { //start指向最后一个元素
                string ipAddr;
                for (int i = 0; i < SEG_COUNT; i++){
                    ipAddr += to_string(segments[i]);
                    if (i != SEG_COUNT - 1){
                        ipAddr += '.';
                    }
                }
                result.push_back(ipAddr);
            }
            return;
        }
        
        if(start == s.size()){ //未找到
            return;
        }
        
        //处理0的问题
        if (s[start] == '0'){
            segments[segId] = 0;
            dfs(s, segId + 1, start + 1);
        }
        
        //这一段代码是回溯思想的体现
        int addr = 0;
        for (int i = start; i < s.size(); i++){ //每段ip只有3种可能
            addr = addr * 10 + (s[i] - '0');
            if (addr > 0 && addr <= 255){
                segments[segId] = addr;
                dfs(s, segId + 1, i + 1);
            }
            else{
                break;
            }
        }
    }
    
private:
    const int SEG_COUNT = 4;
    vector<int> segments;
    vector<string> result;

};


