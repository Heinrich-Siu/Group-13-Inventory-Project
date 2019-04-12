#include <iostream>
#include <string>
#incldue "inventorysys.h"

void optionPrinter(int i){ //print the columns
    switch (i) {
            //"1. Index 2.ProductCode 3.Name 4.Price 5.StockNum 6.StockSize 7.NumOfSalesRec 8.numOfRestockRec"
        case 1:
            cout.width(10); cout<<left<<"Index";
            break;
        case 2:
            cout.width(15); cout<<left<<"Product Code";
            break;
        case 3:
            cout.width(20); cout<<left<<"Name";
            break;
        case 4:
            cout.width(10); cout<<left<<"Price";
            break;
        case 5:
            cout.width(15); cout<<left<<"Stock Number";
            break;
        case 6:
            cout.width(15); cout<<left<<"Stock Size";
            break;
        case 7:
            cout.width(21); cout<<left<<"Number of Sales Record";
            break;
        case 8:
            cout.width(24); cout<<left<<"Number of Restock Record";
            break;

        default:
            break;
    }
}
void specPrinter(int i, commodity * product){ //print product info according to request
    switch (i) {
            //"1. Index 2.ProductCode 3.Name 4.Price 5.StockNum 6.StockSize 7.NumOfSalesRec 8.numOfRestockRec"
        case 1:
            cout.width(10); cout<<left<<product->index;
            break;
        case 2:
            cout.width(15); cout<<left<<product->productCode;
            break;
        case 3:
            cout.width(20); cout<<left<<product->name;
            break;
        case 4:
            cout.width(10); cout<<left<<product->price;
            break;
        case 5:
            cout.width(15); cout<<left<<product->stockNum;
            break;
        case 6:
            cout.width(15); cout<<left<<product->stockSize;
            break;
        case 7:
            cout.width(21); cout<<left<<product->numOfSalesRec;
            break;
        case 8:
            cout.width(24); cout<<left<<product->numOfRestockRec;
            break;

        default:
            break;
    }
}
