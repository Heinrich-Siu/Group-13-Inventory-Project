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

//start of print inventory function
void optionPrinter(int i);

void specPrinter(int i, commodity * product);

void recordPrinter(commodity * product, int * fields);

void inventoryShower(commodity * shopPtr, int numberOfCommodity);

//End of function print inventory


//start of record cahnging prompts
void recordChangePrompt();

void recordPrinterByIndex(commodity * shopPtr, int index);

//end of record changing prompts


//start of inventory space printer

void inventorySpacePrinter(int totalOcuppiedSpace, int inventorySpace);

//end of inventory space printer


//start of history check
void checkRecordUIPrinter();

void dayStrtoInt(string date, int &year, int &month, int &day);

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


//start of function 1

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
            cout.width(25); cout<<left<<"Manufacturer";
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
            cout.width(25); cout<<left<<product->manufacturer;
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

    cout<<"Input the number one by one in any sequence and input -1 when done or enter 11 to print All\n"<<"*** E.g. Enter your choice here: 1 2 5 4 -1 ***"<<endl;
    cout<<"Here are the options: \n";
    cout<<
    "1. Index            2.Product Code           3.Name\n"
    "4.Price             5.Stock Number           6.Stock Size\n"
    "7.Number Of Sales Record                     8.Number Of Restock Record\n"
    "9.Manufacturer      10.Tax Amount            11.ALL\n"
    "Enter your choice here: ";

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

    cout<<"\n*********Enquiry result*********" << endl << endl;

    for (int i=0; (fields[i])!=-1 ; i++) {
        optionPrinter(fields[i]); //print the columns
    }
    cout<<endl;
    for (int i=0; i<numberOfCommodity; i++)
        recordPrinter(shopPtr+i,fields); //print the data one by one
    delete [] fields;

}

//end of funtion 1 printer
/*
 ****************************************************************
*/
//start of update commodity

//Prompt when asking user to change Record
void recordChangePrompt(){
    cout << "\nWhat attribute of the commodity do you want to change/update?\n"
            "1. Product Code\n"
            "2. Product Name\n"
            "3. Price\n"
            "4. Size of stock\n"
            "5. Tax amount\n"
            "6. Name of manufacturer\n"
            "7. Quit\n"
            "Enter your choice here: ";
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

//end of funtion change record
/*
 ****************************************************************
 */
//start of record checking

//space calculating
void inventorySpacePrinter(int totalOcuppiedSpace, int inventorySpace)
{
    cout << "Calculating..."<<endl;
    cout << "Inventory Space: " << totalOcuppiedSpace << "/" << inventorySpace << endl << endl; //eg. Inventory Space: 685/5000
    //add occupy check?
}
//end of space calulation


/*
 ****************************************************************
 */

//start of check sales/restock

void checkRecordUIPrinter()
{
    cout << "Check by:\n"
    "          1. n Months\n"
    "          2. Whole history\n"
    "          3. Quit\n"
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

    cout<<"Please enter the product code of the commodity record that you want to check: ";
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

//
// per record printer
//
void salesPrinterPerRecord(salesRecord *salesRec)
{
    string temp_date = std::to_string(salesRec->date.tm_year) + "-" + std::to_string(salesRec->date.tm_mon) + "-" + std::to_string(salesRec->date.tm_mday); //eg. 2019-4-20
    cout.width(20); cout << left << temp_date;
    cout.width(6); cout << left << salesRec->quantity << endl; //print quantity
}

void restockPrinterPerRecord(restockRecord *restockRec)
{
    string temp_date = std::to_string(restockRec->deliveryTime.tm_year) + "-" + std::to_string(restockRec->deliveryTime.tm_mon) + "-" + std::to_string(restockRec->deliveryTime.tm_mday); //eg. 2019-4-20
    cout.width(20); cout << left << temp_date;
    cout.width(6); cout << left << restockRec->quantity << endl; //print quantity
}
//
//
//

//
//store record to dynamic array
//

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
///
///
///

///
///end of n month printer
///

//
//all record printer
//
void wholeSalesHistoryPrinter(commodity *shopPtr, int index)
{
    int totalSales = 0;
    cout << "Total " << shopPtr[index].numOfSalesRec << " record found." << endl << endl;
    cout.width(20); cout << left <<  "Date (YYYY-MM-DD)";
    cout.width(6); cout << "Quantity" << endl;
    for(int i=0; i<shopPtr[index].numOfSalesRec; i++)
    {
        salesPrinterPerRecord(shopPtr[index].salesRec+i);
        totalSales += shopPtr[index].salesRec[i].quantity;
    }
    cout << endl << "Total sales in the whole history is " << totalSales << "."<< endl << endl;
}
void wholeRestockHistoryPrinter(commodity *shopPtr, int index)
{
    int totalSales = 0;
    cout << "Total " << shopPtr[index].numOfRestockRec << " record found." << endl << endl;
    cout.width(20); cout << "Date (YYYY-MM-DD)";
    cout.width(6); cout << "Quantity" << endl;
    for(int i=0; i<shopPtr[index].numOfRestockRec; i++)
    {
        restockPrinterPerRecord(shopPtr[index].restockRec+i);
        totalSales += shopPtr[index].restockRec[i].quantity;
    }
    cout << endl << "Total restock in the whole history is " << totalSales << "."<< endl << endl;
}
//
//
//

/*void checkRecordUIPrinter()
{
    cout << "Check by:"
    "          1. n Months\n"
    "          2. Whole history\n"
    "          3. Quit\n"
    "Choice: ";
}
*/

void nMonthPrinter(commodity *shopPtr, int index, tm fromDate, int numOfMonth, bool isSlaes){
    string duration = to_string(numOfMonth)+" months";
    tm *desireMonth = 0;
    int temp_record_num = 0, totalSales = 0;
    returnPastNMonth(fromDate, desireMonth, numOfMonth);

    string stockOrRestock = "sales";
    if (!isSlaes) stockOrRestock = "restock";

    salesRecord *temp_recordS = 0;
    restockRecord *temp_recordR = 0;
    if (isSlaes) {
        for(int j=0; j<numOfMonth; j++)
        {
            for(int i=shopPtr[index].numOfSalesRec-1; i>=0; i--) //loop from last record to first because of most recent order
            {
                if(desireMonth[j].tm_year == shopPtr[index].salesRec[i].date.tm_year && desireMonth[j].tm_mon == shopPtr[index].salesRec[i].date.tm_mon)
                {
                    storeBeforePrint_sales(temp_recordS, temp_record_num, shopPtr[index].salesRec+i);
                }
            }
        }
    }
    else{
        for(int j=0; j<numOfMonth; j++)
        {
            for(int i=shopPtr[index].numOfRestockRec-1; i>=0; i--) //loop from last record to first because of most recent order
            {
                if(desireMonth[j].tm_year == shopPtr[index].restockRec[i].deliveryTime.tm_year && desireMonth[j].tm_mon == shopPtr[index].restockRec[i].deliveryTime.tm_mon)
                {
                    storeBeforePrint_restock(temp_recordR, temp_record_num, shopPtr[index].restockRec+i);
                }
            }
        }
    }
    if(temp_record_num == 0)
    {
        cout << "Sorry, There is no "<<stockOrRestock<<" record found in the last " << duration << endl;
    }
    else
    {
        cout << "Total " << temp_record_num << " record in the last " << duration << " found." << endl << endl;
        cout.width(20); cout << left << "Date (YYYY-MM-DD)";
        cout.width(6); cout << left << "Quantity" << endl;
        if (isSlaes) {
            for(int i=0; i<temp_record_num; i++)
            {
                salesPrinterPerRecord(temp_recordS+i);
                totalSales += temp_recordS[i].quantity;
            }
        }
        else{
            for(int i=0; i<temp_record_num; i++)
            {
                restockPrinterPerRecord(temp_recordR+i);
                totalSales += temp_recordR[i].quantity;
            }
        }

        cout << endl << "Total restock in the last " << duration << " is " << totalSales << "."<< endl << endl;
    }
    delete [] temp_recordS;
    delete [] temp_recordR;
    delete [] desireMonth;
}


void historyCheck(commodity *shopPtr, int numberOfCommodity, bool isSales){
    int choice;
    tm fromDate;
    fromDate.tm_year = 0;
    fromDate.tm_mon = 0;
    string date;
    int targetRecordIndex = -1;//initiate with not found
    searchBefore_checkRecord(shopPtr, numberOfCommodity, targetRecordIndex);
    if(targetRecordIndex == -1) //check if product code found?
    {
        cout << "The product code you entered does not exist" << endl;
    }
    else{
        checkRecordUIPrinter();
        cin >> choice;
        while (choice!=3) {
            if (choice==1){
                int nMonth;
                cout << "\nEnter the value of n: ";
                cin>>nMonth;
                cout << "From when (YYYY-MM, e.g. 2019-12) to "<<nMonth<<" months before: ";
                cin >> date;
                dayStrtoInt(date, fromDate);
                nMonthPrinter(shopPtr, targetRecordIndex, fromDate, nMonth, isSales);
            }
            else if (choice==2) {
                if (isSales) wholeSalesHistoryPrinter(shopPtr, targetRecordIndex);
                else wholeRestockHistoryPrinter(shopPtr, targetRecordIndex);
            }
            checkRecordUIPrinter();
            cin>>choice;
        }
    }
}
