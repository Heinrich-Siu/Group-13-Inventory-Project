#ifndef inventoryStatus_h
#define inventoryStatus_h

#include <stdio.h>
void stockPrinter(commodity *product, double predictedSales);
void salesAverage(commodity *shopPtr, int index, tm fromDate, int numOfMonth);
void tdayStrtoInt(std::string date, tm &fromDate);
void checkInventoryStatus(commodity* shopPrt, int numberOfCommodity);

#endif /* inventoryStatus_h */
