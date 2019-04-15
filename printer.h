#ifndef PRINTER_h
#define PRINTER_h
#include "inventorysys.h"

void optionPrinter(int i);

void specPrinter(int i, commodity * product);

void recordPrinter(commodity * product, int * fields);

void inventoryShower(commodity * shopPtr, int numberOfCommodity);

void salesRecordPrinter(salesRecord *salesRec, int numOfSalesRec);

void restockRecordPrinter(restockRecord *restockRec, int numOfRestockRec);

void recordPrinterByIndex(commodity * shopPtr, int index);

#endif
