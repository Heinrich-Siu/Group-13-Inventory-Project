#ifndef INVENTORYSYS_h
#define INVENTORYSYS_h

#include <string.h>


struct commodity
{
    int index;
    std::string name;
    double price;
    double stockNum;
    double salesRec[3] = {0}; // 0: 3 months; 1: 6 months; 2: 1 year; 3: Whole history
    std::string lastRestock = "N/A";
    std::string lastSales = "N/A";
    int pastDeliveryRecord; //time from order to in inventory
    double taxAmount;
    std::string manufacturer;
    int productCode;
};

void printUI();

#endif
