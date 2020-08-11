class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()){//判空
            return;
        }
        int row = board.size();
        int col = board[0].size();
        int total = row * col;  
        UnionSet unionset(total + 1); //防止越界
        for(int i = 0; i < row; i++){
            for(int j =0; j < col; j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || j == 0 || i == row - 1 || j == col - 1){
                        unionset.join(total, i*col + j);
                    }
                    else{
                        if(board[i - 1][j] == 'O'){
                            unionset.join(i*col + j, (i-1)*col + j);
                        }
                        if(board[i + 1][j] == 'O'){
                            unionset.join(i*col + j, (i+1)*col + j);
                        }
                        if(board[i][j - 1] == 'O'){
                            unionset.join(i*col + j, i*col + (j-1));
                        }
                        if(board[i][j + 1] == 'O'){
                            unionset.join(i*col + j, i*col + (j+1));
                        }
                    }
                }
            }
        }
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == 'O' && unionset.find(total) != unionset.find(i*col + j)){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
    class UnionSet{
    public:
        vector<int> parent;
        UnionSet(int num){
            parent = vector<int>(num, 0);
            for(int i = 0; i < num; i++){
                parent[i] = i;
            }
        }
        int find(int root){
            return (parent[root] == root) ? root : (parent[root] = find(parent[root]));
        }

        void join(int x, int y){
            if(find(x) != find(y)){
                parent[find(x)] = find(y);
            }
            return;
        }
    };
};


