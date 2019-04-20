#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <ctime>
//#include "inventorysys.h"
#include "printer.h"
#include "controlrecord.h"
#include "searcher.h"

using namespace std;

//function prototype
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

void dayStrtoInt(string date, int &year, int &month, int &day);

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
//

void optionPrinter(int i){ //print the columns
    switch (i) {
            //"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount\n"
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
            cout.width(23); cout<<left<<"Number of Sales Record";
            break;
        case 8:
            cout.width(26); cout<<left<<"Number of Restock Record";
            break;
        case 9:
            cout.width(15); cout<<left<<"Manufacturer";
            break;
        case 10:
            cout.width(15); cout<<left<<"Tax Amount";
            break;
        default:
            break;
    }
}
void specPrinter(int i, commodity * product){ //print product info according to request
    switch (i) {
            //"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount\n"
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
            cout.width(23); cout<<left<<product->numOfSalesRec;
            break;
        case 8:
            cout.width(26); cout<<left<<product->numOfRestockRec;
            break;
        case 9:
            cout.width(15); cout<<left<<product->manufacturer;
            break;
        case 10:
            cout<<"$"; cout.width(14); cout<<left<<product->taxAmount;
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
    cout<<"Input the number one by one in any sequence and input -1 when done or enter 11 to print All\n"<<"***e.g. 1 2 5 4 -1***"<<endl;
    cout<<"Here are the options: \n";
    cout<<"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL\n";
    int* fields = new int[11]; //dynamic array that store the aspects need to print
    int a=0, all=0;
    for (int k=0; a!=-1; k++) { //load in different aspects from user
        cin>>a;
        if (a==11){
            all=1;
            break;
        }
        fields[k] = a;
    }
    if (all){//print all
        for (int i=0; i<11; i++){
            fields[i]=i;
        }
        fields[11]=-1;
    }

    for (int i=0; (fields[i])!=-1 ; i++) {
        optionPrinter(fields[i]); //print the columns
    }
    cout<<endl;
    for (int i=0; i<numberOfCommodity; i++)
        recordPrinter(shopPtr+i,fields); //print the data one by one
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
  for (int i=1; i<=10; i++)
      optionPrinter(i); //print the columns

  cout<<endl;

  for (int i=1; i<=10; i++)
      specPrinter(i, shopPtr+index); //print the data in structure one by one
  cout<<endl;
}

//Prompt when asking user to change Record
void recordChangePrompt(){
    cout << "**************************************************\n"
    "*~~~What record do you want to change/update?    *\n"
    "*1. Product Code                                 *\n"
    "*2. Product Name                                 *\n"
    "*3. Price                                        *\n"
    "*4. Size of stock                                *\n"
    "*5. Tax amount                                   *\n"
    "*6. Name of manufacturer                         *\n"
    "*7. Quit                                         *\n"
    "**************************************************" << endl;
}

void inventorySpacePrinter(int totalOcuppiedSpace, int inventorySpace)
{
    cout << endl;
    cout << "Inventory Space: " << totalOcuppiedSpace << "/" << inventorySpace << endl << endl; //eg. Inventory Space: 685/5000
}

void searchBefore_checkRecord(commodity* shopPtr, int numberOfCommodity, int &targetRecordIndex)
{
    string knowTheProductCode;
    int searchProductCode;
    cout << "Do you know the product code of the commodity that you want to check?(Y/N) ";
    cin >> knowTheProductCode;
    if(knowTheProductCode == "N") //user need to search for the productCode if they dont know
    {
        cout << "~~Please first search the commodity and check the record by productCode~~" << endl;
        search(shopPtr, numberOfCommodity);
    }


    cout << "\n"
            "Please enter the product code of the commodity record that you want to check: ";
    cin >> searchProductCode;
    cout << endl;

    for(int i=0; i < numberOfCommodity; i++) //loop through all productCode to find match
    {
        if(shopPtr[i].productCode == searchProductCode)
        {
            targetRecordIndex = i; // found
        }
    }
}

void checkRecordUIPrinter()
{
    cout << "Check by: 1. 3 Months\n"
            "          2. 6 Months\n"
            "          3. 1 Year\n"
            "          4. Whole history\n"
            "          5. Quit\n"
            "Choice: ";
}

void dayStrtoInt(string date, tm &fromDate)
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


void salesPrinterPerRecord(salesRecord *salesRec)
{
    string temp_date = std::to_string(salesRec->date.tm_year) + "-" + std::to_string(salesRec->date.tm_mon) + "-" + std::to_string(salesRec->date.tm_mday); //eg. 2019-4-20
    cout.width(18); cout << left << temp_date;
    cout.width(6); cout << left << salesRec->quantity << endl; //print quantity
}


void returnPastNMonth(tm fromDate, tm *&desireMonth, int numOfMonth) //eg.fromdate is 2019-04 then 3 months = 2019-04, 2019-03, 2019-02
{
    desireMonth = new tm[numOfMonth];
    for(int i=0; i<numOfMonth; i++)
    {
        if(i==0) //
        {
            desireMonth[i].tm_year = fromDate.tm_year;
            desireMonth[i].tm_mon = fromDate.tm_mon;
        }
        else
        {
            if(fromDate.tm_mon-1 == 0)
            {
                fromDate.tm_year--;
                fromDate.tm_mon = 12;
                desireMonth[i].tm_year = fromDate.tm_year;
                desireMonth[i].tm_mon = fromDate.tm_mon;
            }
            else
            {
                fromDate.tm_mon--;
                desireMonth[i].tm_year = fromDate.tm_year;
                desireMonth[i].tm_mon = fromDate.tm_mon;
            }
        }
    }
}

void storeBeforePrint_sales(salesRecord *&temp_record, int &temp_record_num, salesRecord *salesRec)
{
    if(temp_record_num==0)
    {
        temp_record_num++;
        temp_record = new salesRecord[temp_record_num];
        temp_record[0].date.tm_year = salesRec->date.tm_year;
        temp_record[0].date.tm_mon = salesRec->date.tm_mon;
        temp_record[0].date.tm_mday = salesRec->date.tm_mday;
        temp_record[0].quantity = salesRec->quantity;
    }
    else
    {
        //enlarge the array
        temp_record_num++;
        salesRecord *enlarged = new salesRecord[temp_record_num];
        for(int i=0; i<temp_record_num-1; i++)
        {
            enlarged[i] = temp_record[i];
        }
        delete [] temp_record;
        temp_record = enlarged;
        enlarged = 0;
        //
        temp_record[temp_record_num-1].date.tm_year = salesRec->date.tm_year;
        temp_record[temp_record_num-1].date.tm_mon = salesRec->date.tm_mon;
        temp_record[temp_record_num-1].date.tm_mday = salesRec->date.tm_mday;
        temp_record[temp_record_num-1].quantity = salesRec->quantity;
    }
}

void nthMonthPrinter_sales(commodity *shopPtr, int index, tm fromDate, int numOfMonth)
{
    string duration;
    if(numOfMonth == 3)
    {
        duration = "3 months";
    }
    else if(numOfMonth == 6)
    {
        duration = "6 months";
    }
    else if(numOfMonth == 12)
    {
        duration = "1 year";
    }
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

    if(temp_record_num == 0)
    {
        cout << "Sorry, There is no sales record found in the last " << duration << endl;
    }
    else
    {
        cout << "Total " << temp_record_num << " record in the last " << duration << " found." << endl << endl;
        cout.width(18); cout << left << "Date (YYYY-MM-DD)";
        cout.width(6); cout << left << "Quantity" << endl;
        for(int i=0; i<temp_record_num; i++)
        {
            salesPrinterPerRecord(temp_record+i);
            totalSales += temp_record[i].quantity;
        }
    }
    cout << endl << "Total sales in the last " << duration << " is " << totalSales << "."<< endl << endl;


    delete [] temp_record;
    delete [] desireMonth;
}

void wholeSalesHistoryPrinter(commodity *shopPtr, int index)
{
    int totalSales = 0;
    cout << "Total " << shopPtr[index].numOfSalesRec << " record found." << endl << endl;
    cout.width(18); cout << "Date (YYYY-MM-DD)";
    cout.width(6); cout << "Quantity" << endl;
    for(int i=0; i<shopPtr[index].numOfSalesRec; i++)
    {
        salesPrinterPerRecord(shopPtr[index].salesRec+i);
        totalSales += shopPtr[index].salesRec[i].quantity;
    }
    cout << endl << "Total sales in the whole history is " << totalSales << "."<< endl << endl;
}

void checkSalesHistory(commodity *shopPtr, int numberOfCommodity)
{
    int choice;
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;
    string date;
    int targetRecordIndex = -1;//initiate with not found
    searchBefore_recordAdding(shopPtr, numberOfCommodity, targetRecordIndex);
    if(targetRecordIndex == -1) //check if product code found?
    {
        cout << "The product code you entered does not exist" << endl;
    }
    else
    {
        checkRecordUIPrinter();
        cin >> choice;
        cout << endl;
        while(choice != 5)
        {
            switch (choice) {
              case 1:
                  cout << "From when (YYYY-MM, e.g. 2019-12) to 3 months before: ";
                  cin >> date;
                  dayStrtoInt(date, fromDate);
                  nthMonthPrinter_sales(shopPtr, targetRecordIndex, fromDate, 3);
                  break;
              case 2:
                  cout << "From when (YYYY-MM, e.g. 2019-12) to 6 months before: ";
                  cin >> date;
                  dayStrtoInt(date, fromDate);
                  nthMonthPrinter_sales(shopPtr, targetRecordIndex, fromDate, 6);
                  break;
              case 3:
                  cout << "From when (YYYY-MM, e.g. 2019-12) to 1 year before: ";
                  cin >> date;
                  dayStrtoInt(date, fromDate);
                  nthMonthPrinter_sales(shopPtr, targetRecordIndex, fromDate, 12);
                  break;
              case 4:
                  wholeSalesHistoryPrinter(shopPtr, targetRecordIndex);
                  break;
            }
            checkRecordUIPrinter();
            cin >> choice;

        }
    }
}


void restockPrinterPerRecord(restockRecord *restockRec)
{
    string temp_date = std::to_string(restockRec->deliveryTime.tm_year) + "-" + std::to_string(restockRec->deliveryTime.tm_mon) + "-" + std::to_string(restockRec->deliveryTime.tm_mday); //eg. 2019-4-20
    cout.width(18); cout << left << temp_date;
    cout.width(6); cout << left << restockRec->quantity << endl; //print quantity
}


void storeBeforePrint_restock(restockRecord *&temp_record, int &temp_record_num, restockRecord *restockRec)
{
    if(temp_record_num==0)
    {
        temp_record_num++;
        temp_record = new restockRecord[temp_record_num];
        temp_record[0].deliveryTime.tm_year = restockRec->deliveryTime.tm_year;
        temp_record[0].deliveryTime.tm_mon = restockRec->deliveryTime.tm_mon;
        temp_record[0].deliveryTime.tm_mday = restockRec->deliveryTime.tm_mday;
        temp_record[0].quantity = restockRec->quantity;
    }
    else
    {
        //enlarge the array
        temp_record_num++;
        restockRecord *enlarged = new restockRecord[temp_record_num];
        for(int i=0; i<temp_record_num-1; i++)
        {
            enlarged[i] = temp_record[i];
        }
        delete [] temp_record;
        temp_record = enlarged;
        enlarged = 0;
        //
        temp_record[temp_record_num-1].deliveryTime.tm_year = restockRec->deliveryTime.tm_year;
        temp_record[temp_record_num-1].deliveryTime.tm_mon = restockRec->deliveryTime.tm_mon;
        temp_record[temp_record_num-1].deliveryTime.tm_mday = restockRec->deliveryTime.tm_mday;
        temp_record[temp_record_num-1].quantity = restockRec->quantity;
    }
}

void nthMonthPrinter_restock(commodity *shopPtr, int index, tm fromDate, int numOfMonth)
{
    string duration;
    if(numOfMonth == 3)
    {
        duration = "3 months";
    }
    else if(numOfMonth == 6)
    {
        duration = "6 months";
    }
    else if(numOfMonth == 12)
    {
        duration = "1 year";
    }
    tm *desireMonth = 0;
    restockRecord *temp_record = 0;
    int temp_record_num = 0, totalSales = 0;
    returnPastNMonth(fromDate, desireMonth, numOfMonth);

    for(int j=0; j<numOfMonth; j++)
    {
        for(int i=shopPtr[index].numOfRestockRec-1; i>=0; i--) //loop from last record to first because of most recent order
        {
            if(desireMonth[j].tm_year == shopPtr[index].restockRec[i].deliveryTime.tm_year && desireMonth[j].tm_mon == shopPtr[index].restockRec[i].deliveryTime.tm_mon)
            {
                storeBeforePrint_restock(temp_record, temp_record_num, shopPtr[index].restockRec+i);
            }
        }
    }

    if(temp_record_num == 0)
    {
        cout << "Sorry, There is no restock record found in the last " << duration << endl;
    }
    else
    {
        cout << "Total " << temp_record_num << " record in the last " << duration << " found." << endl << endl;
        cout.width(18); cout << left << "Date (YYYY-MM-DD)";
        cout.width(6); cout << left << "Quantity" << endl;
        for(int i=0; i<temp_record_num; i++)
        {
            restockPrinterPerRecord(temp_record+i);
            totalSales += temp_record[i].quantity;
        }
    }
    cout << endl << "Total restock in the last " << duration << " is " << totalSales << "."<< endl << endl;


    delete [] temp_record;
    delete [] desireMonth;
}

void wholeRestockHistoryPrinter(commodity *shopPtr, int index)
{
    int totalSales = 0;
    cout << "Total " << shopPtr[index].numOfRestockRec << " record found." << endl << endl;
    cout.width(18); cout << "Date (YYYY-MM-DD)";
    cout.width(6); cout << "Quantity" << endl;
    for(int i=0; i<shopPtr[index].numOfRestockRec; i++)
    {
        restockPrinterPerRecord(shopPtr[index].restockRec+i);
        totalSales += shopPtr[index].restockRec[i].quantity;
    }
    cout << endl << "Total restock in the whole history is " << totalSales << "."<< endl << endl;
}


void checkRestockHistory(commodity *shopPtr, int numberOfCommodity)
{
    int choice;
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;
    string date;
    int targetRecordIndex = -1;//initiate with not found
    searchBefore_recordAdding(shopPtr, numberOfCommodity, targetRecordIndex);
    if(targetRecordIndex == -1) //check if product code found?
    {
        cout << "The product code you entered does not exist" << endl;
    }
    else
    {
        checkRecordUIPrinter();
        cin >> choice;
        cout << endl;
        while(choice != 5)
        {
            switch (choice) {
              case 1:
                  cout << "From when (YYYY-MM, e.g. 2019-12) to 3 months before: ";
                  cin >> date;
                  dayStrtoInt(date, fromDate);
                  nthMonthPrinter_restock(shopPtr, targetRecordIndex, fromDate, 3);
                  break;
              case 2:
                  cout << "From when (YYYY-MM, e.g. 2019-12) to 6 months before: ";
                  cin >> date;
                  dayStrtoInt(date, fromDate);
                  nthMonthPrinter_restock(shopPtr, targetRecordIndex, fromDate, 6);
                  break;
              case 3:
                  cout << "From when (YYYY-MM, e.g. 2019-12) to 1 year before: ";
                  cin >> date;
                  dayStrtoInt(date, fromDate);
                  nthMonthPrinter_restock(shopPtr, targetRecordIndex, fromDate, 12);
                  break;
              case 4:
                  wholeRestockHistoryPrinter(shopPtr, targetRecordIndex);
                  break;
            }
            checkRecordUIPrinter();
            cin >> choice;

        }
    }
}
