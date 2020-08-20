//运用深度优先搜索和递归的思想
class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; //待递归的方向位

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if(board[x][y] == 'M'){ //直接点中雷
            board[x][y] = 'X';
        }
        else{
            dfs(board, x, y); //开始深度优先搜索
        }
        return board;
    }

    void dfs(vector<vector<char> >& board, int x, int y){
        int count = 0;
        for(int i = 0; i < 8; ++i){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()){
                continue;
            }
            count += board[tx][ty] == 'M'; //记录周围雷的数目
        }
        if(count > 0) {
            board[x][y] = count + '0';
        }
        else{ //递归部分
            board[x][y] = 'B';
            for(int i = 0; i < 8; ++i){
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() 
                    || board[tx][ty] != 'E'){
                    continue;
                }
                dfs(board, tx, ty);
            }
        }
    }
};
