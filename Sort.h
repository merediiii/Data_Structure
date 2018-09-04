//
// Created by Merediii on 2018/4/16.
//

#ifndef DATA_STRUCTURE_SORT_H
#define DATA_STRUCTURE_SORT_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

void InsertSort(int R[], int n)
{
    int a, i, j;
    for (i = 1; i < n; ++i)
    {
        a = R[i];
        j = i - 1;
        while (j >= 0 && a < R[j])
        { //
            R[j + 1] = R[j];
            j--;
        }
        R[j + 1] = a;
    }
}

void binInsertSort(int R[], int n)
{
    int a, i, j, m, l, h;
    for (i = 1; i < n; i++)
    {
        a = R[i];
        l = 0;
        h = i - 1;
        while (h >= l)
        {
            m = (l + h) / 2;
            if (R[m] > a) //
                h = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--)
            R[j + 1] = R[j];
        R[l] = a;
    }
}

void BubbleSort(int R[], int n)
{
    int i, j, a, flag;
    for (i = n - 1; i >= 1; i--)
    {
        flag = 0;
        for (j = 1; j <= i; j++)
            if (R[j - 1] > R[j])
            {
                a = R[j];
                R[j] = R[j - 1];
                R[j - 1] = a;
                flag = 1;
            }
        if (flag == 0)
            return;
    }
}

void QuickSort(int R[], int l, int h)
{
    int a, i = l, j = h;
    if (l < h)
    {
        a = R[l];
        while (i != j)
        {
            while (j > i && R[j] >= a)
                j--;
            if (i < j)
            {
                R[i] = R[j];
                i++;
            }
            while (j > i && R[i] < a)
                i++;
            if (i < j)
            {
                R[j] = R[i];
                j--;
            }
        }
        R[i] = a;
        QuickSort(R, l, i - 1);
        QuickSort(R, i + 1, h);
    }
}

void SelectSort(int R[], int n)
{
    int i, j, k, a;
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (R[k] > R[j])
                k = j;
        a = R[i];
        R[i] = R[k];
        R[k] = a;
    }
}

void Sift(int R[], int l, int h)
{
    int a = R[l];
    int i = 2 * l + 1;
    while (i <= h)
    {
        if (i + 1 <= h && R[i + 1] > R[i])
            i++;
        if (R[i] <= a)
            break;
        R[l] = R[i];
        l = i;
        i = 2 * l + 1;
    }
    R[l] = a;
}

void HeapSort(int R[], int n)
{
    int i, a;
    for (i = n / 2 - 1; i >= 0; i--)
        Sift(R, i, n - 1);
    for (i = n - 1; i > 0; i--)
    {
        a = R[i];
        R[i] = R[0];
        R[0] = a;
        Sift(R, 0, i - 1);
    }
}


void Si(int R[], int l, int h)
{
    int a = R[l];
    int i = 2 * l;
    while (i <= h)
    {
        if (i < h && R[i] < R[i + 1])
            i++;
        if (R[i] > a)
        {
            R[l] = R[i];
            l = i;
            i = 2 * l;
        }
        else
            break;
    }
    R[l] = a;
}



void Heap(int R[], int n)
{
    int i, a;
    for (i = n / 2; i >= 1; i--)
        Sift(R, i, n);
    for (i = n; i >= 2; i--)
    {
        a = R[1];
        R[1] = R[i];
        R[i] = a;
        Si(R, 1, i - 1);
    }
}


#endif //DATA_STRUCTURE_SORT_H
