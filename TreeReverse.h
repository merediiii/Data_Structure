//
// Created by Merediii on 2018/4/16.
//

#ifndef DATA_STRUCTURE_TREEREVERSE_H
#define DATA_STRUCTURE_TREEREVERSE_H

#include <iostream>

using namespace std;

void del(int a[], int n)
{
    int i = 1, j = 0, k = 0;
    for (; i < n; i++)
    {
        k = 0;
        while (k <= j && a[i] != a[i - 1])
            k++;
        if (k > j)
            j++;
        a[j] = a[i];
    }
}

void PreToPost(int a[], int b[], int s1, int t1, int s2, int t2)
{
    int n = t1 - s1 + 1, m = (n - 1) / 2;
    cout << n << " " << m << endl;
    if (n)
    {
        cout << s1 << " " << t1 << " " << s2 << " " << t2 << endl;
        b[t2] = a[s1];
        PreToPost(a, b, s1 + 1, s1 + m, s2, s2 + m - 1);
        cout << "=========================" << endl;
        PreToPost(a, b, t1 - m + 1, t1, t2 - m, t2 - 1);
    }
}

void PreToInO(int a[], int b[], int s1, int t1, int s2, int t2)
{
    int n = t1 - s1 + 1, m = (n - 1) / 2;
    if (n)
    {
        cout << s1 << " " << t1 << " " << s2 << " " << t2 << endl;
        b[(s2 + t2) / 2] = a[s1];
        PreToInO(a, b, s1 + 1, s1 + m, s2, s2 + m - 1);
        cout << "=========================" << endl;
        PreToInO(a, b, t1 - m + 1, t1, t2 - m + 1, t2);
    }
}

void InOToPre(int a[], int b[], int s1, int t1, int s2, int t2)
{
    int n = t2 - s2 + 1, m = (n - 1) / 2;
    if (n)
    {
        cout << s1 << " " << t1 << " " << s2 << " " << t2 << endl;
        b[s2] = a[(s1 + t1) / 2];
        InOToPre(a, b, s1, s1 + m - 1, s2 + 1, s2 + m);
        cout << "=========================" << endl;
        InOToPre(a, b, s1 + m + 1, t1, s2 + m + 1, t2);
    }
}

void InOToPost(int a[], int b[], int s1, int t1, int s2, int t2)
{
    if (t1 >= s1)
    {
        cout << s1 << " " << t1 << " " << s2 << " " << t2 << endl;
        b[t2] = a[(t1 + s1) / 2];
        int n = (t1 - s1) / 2;
        InOToPost(a, b, s1, s1 + n - 1, s2, s2 + n - 1);
        cout << "=========================" << endl;
        InOToPost(a, b, s1 + n + 1, t1, s2 + n, t2 - 1);
    }
}

void PostToPre(int a[], int b[], int s1, int t1, int s2, int t2)
{
    int n = t1 - s1 + 1, m = (n - 1) / 2;
    if (n)
    {
        cout << s1 << " " << t1 << " " << s2 << " " << t2 << endl;
        b[s2] = a[t1];
        PostToPre(a, b, s1, s1 + m - 1, s2 + 1, s2 + m);
        cout << "=========================" << endl;
        PostToPre(a, b, t1 - m, t1 - 1, t2 - m + 1, t2);
    }
}

void PostToInO(int a[], int b[], int s1, int t1, int s2, int t2)
{
    if (t2 >= s2)
    {
        cout << s1 << " " << t1 << " " << s2 << " " << t2 << endl;
        b[(t2 + s2) / 2] = a[t1];
        int n = (t2 - s2) / 2;
        PostToInO(a, b, s1, s1 + n - 1, s2, s2 + n - 1);
        cout << "=========================" << endl;
        PostToInO(a, b, s1 + n, t1 - 1, s2 + n + 1, t2);
    }
}

#endif //DATA_STRUCTURE_TREEREVERSE_H
