#ifndef INVENTORYSYS_h
#define INVENTORYSYS_h

#include <string.h>
#include <time.h>

struct salesRecord
{
    tm date;
    int quantity;

};

struct restockRecord
{
    tm deliveryTime;
    int quantity;
};

struct commodity
{
    int index;  //0
    int productCode;  //1
    std::string name;  //2
    double price;  //3
    double stockNum;  //4
    int stockSize;  //5   //in unit size, for calculating used inventory space
    int numOfSalesRec;
    salesRecord *salesRec; //6  //Struct salesRecord //Whole history with time(day) and quantity //lastSales(string) through function
    //format int file:start with num of record(int) first, then date format: "YYYY-(M)M-(M)D" example: 2019-12-5 or 2019-3-24
    int numOfRestoreRec;
    restockRecord *restockRec; //7  //delivery time and quantity //tm struct //lastRestock(string) through function //pastDeliveryRecord(string) through function
    double taxAmount; //8
    std::string manufacturer; //9
};


#endif
