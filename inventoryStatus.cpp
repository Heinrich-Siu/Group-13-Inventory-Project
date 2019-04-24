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
using namespace std;

void stockPrinter(commodity *product);
void salesAverage(commodity *shopPtr, int index, tm fromDate, int numOfMonth, double &average);
void tdayStrtoInt(string date, tm &fromDate);
void salesPrediction(commodity* shopPtr, int numberOfCommodity);
void stockStatus(commodity *shopPtr, int numberOfCommodity);
void checkInventoryStatus(commodity* shopPrt, int numberOfCommodity);

void stockPrinter(commodity *product){
    cout.width(10); cout<<left<<product->index;
    cout.width(15); cout<<left<<product->productCode;
    cout.width(20); cout<<left<<product->name;
    cout.width(20); cout<<left<<product->stockNum;
}

void salesAverage(commodity *shopPtr, int index, tm fromDate, int numOfMonth, double &average)
{
    tm *desireMonth = 0;
    salesRecord *temp_record = 0;
    int temp_record_num = 0, totalSales = 0;
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
    
    average = (double)totalSales/(double)numOfMonth;
    
    delete [] temp_record;
    delete [] desireMonth;
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
    int month;
    cout<<"Choose the average of sales in the last x months: ";
    cin>>month;
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;
    
    string date;
    cout << "From when (YYYY-MM, e.g. 2019-12) to "<<month<<" months before: ";
    cin >> date;
    tdayStrtoInt(date, fromDate);
    
    cout.width(10); cout<<left<<"Index";
    cout.width(15); cout<<left<<"Product Code";
    cout.width(20); cout<<left<<"Name";
    cout.width(20); cout<<left<<"Current stock";
    cout.width(20); cout<<left<<"Predicted sales in "<<month<<" month";
    cout<<endl;
    double average;
    for (int i=0; i<numberOfCommodity; i++) {
        salesAverage(shopPtr, i, fromDate, month, average);
        stockPrinter(&shopPtr[i]);
        cout.width(20); cout<<left<<average;
        cout<<endl;
    }
    cout<<endl;
}

void stockStatus(commodity *shopPtr, int numberOfCommodity){
    //Out of stock first
    
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;
    
    string date;
    cout << "\nEnter current date in (YYYY-MM, e.g. 2019-12) format: ";
    cin >> date;
    tdayStrtoInt(date, fromDate);
    
    int month;
    cout<<"Choose the number of month(s) for prediction: ";
    cin>>month;
    
    cout<<"\nOut of stock warning: \n";
    cout.width(10); cout<<left<<"Index";
    cout.width(15); cout<<left<<"Product Code";
    cout.width(20); cout<<left<<"Name";
    cout<<endl;
    for (int i=0; i<numberOfCommodity; i++) {
        if (shopPtr[i].stockNum==0) {
            stockPrinter(&shopPtr[i]);
            cout<<endl;
        }
    }

    cout<<"\nPredicted out of stock warning: \n";
    cout.width(10); cout<<left<<"Index";
    cout.width(15); cout<<left<<"Product Code";
    cout.width(20); cout<<left<<"Name";
    cout.width(20); cout<<left<<"Current stock";
    cout.width(25); cout<<left<<"Predicted sales in "<<to_string(month)<<" month";
    cout.width(20); cout<<left<<"Difference";
    cout<<endl;
    
    double average;
    for (int j=0; j<numberOfCommodity; j++) {
        salesAverage(shopPtr, j, fromDate, month, average);
        if ((shopPtr[j]).stockNum<average){
            stockPrinter(&shopPtr[j]);
            cout.width(25); cout<<left<<average;
            cout.width(20); cout<<left<<shopPtr[j].stockNum-average;
            cout<<endl;
        }
    }
}

void checkInventoryStatus(commodity* shopPrt, int numberOfCommodity){
    int choice=0;
    while (choice!=3) {
        cout<<"1. Show stock status\n"
        "2. Show sales prediciton\n"
        "3. Quit\n";
        cout<<"Enter your choice here: ";
        cin>>choice;
        if (choice==1){
            cout<<"\nShowing stock status:\n";
            stockStatus(shopPrt, numberOfCommodity);
            cout<<endl;
        }
        else if (choice==2){
            salesPrediction(shopPrt, numberOfCommodity);
        }
        else{
            break;
        }
    }
}
