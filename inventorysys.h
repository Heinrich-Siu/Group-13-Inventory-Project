#ifndef INVENTORYSYS_h
#define INVENTORYSYS_h

#include <string>
#include <time.h>


/*
 stuct tm
 tm_sec    int    seconds after the minute    0-60*
 tm_min    int    minutes after the hour    0-59
 tm_hour    int    hours since midnight    0-23
 tm_mday    int    day of the month    1-31
 tm_mon    int    months since January    0-11
 tm_year    int    years since 1900
 tm_wday    int    days since Sunday    0-6
 tm_yday    int    days since January 1    0-365
 */

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
    int numOfRestockRec;
    restockRecord *restockRec; //7  //delivery time and quantity //tm struct //lastRestock(string) through function //pastDeliveryRecord(string) through function
    double taxAmount; //8
    std::string manufacturer; //9
};




#endif
