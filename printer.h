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

//void threeMonthPrinter(commodity *shopPtr, int index, tm fromDate);

void returnPastNMonth(tm fromDate, tm *&desireMonth, int numOfMonth);

void storeBeforePrint_sales(salesRecord *&temp_record, int &temp_record_num, salesRecord *salesRec);

void nthMonthPrinter_sales(commodity *shopPtr, int index, tm fromDate, int numOfMonth);

void salesPrinterPerRecord(salesRecord *salesRec);

void wholeSalesHistoryPrinter(commodity *shopPtr, int index);

void checkSalesHistory(commodity *shopPtr, int numberOfCommodity);

void restockPrinterPerRecord(restockRecord *restockRec);

void storeBeforePrint_restock(restockRecord *&temp_record, int &temp_record_num, restockRecord *restockRec);

void nthMonthPrinter_restock(commodity *shopPtr, int index, tm fromDate, int numOfMonth);

void wholeRestockHistoryPrinter(commodity *shopPtr, int index);

void checkRestockHistory(commodity *shopPtr, int numberOfCommodity);

#endif
