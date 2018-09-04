//
// Created by Merediii on 2018/4/16.
//

#ifndef DATA_STRUCTURE_BTREE_H
#define DATA_STRUCTURE_BTREE_H
#define maxSize 1000

#include <malloc.h>
#include <iostream>

using namespace std;
typedef struct BTNode {
    char data;
    struct BTNode *lchild, *rchild;
} BTNode, *BTree;

void grow (BTree &t) {
    char c;
    cin >> c;
    if (c == '#')
        t = NULL;
    else {
        t = (BTree) malloc(sizeof(BTNode));
        t->data = c;
        grow(t->lchild);
        grow(t->rchild);
    }
}

void grow (BTree &t, char a[], int n) {
    int static i = 0;
    if (a[i] == '#')
        if (a[i] == '#') {
            t = NULL;
        } else {
            t = (BTree) malloc(sizeof(BTNode));
            t->data = a[i];
            cout << " " << t->data << a[i] << " " << i << " " << endl;
            grow(t->lchild, a, i++);
            grow(t->rchild, a, i++);
        }
}

void grow (BTree &t, char a[]) {
    int static i = 0;
//	cout<<i<<endl;
    if (a[i] == '#') {
        t = NULL;
    } else {
        t = (BTree) malloc(sizeof(BTNode));
        t->data = a[i];
//		cout<<" "<<t->data<<a[i]<<" "<<i<<" "<<endl;
        i++;
        grow(t->lchild, a);
        i++;
        grow(t->rchild, a);
    }
}

void InO (BTree t) {
    if (!t)
        return;
    InO(t->lchild);
    cout << t->data << " ";
    InO(t->rchild);
}

void Pre (BTree t) {
    if (!t)
        return;
    cout << t->data << " ";
    Pre(t->lchild);
    Pre(t->rchild);
}

void Post (BTree t) {
    if (!t)
        return;
    Post(t->lchild);
    Post(t->rchild);
    cout << t->data << " ";
}

void LineO (BTree t) {
    BTNode *que[maxSize], *q;
    int front = 0, rear = 0;
    que[rear++] = t;
    while (front != rear) {
        q = que[front++];
        cout << q->data << " ";
        if (q->lchild)
            que[rear++] = q->lchild;
        if (q->rchild)
            que[rear++] = q->rchild;
    }
    cout << endl;
}

int Height (BTree t) {
    if (!t)
        return 0;
    int LHeight = Height(t->lchild);
    int RHeight = Height(t->rchild);
    return 1 + (LHeight >= RHeight ? LHeight : RHeight);
}

int DegreeIs2 (BTree t) {
    if (!t)
        return 0;
    if (t->lchild != NULL && t->rchild != NULL)
        return 1 + DegreeIs2(t->lchild) + DegreeIs2(t->rchild);
    return DegreeIs2(t->lchild) + DegreeIs2(t->rchild);
}

int DegreeIs1 (BTree t) {
    if (!t)
        return 0;
    if ((t->lchild != NULL && t->rchild == NULL) || (t->lchild == NULL && t->rchild != NULL))
        return 1 + DegreeIs1(t->lchild) + DegreeIs1(t->rchild);
    else
        return DegreeIs1(t->lchild) + DegreeIs1(t->rchild);
}

int leaves (BTree t) {
    if (!t)
        return 0;
    if (t->lchild == NULL && t->rchild == NULL)
        return 1;
    else
        return leaves(t->lchild) + leaves(t->rchild);
}

int width (BTree t) {
    int last = 1, num = 0, max = 0, rear = 0, front = 0;
    BTNode *que[maxSize], *q;
    if (!t)
        return 0;
    que[rear++] = t;
    while (front != rear) {
        q = que[front++];
        num++;
        if (q->lchild)
            que[rear++] = q->lchild;
        if (q->rchild)
            que[rear++] = q->rchild;
        if (front == last) {
            last = rear;
            max = (num > max ? num : max);
            num = 0;
        }
    }
    return max;
}

void reflect (BTree t) {
    BTNode *p;
    if (!t)
        return;
    reflect(t->lchild);
    reflect(t->rchild);
    p = t->lchild;
    t->lchild = t->rchild;
    t->rchild = p;
}

int depth (BTree t) {
    if (!t)
        return 0;
    return 1
           + (depth(t->lchild) >= depth(t->rchild) ?
              depth(t->lchild) : depth(t->rchild));
}

void PreS (BTree t) {
    if (!t)
        return;
    BTNode *s[maxSize], *p;
    p = t;
    int top = -1;
    s[++top] = t;
    while (top != -1) {
        p = s[top--];
        cout << p->data << " ";
        if (p->rchild) {
            s[++top] = p->rchild;
        }
        if (p->lchild) {
            s[++top] = p->lchild;
        }
    }
    cout << endl;
}

void InOS (BTree t) {
    if (!t)
        return;
    BTNode *s[maxSize], *p;
    p = t;
    int top = -1;
    while (top != -1 || p) {
        while (p) {
            s[++top] = p;
//			cout<<"while "<<p->data<<" get in top is "<<top<<endl;
            p = p->lchild;
        }
        if (top != -1) {
            p = s[top--];
//			cout<<"if "<<p->data<<" get out top is "<<top<<endl;
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    cout << endl;
}

void PostS (BTree t) {
    if (!t)
        return;
    BTNode *s[maxSize], *u[maxSize], *p;
    int tops = -1, topu = -1;
    p = t;
    s[++tops] = p;
    while (tops != -1) {
        p = s[tops--];
        u[++topu] = p;
        if (p->lchild)
            s[++tops] = p->lchild;
        if (p->rchild)
            s[++tops] = p->rchild;
    }
    while (topu != -1) {
        cout << u[topu--]->data << " ";
    }
    cout << endl;
}

int sum (BTree t) {
    if (!t)
        return 0;
    return 1 + sum(t->lchild) + sum(t->rchild);
}

void HeightPrint (BTree t) {
    BTNode *que[maxSize], *q;
    int level = 1, a = 0, l = 1, front = 0, rear = 0;
    que[rear++] = t;
    while (front != rear) {
        q = que[front++];
        a++;
        if (a == 1)
            cout << level << " ";
        cout << q->data << " ";
        if (q->lchild)
            que[rear++] = q->lchild;
        if (q->rchild)
            que[rear++] = q->rchild;
        if (l == front) {
            l = rear;
            level++;
            cout << a << endl;
            a = 0;
        }
    }
    cout << endl;
}

void levelOfx (BTree t, char x) {
    if (!t)
        return;
    static int i = 1;
    if (t->data == x)
        cout << i << endl;
    i++;
    levelOfx(t->lchild, x);
    levelOfx(t->rchild, x);
    i--;
}

void LeavesRoutine (BTree t) {
    if (!t)
        return;
//	path[top++] = t->data;
    if (t->lchild == NULL && t->rchild == NULL)
        cout << t->data;
    LeavesRoutine(t->lchild);
    LeavesRoutine(t->rchild);
//	top--;
}

BTNode *DathVader (BTree t, BTNode *p) {
    if (!t)
        return NULL;
    if (t->lchild == p || t->rchild == p)
        return t;
    p = DathVader(t->lchild, p);
    if (p)
        return p;
    else
        return DathVader(t->rchild, p);
}

///*
int isComplete (BTree t) {
    BTNode *s[maxSize], *p;
    int front = 0, rear = 0, flag = 0;
    if (!t)
        return 1;
    s[rear++] = t;
    while (front != rear) {
        cout << rear << "->" << front << "->" << flag << " " << endl;
        p = s[front++];
        if (front == 4)
            if (p == NULL)
                cout << "p = " << "NULL ";
        if (p == NULL)
            cout << "front=" << front << " flag=" << flag << " " << endl;
        if (p == NULL)
            flag = 1;
        else if (flag)
            return 0;
        else {
            s[rear++] = p->lchild;
            s[rear++] = p->rchild;
        }
    }
    return 1;
}

#endif //DATA_STRUCTURE_BTREE_H
