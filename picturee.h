//
// Created by Merediii on 2018/9/5.
//
#ifndef DATA_STRUCTURE_PICTURE_H
#define DATA_STRUCTURE_PICTURE_H
#define maxSize 100
typedef struct  VertexType{
    int no;
    char info;
}VertexType;
typedef struct MGraph{
    int edge[maxSize][maxSize];
    int n,e;
    VertexType vex[maxSize];
}MGraph;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    int info;
}ArcNode;
typedef struct VNode{
    char data;
    ArcNode *first;
}VNode;
typedef struct AGraph{
    VNode list[maxSize];
    int n,e;
}AGraph;

#endif //DATA_STRUCTURE_PICTUREE_H