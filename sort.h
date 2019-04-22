#ifndef SORT_h
#define SORT_h
#include "inventorysys.h"


void swap(commodity *xp, commodity *yp);
void selectionSort(commodity *arr, int n);
void sortingInventory(commodity *shopPtr, int numberOfCommodity);
bool compareName(commodity *a, commodity *b);

#endif
