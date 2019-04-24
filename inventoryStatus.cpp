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

void stockPrinter(commodity *product, double predictedSales);
void salesAverage(commodity *shopPtr, int index, tm fromDate, int numOfMonth);
void tdayStrtoInt(string date, tm &fromDate);
void checkInventoryStatus(commodity* shopPrt, int numberOfCommodity);

void stockPrinter(commodity *product, double predictedSales){
    cout.width(10); cout<<left<<product->index;
    cout.width(15); cout<<left<<product->productCode;
    cout.width(20); cout<<left<<product->name;
    cout.width(20); cout<<left<<product->stockNum;
    cout.width(20); cout<<left<<predictedSales;
}

void salesAverage(commodity *shopPtr, int index, tm fromDate, int numOfMonth)
{
    string duration;
    duration = to_string(numOfMonth)+"month";
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
    
    double average = (double)totalSales/(double)numOfMonth;
    stockPrinter(shopPtr+index, average);
    cout<<endl;
    
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

void checkInventoryStatus(commodity* shopPrt, int numberOfCommodity){
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
    cout.width(20); cout<<left<<"Predicted sales";
    cout<<endl;
    for (int i=0; i<numberOfCommodity; i++) {
        salesAverage(shopPrt, i, fromDate, month);
    }
    cout<<endl;
}
