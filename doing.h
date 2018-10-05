//
// Created by Merediii on 2018/9/8.
//

#ifndef DATA_STRUCTURE_DOING_H
#define DATA_STRUCTURE_DOING_H
#define len(a) end(a)-begin(a)
#define INF 0x3f3f3f3f
int a[10] = {3, 24, 35, 61, 27, 16, 28, 39, 12, 10};
char ch[] = {
        'A', 'B', 'C', 'D', '#', 'E', '#', '#', 'F',//            A
        'G', '#', '#', 'H', '#', '#', 'I', '#', '#',//       B         J
        'J', 'K', '#', 'L', '#', '#', 'M', 'N', '#',//    C     I   K     M
        '#', 'O', '#', '#'                          //  D   F         L N   O
};                                                  //   E G H
const int V = 7;
int mincost[V];
bool used[V];
int cost[V][V]={INF,1,INF,INF,INF,INF,INF,//                            0
                1,INF,2,3,INF,7,INF,//                                  |
                INF,2,INF,INF,10,INF,INF,//            2----------------1-------3
                INF,3,INF,INF,INF,1,5,//               |                |    /  |
                INF,INF,10,INF,INF,5,INF,//            |                |  /    |
                INF,1,INF,1,INF,INF,8,//               4----------------5-------6
                INF,INF,INF,5,INF,8,INF};//


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

void so(int r[],int a){
    int b,t;
    for (int i = 0; i < a; ++i) {
        b = i;
        for (int j = i + 1; j < a; ++j)
            if(r[b] > r[j])
                b = j;
//        t = r[i];
//        r[i] = r[b];
//        r[b] = t;
        swap(r[b], r[i]);

    }
}

void Do(){
//    LiStack s;
//    create(s);
//    for (int i = 0; i < 10; ++i) {
//        push(s,i);
//    }
//    show(s);
//    LiQue q;
//    create(q);
//    for (int i = 0; i < 10; ++i) {
//        enQue(q,i);
//    }
//    show(q);
    //BubbleSort(a,len(a));

//    int aq =3;
//    swap(aq, aq);
//    cout<< aq << " "<< aq;
    Show(a, len(a));
    HeapSort(a,len(a));
    Show(a,len(a));
;

}
#endif //DATA_STRUCTURE_DOING_H
