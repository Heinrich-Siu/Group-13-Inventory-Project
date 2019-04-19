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

void inventorySpacePrinter(int totalOcuppiedSpace, int inventorySpace);

void searchBefore_checkRecord(commodity* shopPtr, int numberOfCommodity, int &targetRecordIndex);

void checkRecordUIPrinter();

void dayStrtoInt(std::string date, int &year, int &month, int &day);

void wholeHistoryPrinter(commodity * &shopPtr, int index);

void checkSalesHistory(commodity * &shopPtr, int &numberOfCommodity);

#endif
