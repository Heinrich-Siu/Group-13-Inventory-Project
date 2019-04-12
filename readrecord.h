#ifndef READRECORD_h
#define READRECORD_h

void readSalesRecord(salesRecord *&thisRecord, string line, int &numOfRec);

void readRestockRecord(restockRecord *&thisRecord, string line, int &numOfRec);

void readCSVinventoryRecord(commodity &commod, string line);

void grow_commodityRecord(commodity *&shopPtr, int originSize, int grownSize);

void loadAllRecord(commodity * &shopPtr, int &numberOfCommodity);

#endif
