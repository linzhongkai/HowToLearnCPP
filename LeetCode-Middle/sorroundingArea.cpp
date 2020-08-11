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
                if(board[i][j] == 'O'){ //要处理的对象
                    if(i == 0 || j == 0 || i == row - 1 || j == col - 1){ //边界当爸爸
                        unionset.join(total, i*col + j);
                    }
                    else{
                        if(board[i - 1][j] == 'O'){ //处理和边界连通的点，换爸爸
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
        for(int i = 0; i < row; ++i){ //遍历
            for(int j = 0; j < col; ++j){ //判断是不是属于同一个爸爸
                if(board[i][j] == 'O' && unionset.find(total) != unionset.find(i*col + j)){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
    class UnionSet{ //并查集
    public:
        vector<int> parent;
        UnionSet(int num){ //用数组也可以，但是用vector可以动态增长
            parent = vector<int>(num, 0);
            for(int i = 0; i < num; i++){
                parent[i] = i;
            }
        }
        int find(int root){ //找爸爸
            return (parent[root] == root) ? root : (parent[root] = find(parent[root]));
        }

        void join(int x, int y){ //认儿子
            if(find(x) != find(y)){
                parent[find(x)] = find(y);
            }
            return;
        }
    };
};


