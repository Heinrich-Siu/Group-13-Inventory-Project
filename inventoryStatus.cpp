#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <ctime>
//#include "inventorysys.h"
#include "printer.h"
#include "controlrecord.h"
#include "searcher.h"
#include "inventoryStatus.h"
#include "readrecord.h"
using namespace std;

void stockPrinter(commodity *product);
double salesAmount(commodity *shopPtr, int index, tm fromDate, int numOfMonth);
void tdayStrtoInt(string date, tm &fromDate);
void salesPrediction(commodity* shopPtr, int numberOfCommodity);
void outOfStockAlert(commodity *shopPtr, int numberOfCommodity);
void stockStatus(commodity *shopPtr, int numberOfCommodity);
void reduce_commodityRecord(commodity *&shopPtr, int originSize, int target);
void deleteOutDatedCommodity(commodity *& shopPtr, int &numberOfCommodity);
void checkInventoryStatus(commodity*&shopPrt, int &numberOfCommodity);


void stockPrinter(commodity *product){
    cout.width(10); cout<<left<<product->index;
    cout.width(15); cout<<left<<product->productCode;
    cout.width(20); cout<<left<<product->name;
    cout.width(20); cout<<left<<product->stockNum;
}

double salesAmount(commodity *shopPtr, int index, tm fromDate, int numOfMonth)
{
    tm *desireMonth = 0;
    salesRecord *temp_record = 0;
    int temp_record_num = 0;
    double totalSales = 0;
    returnPastNMonth(fromDate, desireMonth, numOfMonth);
    
    for(int j=0; j<numOfMonth; j++)
    {
        for(int i=shopPtr[index].numOfSalesRec-1; i>=0; i--) //loop from last record to first because of most recent order
        {
            if(desireMonth[j].tm_year == shopPtr[index].salesRec[i].date.tm_year && desireMonth[j].tm_mon == shopPtr[index].salesRec[i].date.tm_mon)
            {
                storeBeforePrint_sales(temp_record, temp_record_num, shopPtr[index].salesRec+i);
            }
        }
    }
    for(int i=0; i<temp_record_num; i++)
    {
        totalSales += temp_record[i].quantity;
    }
    
    delete [] temp_record;
    delete [] desireMonth;
    
    return totalSales;
}

void tdayStrtoInt(string date, tm &fromDate)
{
    int columns = 0;
    string temp;
    istringstream dateStr (date); //tramsform the string to the restock structure
    while(getline(dateStr, temp, '-'))
    {
        switch (columns) {
            case 0:
                fromDate.tm_year = stoi(temp);
                break;
            case 1:
                fromDate.tm_mon = stoi(temp);
                break;
        }
        columns++;
    }
}

void salesPrediction(commodity* shopPtr, int numberOfCommodity){
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;

    
    string date;
    cout<<"\nNote: the current month will be included in the prediction"<<endl;
    cout << "Enter current date in (YYYY-MM, e.g. 2019-12) format: ";
    cin >> date;
    
    int month;
    cout<<"Choose the number of month(s) for prediction: ";
    cin>>month;
    
    tdayStrtoInt(date, fromDate);
    
    cout.width(10); cout<<left<<"Index";
    cout.width(15); cout<<left<<"Product Code";
    cout.width(20); cout<<left<<"Name";
    cout.width(20); cout<<left<<"Current stock";
    string predict ="Predicted sales in "+to_string(month)+" month";
    cout<<predict;
    cout<<endl;
    double average;
    for (int i=0; i<numberOfCommodity; i++) {
        average = salesAmount(shopPtr, i, fromDate, month)/month;
        stockPrinter(&shopPtr[i]);
        cout.width(20); cout<<left<<average;
        cout<<endl;
    }
    cout<<endl;
}

void outOfStockAlert(commodity *shopPtr, int numberOfCommodity){
    bool hasPrinted = false;
    for (int i=0; i<numberOfCommodity; i++) {
        if (shopPtr[i].stockNum==0) {
            if (!hasPrinted) {
                cout<<"\nOut of stock warning: \n";
                cout.width(10); cout<<left<<"Index";
                cout.width(15); cout<<left<<"Product Code";
                cout.width(20); cout<<left<<"Name";
                cout<<"Number of stock";
                cout<<endl;
                hasPrinted=true;
            }
            stockPrinter(&shopPtr[i]);
            cout<<endl<<endl;
        }
    }
}

void stockStatus(commodity *shopPtr, int numberOfCommodity){
    //Out of stock first
    
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;
    
    string date;
    cout<<"\nNote: the current month will be included in the prediction"<<endl;
    cout << "Enter current date in (YYYY-MM, e.g. 2019-12) format: ";
    cin >> date;
    tdayStrtoInt(date, fromDate);
    
    int month;
    cout<<"Choose the number of month(s) for prediction: ";
    cin>>month;
    
    outOfStockAlert(shopPtr, numberOfCommodity);

    bool hasPrinted = false;
    cout<<"\nPredicted out of stock warning: \n";
    
    double average;
    for (int j=0; j<numberOfCommodity; j++) {
        average = salesAmount(shopPtr, j, fromDate, month)/month;
        if ((shopPtr[j]).stockNum<average){
            if (!hasPrinted) {
                cout.width(10); cout<<left<<"Index";
                cout.width(15); cout<<left<<"Product Code";
                cout.width(20); cout<<left<<"Name";
                cout.width(20); cout<<left<<"Current stock";
                string predict ="Predicted sales in "+to_string(month)+" month";
                cout.width(30); cout<<left<<predict;
                cout.width(20); cout<<left<<"Difference";
                cout<<endl;
                hasPrinted=true;
            }
            stockPrinter(&shopPtr[j]);
            cout.width(30); cout<<left<<average;
            cout.width(20); cout<<left<<shopPtr[j].stockNum-average;
            cout<<endl;
        }
    }
    if (!hasPrinted) {
        cout<<"\nNo out of stock warning!\n";
    }
}


void reduce_commodityRecord(commodity *&shopPtr, int originSize, int target)
{
    commodity *grownRecordPtr = new commodity[originSize-1];
    int j=0;
    for(int i=0; i<originSize; i++){ //transfer data from the old array to the new one
        if (i!=target) {
            grownRecordPtr[j] = shopPtr[i];
            j++;
        }
    }
    delete [] shopPtr; //free original Dynamic array in shopPtr
    
    shopPtr = grownRecordPtr; //point shopPtr pointer to the new grown Dynamic array
}


void deleteOutDatedCommodity(commodity *& shopPtr, int &numberOfCommodity){
    cout<<"\nSearching for outdated commodity\n";
    cout<<"Delete commodity without sales in the last n months"<<endl;
    cout<<"Enter value of n: ";
    int month;
    cin>>month;
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;

    string date;
    cout << "From when (YYYY-MM, e.g. 2019-12) to "<<month<<" months before: ";
    cin >> date;
    tdayStrtoInt(date, fromDate);
    
    bool hasChanged = false;
    bool nothing = true;

    
    for (int i=0; i<numberOfCommodity; i++) {
        if (salesAmount(shopPtr, i, fromDate, month)==0){
            //prompt if delete
            cout<<"Are you sure to delete "<<shopPtr[i].name<<"?"<<endl;
            cout<<"Enter Yes or No by (Y/N): ";
            string yesNo;
            cin>>yesNo;
            if (yesNo=="Y") {
                reduce_commodityRecord(shopPtr, numberOfCommodity, i);
                numberOfCommodity-=1;
                i--;
                hasChanged=true;
                cout<<"Selected commodity deleted!\n";
            }
            nothing=false;
        }
    }
    if (nothing) cout<<"\nNo commodity to be deleted!";
    else if (hasChanged) cout<<"\nOutdated commodity deleted";
    else cout<<"\nNo commodity deleted";
}

void checkInventoryStatus(commodity*&shopPtr, int &numberOfCommodity){
    int choice=0;
    while (choice!=4) {
        cout<<"1. Show stock status\n"
        "2. Show sales prediciton\n"
        "3. Delete obsoleted commodity\n"
        "4. Quit\n";
        cout<<"Enter your choice here: ";
        cin>>choice;
        if (choice==1){
            cout<<"\nShowing stock status:\n";
            stockStatus(shopPtr, numberOfCommodity);
            cout<<endl;
        }
        else if (choice==2){
            salesPrediction(shopPtr, numberOfCommodity);
        }
        else if (choice==3){
            deleteOutDatedCommodity(shopPtr, numberOfCommodity);
            indexer(shopPtr, numberOfCommodity);
            cout<<endl<<endl;
        }
        else{
            break;
        }
    }
}
