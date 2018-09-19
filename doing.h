//
// Created by Merediii on 2018/9/8.
//

#ifndef DATA_STRUCTURE_DOING_H
#define DATA_STRUCTURE_DOING_H
#define len(a) end(a)-begin(a)
int a[10] = {3, 24, 35, 61, 27, 16, 28, 39, 12, 10};
char t[] = {
        'A', 'B', 'C', 'D', '#', '#', '#', 'F', 'E', '#', '#',
        'G', 'H', '#', 'I', '#', '#', '#'
};

//     LinkedList L;
//     createHead(L, a, 11);
//     show(L);
//     Heap(a,end(a) - begin(a));
//     Show(a,end(a) - begin(a));
//     BTree tree;
//     grow(tree,t);
//     Pre(tree);
//cout<<prim ()<<endl;
//system("pause");

int delTheNode (LNode *L, int x);

void listDo () {
    LinkedList L;
    int x = 1;
    createHead(L, a, len(a));
    show(L);
    while(x!=0){
        cin>> x;
        //del(L, x);
        cout<<delTheNode(L,x)<<endl;
        show(L);
    }
};

int delTheNode (LNode *L, int x){
    LNode *p;
    LNode *q;
    p = L->next;
    q = L;
    while(p){
        if(p->data == x){
            q->next = p->next;free(p);return 1;}
        q = p;
        p = p->next;
    }
    return 0;
};
#endif //DATA_STRUCTURE_DOING_H
