//
// Created by Merediii on 2018/4/16.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
typedef struct QueNode{
    int data;
    struct QueNode* next;
}QueNode;
typedef struct {
    QueNode * front,* rear;
}*LiQue;
void create(LiQue &q){
    q = (LiQue) malloc(sizeof(LiQue));
    q->front = q->rear = (QueNode *) malloc(sizeof(QueNode));
    q->front->next = NULL;
    cout << "1";
}
int isEmpty(LiQue q){
    if(q->rear == q->front) return 1;
    else
        return 0;
}

void enQue (LiQue q, int a){
    QueNode* s = (QueNode *) malloc(sizeof(QueNode));
    s->next = NULL;
    q->rear->next = s;
    s->data = a;
    q->rear = s;
};

int deQue(LiQue q , int &a){
    QueNode *s;
    if (isEmpty(q)) return 0;
    s = q->front->next;
    a = s->data;
    q->front->next = s->next;
    if(q->rear == s) q->rear = q->front;
    free(s);
    return 1;
}

void show (LiQue q){
    QueNode * p;
    p = q->front;
    while (p) {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout << "NULL";
};
#endif //DATA_STRUCTURE_QUEUE_H
