#ifndef CONTROLRECORD_h
#define CONTROLRECORD_h
#include "inventorysys.h"

void addCommodity(commodity* shopPtr, int &numberOfCommodity);

void changeRecord(commodity* shopPtr, int &numberOfCommodity);

void changeProductCode(commodity* shopPtr, int index);

void changeProductName(commodity* shopPtr, int index);

void changePrice(commodity* shopPtr, int index);

void changeSizeOfStock(commodity* shopPtr, int index);

void changeTaxAmount(commodity* shopPtr, int index);

void changeManufacturerName(commodity* shopPtr, int index);

void searchBefore_recordAdding(commodity* shopPtr, int numberOfCommodity, int &targetRecordIndex);

void addRestock(commodity* shopPtr, int index, int inventorySpace, int &totalOcuppiedSpace);

void addSales(commodity* shopPtr, int index, int inventorySpace, int &totalOcuppiedSpace);

void restockOrSales(commodity* shopPtr, int &numberOfCommodity, int inventorySpace, int &totalOcuppiedSpace);

void grow_record(salesRecord *&recordPtr, int originSize, int grownSize);

void grow_record(restockRecord *&recordPtr, int originSize, int grownSize);

void recordChangePrompt();

bool updateInventorySpace_inAddRecord(int addSize,int inventorySpace, int &totalOcuppiedSpace);



#endif
