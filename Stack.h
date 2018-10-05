//
// Created by Merediii on 2018/4/16.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode, *LiStack;
void create(LiStack &stack){
    stack = (StackNode *) malloc(sizeof(StackNode));
    stack->next = NULL;
}

int isEmpty (LiStack s){
    if(s->next == NULL)
        return 1;
    else
        return 0;
};

void push(LiStack s, int a){
    StackNode *p;
    p = (StackNode *) malloc(sizeof(StackNode));
    p->next = NULL;

    //头插法
    p->data = a;
    p->next = s->next;
    s->next = p;
}

int pop (LiStack s, int &a){
    StackNode *p;
    if(isEmpty(s)) return 0;
    p = s->next;
    a = p->data;
    s->next = p->next;
    free(p);
    return  1;
};

void show(LiStack s) {
    cout << "Top->";
    StackNode *p = s;
    while (p){
        cout << p->data << "->";
        p=p->next;
    }
    cout << "NULL";
}
#endif //DATA_STRUCTURE_STACK_H
