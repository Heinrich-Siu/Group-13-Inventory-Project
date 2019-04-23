#ifndef SORT_h
#define SORT_h
#include "inventorysys.h"


void swap(commodity *xp, commodity *yp);
bool compareParameter(commodity *arr, int j, int min_idx, int option, int order)
void selectionSort(commodity *arr, int n, int choice, int order);
void sortMenu();
void orderMenu();
void sortingInventory(commodity *shopPtr, int numberOfCommodity);


#endif
