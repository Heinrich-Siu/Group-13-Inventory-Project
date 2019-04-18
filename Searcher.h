#ifndef Searcher_h
#define Searcher_h
#include <string.h>
#include "inventorysys.h"

void ranger(int &max, int &min, int absoulteMax);

double typeInNumberToValue(commodity* commod, int type);

std::string commdityStringValueReturn(commodity*commod, int type);

void searchingInDifferentWays(int type, int* &position, int numberOfCommodity, commodity * shopPtr); //search and destroy, "destroy" all items not meeting criteria

void search(commodity* shopPtr, int numberOfCommodity);


#endif /* Searcher_h */
