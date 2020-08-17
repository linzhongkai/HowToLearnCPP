class Solution {
public:
    const int dx[4] = {1, 0, 0, -1}; //四个方向的移动
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int curColor = image[sr][sc];
        if(curColor == newColor){ //没有newcolor
            return image;
        }
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int> > que; //使用队列
        que.emplace(sr, sc);
        image[sr][sc] = newColor;
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int i = 0; i < 4; i++){
                int mx = x + dx[i];
                int my = y + dy[i];
                if(mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] ==curColor){
                    que.emplace(mx, my);
                    image[mx][my] = newColor; //方格颜色更新，不会重复入队
                }
            }
        }
        return image;
    }
};
