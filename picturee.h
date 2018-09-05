//
// Created by Merediii on 2018/9/5.
//
#ifndef DATA_STRUCTURE_PICTURE_H
#define DATA_STRUCTURE_PICTURE_H
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
//顶点定义
typedef struct  VertexType{
    int no;
    char info;
}VertexType;
//
typedef struct MGraph{
    int edge[maxSize][maxSize];
    int n,e;
    VertexType vex[maxSize];
}MGraph;


typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    int info;//权值
}ArcNode;
typedef struct VNode{
    char data;
    ArcNode *first;
}VNode;
typedef struct AGraph{
    VNode list[maxSize];//邻接表
    int n,e;
}AGraph;

const int V = 7;
int cost[V][V]={INF,1,INF,INF,INF,INF,INF,
                1,INF,2,3,INF,7,INF,
                INF,2,INF,INF,10,INF,INF,
                INF,3,INF,INF,INF,1,5,
                INF,INF,10,INF,INF,5,INF,
                INF,1,INF,1,INF,INF,8,
                INF,INF,INF,5,INF,8,INF};
int mincost[V];
bool used[V];

int prim(){
    for (int i = 0; i < V; ++i) {
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0] = 0;
    int res = 0;

    while (true) {
        int v = -1;
        for (int i = 0; i < V; ++i)
            if (!used[i] && (v == -1 || mincost[i] < mincost[v]))
                v = i;
        if (v == -1) break;
        used[v] = true;
        cout << v  << endl;
        res += mincost[v];
        for (int j = 0; j < V; ++j) {
            mincost[j] = min(mincost[j], cost[j][v]);
        }
        Show(mincost, 7);
    }
    return res;
}

#endif //DATA_STRUCTURE_PICTUREE_H
