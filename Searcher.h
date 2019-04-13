//
//  Searcher.h
//  1340 project testing ground
//
//  Created by Heinrich Siu on 10/4/2019.
//  Copyright © 2019 Heinrich Siu. All rights reserved.
//

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
