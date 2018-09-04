//
// Created by Merediii on 2018/4/16.
//

#ifndef DATA_STRUCTURE_LINKEDLIST_H
#define DATA_STRUCTURE_LINKEDLIST_H

#include <bits/stdc++.h>
#include "Sort.h"
#include <iostream>

using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkedList;

void getEle (LinkedList L, int i, int &e) {
    LinkedList p;
    p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        printf("Not Exsist");
    e = p->data;
}

int length (LinkedList L) {
    LNode *p;
    int n = 0;
    p = L;
    while (p->next) {
        n++;
        p = p->next;
    }
    return n;
}

void createHead (LinkedList L) {
    LinkedList p, q;
    int n;
    cout << "输入链表长度:";
    cin >> n;
    L = (LinkedList) malloc(sizeof(LNode));
    L->next = NULL;
    p = L;
    for (int i = 0; i < n; i++) {
        q = (LinkedList) malloc(sizeof(LNode));
        scanf("%d", &q->data);
        p->next = q;
        p = q;
    }
    p->next = NULL;
}

void createHead (LinkedList &L, int R[], int n) {
    LinkedList p, q;
    L = (LinkedList) malloc(sizeof(LNode));
    L->next = NULL;
    p = L;
    for (int i = 0; i < n; i++) {
        q = (LinkedList) malloc(sizeof(LNode));
        q->data = R[i];
        p->next = q;
        p = q;
    }
    p->next = NULL;
}

void create (LinkedList &L) {
    LinkedList p;
    int n;
    cout << "输入链表长度:";
    cin >> n;
    L = (LinkedList) malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        p = (LinkedList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

void create (LinkedList &L, int R[], int n) {
    LinkedList p;
    L = (LinkedList) malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        p = (LinkedList) malloc(sizeof(LNode));
        p->data = R[n - 1 - i];
        p->next = L->next;
        L->next = p;
    }
}

void Show (int a[], int n) {
    int i = 0;
    for (; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void show (LinkedList &L) {
    LinkedList p;
    p = L->next;
    int i = 1;
    cout << "HEAD";
    while (p != NULL) {
        //printf("第%d个元素为:%d\n", i++, p->data);
        printf("->%d", p->data);
        p = p->next;
    }
    printf("\n");
}

void Merge (LNode *a, LNode *b, LNode *&c) {
    LNode *p = a->next;
    LNode *q = b->next;
    LNode *r;
    c = a;
    c->next = NULL;
    free(b);
    r = c;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
            r = r->next;
        } else {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    r->next = NULL;
    if (p != NULL)
        r->next = p;
    if (q != NULL)
        r->next = q;
}

void delII (LinkedList &L, int x) {
    LNode *p = L, *q = p;
    if (!L)
        return;
    if (L->data == x) {
        L = L->next;
        free(p);
        delII(L, x);
    } else
        delII(L->next, x);
}

void del (LinkedList &L, int x) {
    LNode *p = L->next, *pre = L, *r;
    while (p) {
        if (p->data == x) {
            r = p;
            p = p->next;
            pre->next = p;
            free(r);
        } else
            pre = p;
        p = p->next;
    }
}

void print (LinkedList L) {
    if (L->next) {
        print(L->next);
    }
    cout << L->data << endl;
}

void delTheMin (LinkedList &L) {
    LNode *p = L->next, *pre = L, *q = p, *qpre = pre;
    while (p != NULL) {
        if (p->data < q->data) {
            q = p;
            qpre = pre;
        }
        pre = p;
        p = p->next;
    }
    qpre->next = q->next;
    free(q);
}

LinkedList Reverse (LinkedList &L) {
    LNode *q = L->next, *r;
    L->next = NULL;
    while (q) {
        r = q->next;
        q->next = L->next;
        L->next = q;
        q = r;
    }
    return L;
}

void Sort (LinkedList &L) {
    LNode *p = L->next;
    int n = length(L);
    int a[n] = {0};
    for (int i = 0; i < n; i++) {
        a[i] = p->data;
        p = p->next;
    }
    p = L->next;
    for (int i = 0; i < n; i++) {
        p->data = a[i];
        p = p->next;
    }
}

LinkedList Separate (LinkedList &L) {
    LNode *p = L->next;
    LinkedList J = (LinkedList) malloc(sizeof(LNode));
    J->next = NULL;
    LNode *a = L, *b = J;
    L->next = NULL;
    int i = 0;
    while (p) {
        i++;
        if (i % 2 == 0) {
            b->next = p;
            b = p;
        } else {
            a->next = p;
            a = p;
        }
        p = p->next;
    }
    a->next = NULL;
    b->next = NULL;
    return J;
}

void delTheSame (LinkedList &L) {
    LNode *p = L->next, *q;
    if (!p)
        return;
    while (p->next) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else
            p = p->next;
    }
}

void merge (LinkedList &La, LinkedList &Lb) {
    LNode *p = La->next, *q = Lb->next, *r;
    La->next = NULL;
    while (p && q) {
        if (p->data < q->data) {
            r = p->next;
            p->next = La->next;
            La->next = p;
            p = r;
        } else {
            r = q->next;
            q->next = La->next;
            La->next = q;
            q = r;
        }
    }
    if (p)
        q = p;
    while (q) {
        r = q->next;
        q->next = La->next;
        La->next = q;
        q = r;
    }
    free(Lb);
}

int pattern (LinkedList &La, LinkedList &Lb) {
    LNode *p = La->next, *q = Lb->next, *pre = p;
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = Lb->next;
        }
    }
    if (!q)
        return 1;
    return 0;
}

int SearchAtK (LinkedList &L, int k) {
    LNode *p = L->next, *q = p;
    int count = 0;
    while (p) {
        p = p->next;
        if (count < k)
            count++;
        else
            q = q->next;
    }
    if (count < k)
        return 0;
    cout << q->data << endl;
    return 1;
}

void conjoin (LinkedList &La, LinkedList &Lb) {
    LNode *p = La->next, *q = Lb->next, *ra, *rb;
    La->next = NULL;
    Lb->next = NULL;
    ra = La;
    rb = Lb;
    while (p && q) {
        if (p->data == q->data) {
            ra->next = p;
            ra = ra->next;
            rb->next = q;
            rb = rb->next;
            p = p->next;
            q = q->next;
        } else if (p->data < q->data) {
            ra->next = p;
            ra = ra->next;
            p = p->next;
        } else {
            ra->next = q;
            ra = ra->next;
            q = q->next;
        }
    }
}

void decompose (LinkedList &L, LinkedList &La, LinkedList &Lb) {
    LNode *p = L->next, *q;
    La = L;
    La->next = NULL;
    Lb = (LinkedList) malloc(sizeof(LNode));
    if (Lb == NULL) return;
    Lb->next = NULL;
    while (p != NULL) {
        q = p->next;
        if (p->data % 2 == 0) {
            p->next = La->next;
            La->next = p;
        } else {
            p->next = Lb->next;
            Lb->next = p;
        }
        p = q;
    }
}

int duicheng (LNode *p, int n) {
    int a[n / 2], i;
    for (i = 0; i < n / 2; i++) {
        a[i] = p->next->data;
        p = p->next;
    }
    i--;
    if (n % 2)
        p = p->next;
    while (p->next && a[i--] == p->data)
        p = p->next;
    if (i == -1)
        return 1;
    else
        return 0;
}

void sort (LNode *&h) {
    LNode *p, *s, *r;
    p = h->next;
    s = p->next;
    h->next = NULL;
    r = h;
    while (p) {
        if (r->next == NULL || r->next->data > p->data) {
            s = p->next;
            p->next = r->next;
            r->next = p;
            p = s;
            r = h;
        } else
            r = r->next;
    }
}

void Insertsort (LNode *L) {
    LNode *p, *q, *r, *u;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = L;
        q = L->next;
        while (q != NULL && q->data <= p->data) {
            r = q;
            q = q->next; //找到p插入的位置，比如有序序列为1、3、5，将4插入进去就是找到3，r就是所要找到的3
        }
        u = p->next;  //将4后面的数字，也就是下一个要插入的数字存起来
        p->next = r->next;  //将4插入到有序链表
        r->next = p;
        p = u; //将存起来的下一个要插入的数字给p进行下一次插入查找工作
    }
}

void fun (LNode *h) {
    LNode *p, *q;
    int t;
    p = h->next;
    while (p) {
        q = p->next;
        while (q) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}

#endif //DATA_STRUCTURE_LINKEDLIST_H
