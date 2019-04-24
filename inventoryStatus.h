#ifndef inventoryStatus_h
#define inventoryStatus_h
#include "inventorysys.h"
#include <stdio.h>
void stockPrinter(commodity *product);
void salesAverage(commodity *shopPtr, int index, tm fromDate, int numOfMonth, double &average);
void tdayStrtoInt(std::string date, tm &fromDate);
void salesPrediction(commodity* shopPtr, int numberOfCommodity);
void stockStatus(commodity *shopPtr, int numberOfCommodity);
void checkInventoryStatus(commodity* shopPrt, int numberOfCommodity);

#endif /* inventoryStatus_h */
