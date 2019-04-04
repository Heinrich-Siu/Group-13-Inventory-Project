#ifndef INVENTORYSYS_h
#define INVENTORYSYS_h

#include <string.h>

struct tm
{

};


struct commodity
{
    int index;
    int productCode;
    std::string name;
    double price;
    double stockNum;
    int stockSize;  //in unit size, for calculating used inventory space
    salesRecord salesRec[3] = {0}; //Struct salesRecord //Whole history with time(day) and quantity //lastSales(string) through function
    tm restockRec[]; //delivety time and quantity //tm struct //lastRestock(string) through function //pastDeliveryRecord(string) through function
    double taxAmount;
    std::string manufacturer;
};


#endif
