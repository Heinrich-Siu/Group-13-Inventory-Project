#ifndef PRINTER_h
#define PRINTER_h
#include "inventorysys.h"

//function prototype
void optionPrinter(int i);

void specPrinter(int i, commodity * product);

void recordPrinter(commodity * product, int * fields);

void inventoryShower(commodity * shopPtr, int numberOfCommodity);

//End of function print inventory

void recordChangePrompt();

void recordPrinterByIndex(commodity * shopPtr, int index);

//end of record changing prompts

void inventorySpacePrinter(int totalOcuppiedSpace, int inventorySpace);

//end of inventory space printer

void checkRecordUIPrinter();

void dayStrtoInt(std::string date, int &year, int &month, int &day);

void searchBefore_checkRecord(commodity* shopPtr, int numberOfCommodity, int &targetRecordIndex);

void returnPastNMonth(tm fromDate, tm *&desireMonth, int numOfMonth);

void salesPrinterPerRecord(salesRecord *salesRec);

void restockPrinterPerRecord(restockRecord *restockRec);

void storeBeforePrint_sales(salesRecord *&temp_record, int &temp_record_num, salesRecord *salesRec);

void storeBeforePrint_restock(restockRecord *&temp_record, int &temp_record_num, restockRecord *restockRec);

void wholeSalesHistoryPrinter(commodity *shopPtr, int index);

void wholeRestockHistoryPrinter(commodity *shopPtr, int index);

void nMonthPrinter(commodity *shopPtr, int index, tm fromDate, int numOfMonth, bool isSlaes);

void historyCheck(commodity *shopPtr, int numberOfCommodity, bool isSales);

//end of history check

#endif
