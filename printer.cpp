#include <iostream>
#include <string>
#include <limits>
//#include "inventorysys.h"
#include "printer.h"

using namespace std;

//function prototype
void optionPrinter(int i);

void specPrinter(int i, commodity * product);

void recordPrinter(commodity * product, int * fields);

void inventoryShower(commodity * shopPtr, int numberOfCommodity);
//

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

void recordPrinter(commodity * product, int * fields){
    //a specific commodity is pass to this function by product
    //print the aspects of product in sequence
    for (int i=0; (fields[i])!=-1; i++) specPrinter(fields[i], product);
    cout<<endl;
}

void inventoryShower(commodity * shopPtr, int numberOfCommodity){ //"1. Show all inventory record\n"
    cout<<"Choose what to show in sequence and enter -1 when done\n"<<"Here are the options: \n";
    cout<<"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL\n";
    int* fields = new int[11]; //dynamic array that store the aspects need to print
    int a=0, all=-1;
    for (int k=0; a!=-1; k++) { //load in different aspects from user
        cin>>a;
        if (a==11)all=1; break;
        fields[k] = a;
    }
    if (all){//print all
        for (int i=0; i<11; i++) fields[i]=i;
        fields[11]=-1;
    }
    for (int i=0; (fields[i])!=-1; i++) optionPrinter(fields[i]); //print the columns
    cout<<endl;
    for (int i=0; i<numberOfCommodity; i++) recordPrinter(shopPtr+i,fields); //print the data one by one
    delete [] fields;
}


//input: pointer to salesRecord array, and number of sales record
void salesRecordPrinter(salesRecord *salesRec, int numOfSalesRec)
{
    cout.width(6); cout << "Year";
    cout.width(4); cout << "Moth";
    cout.width(4); cout << "Day";
    cout.width(4); cout << "Quantity";
    cout << endl;
    for(int i=0; i<numOfSalesRec; i++)
    {
        cout.width(6); cout << salesRec[i].date.tm_year;
        cout.width(4); cout << salesRec[i].date.tm_mon;
        cout.width(4); cout << salesRec[i].date.tm_mday;
        cout.width(4); cout << salesRec[i].quantity;
        cout << endl;
    }
}

//input: pointer to restockRecord array, and number of sales record
void restockRecordPrinter(restockRecord *restockRec, int numOfRestockRec)
{
    cout.width(6); cout << "Year";
    cout.width(4); cout << "Moth";
    cout.width(4); cout << "Day";
    cout.width(4); cout << "Quantity";
    cout << endl;
    for(int i=0; i<numOfRestockRec; i++)
    {
        cout.width(6); cout << restockRec[i].deliveryTime.tm_year;
        cout.width(4); cout << restockRec[i].deliveryTime.tm_mon;
        cout.width(4); cout << restockRec[i].deliveryTime.tm_mday;
        cout.width(4); cout << restockRec[i].quantity;
        cout << endl;
    }
}

void recordPrinterByIndex(commodity * shopPtr, int index)
{
  for (int i=1; i<=9; i++)
      optionPrinter(i); //print the columns

  cout<<endl;

  for (int i=1; i<=9; i++)
      specPrinter(i, shopPtr+index); //print the data in structure one by one
}
