#include <iostream>
#include "LinkedList.h"
#include "BTree.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main () {
    int a[10] = {3, 24, 35, 61, 27, 16, 28, 39, 12, 10};
    char t[] = {
            'A', 'B', 'C', 'D', '#', '#', '#', 'F', 'E', '#', '#',
            'G', 'H', '#', 'I', '#', '#', '#'
    };
    // LinkedList L;
    // createHead(L, a, 11);
    // show(L);
    // Heap(a,end(a) - begin(a));
    // Show(a,end(a) - begin(a));
     BTree tree;
     grow(tree,t);
     Pre(tree);


    system("pause");
    return 0;
}