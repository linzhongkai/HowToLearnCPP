//
// Created by Administrator on 2020/8/12.
//

#include <iostream>
#include <queue>

using namespace std;

#define MAXNUM 100
typedef char VexType;
typedef int EdgeType;


typedef struct {
    VexType Vex[MAXNUM];
    EdgeType Edge[MAXNUM][MAXNUM];
    int vexnum, edgenum;
} MGragh;


//创建无向图
void creatAMGragh(MGragh& G){
    int i, j, k, w;
    cout << "请输入顶点和边数: " << endl;
    cin >> G.vexnum >> G.edgenum;
    cout << "请输入顶点信息: " << endl;
    for(i = 0; i < G.vexnum; i++){
        cin >> G.Vex[i];
    }
    for(i = 0; i < G.vexnum; i++){
        for(j = 0; j < G.vexnum; j++){
            G.Edge[i][j] = 0;
        }
    }
    for(k = 0; k < G.edgenum; k++){
        cout << "请输入上下标和权值：\n";
        cin >> i >> j >> w;
        G.Edge[i][j] = w;
        G.Edge[j][i] = G.Edge[i][j]; //无向图
    }
}

//广度优先搜索无向图
void BFSTraverse(MGragh GL){
    int i, j;
    queue<int> Q;
    bool visitied[MAXNUM];
    for(i = 0; i < GL.vexnum; i++){
        visitied[i] = false;
    }
    for(i = 0; i < GL.vexnum; i++){
        if(!visitied[i]){
            visitied[i] = true;
            cout << "root: "<< GL.Vex[i] << endl;
            Q.push(i);
            while(!Q.empty()){
                i = Q.front();
                Q.pop();
                for(j = 0; j < GL.vexnum; j++){
                    if(GL.Edge[i][j] == 1 && !visitied[j]){
                        visitied[j] = true;
                        cout << "vec: "<< GL.Vex[j] << " ";
                        cout << "Edge：" << i << j << endl;
                        Q.push(j);
                    }
                }
            }
        }
    }
}

int main() {
    MGragh Gragh;
    creatAMGragh(Gragh);

    cout << "顶点信息：\n";
    for(int i = 0; i < Gragh.vexnum; i++){
        cout <<  Gragh.Vex[i] << " ";
    }
    cout << "\n边数组：\n";
    for(int i = 0; i < Gragh.vexnum; i++){
        for(int j = 0; j < Gragh.vexnum; j++){
            cout << Gragh.Edge[i][j] << " ";
        }
        cout << endl;
    }
    cout << "广度优先搜索:\n";
    BFSTraverse(Gragh);

    return 0;
}



