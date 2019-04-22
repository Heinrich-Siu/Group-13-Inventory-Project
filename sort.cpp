#include <iostream>
//#include <string>
#include "sort.h"

void swap(commodity *xp, commodity *yp)
{
    commodity temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(commodity *arr, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].name < arr[min_idx].name)
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(arr+min_idx, arr+i);
    }
}

void sortingInventory(commodity *shopPtr, int numberOfCommodity)
{
    /*int choice = 0;
    cout << endl;
    cout << "Sort by: 1. Name\n"
            "         2. Price\n";
    cin >> choice;
    */

    //std::sort(shopPtr, shopPtr+numberOfCommodity, compareName);
    selectionSort(shopPtr, numberOfCommodity);
}

bool compareName(commodity *a, commodity *b)
{
    return (a->name) < (b->name);
}
