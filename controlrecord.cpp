#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "readrecord.h"
#include "searcher.h"
#include "printer.h"
#include "controlrecord.h"

using namespace std;

//Function prototype
void addCommodity(commodity *&shopPtr, int &numberOfCommodity);
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

/*
 Input: shopPtr-pointer point to the inventory Record
 numberOfCommodity-Number of commodity type in the inventory
 */
void addCommodity(commodity *&shopPtr, int &numberOfCommodity)
{

    grow_commodityRecord(shopPtr, numberOfCommodity, numberOfCommodity+1); //Increase the size of dynamic array of commodity to hold new commodity
    numberOfCommodity++;
    shopPtr[numberOfCommodity-1].index = numberOfCommodity-1;
    
    string name;
    getline(cin, name);
    cout << "Please enter the commodity name: ";
    getline(cin, name);
    shopPtr[numberOfCommodity-1].name=name;
    
    cout << "Please enter the product code: ";
    cin >> shopPtr[numberOfCommodity-1].productCode;
    
    cout << "Please enter the price: ";
    cin >> shopPtr[numberOfCommodity-1].price;
    
    //cout << "Please enter the number of stock";
    shopPtr[numberOfCommodity-1].stockNum = 0;
    
    cout << "Please enter the size of stock: ";
    cin >> shopPtr[numberOfCommodity-1].stockSize;
    
    //initiate the saled record
    shopPtr[numberOfCommodity-1].numOfSalesRec = 0;
    shopPtr[numberOfCommodity-1].salesRec = 0;
    
    
    //initiate the restock record
    shopPtr[numberOfCommodity-1].numOfRestockRec = 0;
    shopPtr[numberOfCommodity-1].restockRec = 0;
    
    cout << "Please enter the tax amount: ";
    cin >> shopPtr[numberOfCommodity-1].taxAmount;
    
    cout << "Please enter the name of the manufacturer: ";
    cin >> shopPtr[numberOfCommodity-1].manufacturer;
    
    
    
    cout<<"\nCommodity added! Returning to main screen...\n"<<endl;
    
}



//change the record depending on the choice of user
void actualRecordChanger(int choice, commodity* shopPtr, int index){
    switch(choice){
        case 1: //Product Code
            cout << "Change from " << shopPtr[index].productCode << " to: ";
            cin >> shopPtr[index].productCode;
            cout << "The product code is now: " << shopPtr[index].productCode << endl;
            break;
            
        case 2: //Product Name
            cout << "Change from " << shopPtr[index].name << " to: ";
            cin >> shopPtr[index].name;
            cout << "The product name is now: " << shopPtr[index].name << endl;
            break;
            
        case 3: //Price
            cout << "Change from " << shopPtr[index].price << " to: ";
            cin >> shopPtr[index].price;
            cout << "The product price is now: " << shopPtr[index].price << endl;
            break;
            
        case 4: //Size of stock
            cout << "Change from " << shopPtr[index].stockSize << " to: ";
            cin >> shopPtr[index].stockSize;
            cout << "The size of product is now: " << shopPtr[index].stockSize << endl;
            break;
            
        case 5: //Tax amount
            cout << "Change from " << shopPtr[index].taxAmount << " to: ";
            cin >> shopPtr[index].taxAmount;
            cout << "The tax amount of product is now: " << shopPtr[index].taxAmount << endl;
            break;
            
        case 6: //Name of manufacturer
            cout << "Change from " << shopPtr[index].manufacturer << " to: ";
            cin >> shopPtr[index].manufacturer;
            cout << "The manufacturer of product is now: " << shopPtr[index].manufacturer << endl;
            break;
            
    }
}

//called when user need to change record
void changeRecord(commodity* shopPtr, int &numberOfCommodity)
{
    int searchProductCode;
    int targetRecordIndex = -1;//initiate with not found
    string knowTheProductCode;
    cout << "\nPreparing to modify commodity... \nDo you know the product code of the commodity that you want to update?(Y/N) ";
    cin >> knowTheProductCode;
    if(knowTheProductCode == "N") //user need to search for the productCode if they dont know
    {
        cout << "~~Please first search the commodity and update the commodity by productCode~~" << endl;
        search(shopPtr, numberOfCommodity);
    }
    
    cout << "***************************************************************************************\n"
    "Please enter the productCode of the commodity that you want to update: ";
    cin >> searchProductCode;
    cout << "***************************************************************************************" << endl;
    
    for(int i=0; i < numberOfCommodity; i++) //loop through all productCode to find match
    {
        if(shopPtr[i].productCode == searchProductCode)
        {
            targetRecordIndex = i; // found
        }
    }
    
    if(targetRecordIndex == -1) //check if product code found?
    {
        cout << "The product code you entered does not exist" << endl;
    }
    else //Product Code exist
    {
        recordPrinterByIndex(shopPtr, targetRecordIndex);
        recordChangePrompt();
        
        int choice;
        cin >> choice;
        while(choice != 7) //continue in change/update mode unless the input is 10
        {
            actualRecordChanger(choice, shopPtr, targetRecordIndex);
            cout<<"Commodity updated"<<endl;
            recordChangePrompt();
            cin >> choice;
            
        }
    }
    cout<<"\nExiting commodity update...\n"<<endl;
}



void grow_record(salesRecord *&recordPtr, int originSize, int grownSize)
{
    salesRecord *grownRecordPtr = new salesRecord[grownSize];
    
    for(int i=0; i<originSize; i++){ //transfer data from the old array to the new one
        grownRecordPtr[i] = recordPtr[i];
    }
    delete [] recordPtr; //free original Dynamic array in shopPtr
    
    recordPtr = grownRecordPtr; //point shopPtr pointer to the new grown Dynamic array
}

void grow_record(restockRecord *&recordPtr, int originSize, int grownSize)
{
    restockRecord *grownRecordPtr = new restockRecord[grownSize];
    
    for(int i=0; i<originSize; i++){ //transfer data from the old array to the new one
        grownRecordPtr[i] = recordPtr[i];
    }
    delete [] recordPtr; //free original Dynamic array in shopPtr
    
    recordPtr = grownRecordPtr; //point shopPtr pointer to the new grown Dynamic array
}


void addRestock(commodity* shopPtr, int index, int inventorySpace, int &totalOcuppiedSpace)
{
    string date, temp;
    cout << "Delivery time (YYYY-MM-DD): ";
    cin >> date;
    int columns = 0, tmep_year, tmep_mon, temp_mday, temp_quantity;
    istringstream dateStr(date); //tramsform the string to the restock structure
    while(getline(dateStr, temp, '-'))
    {
        switch (columns) {
            case 0:
                tmep_year = stoi(temp);
                break;
            case 1:
                tmep_mon = stoi(temp);
                break;
            case 2:
                temp_mday = stoi(temp);
                break;
        }
        columns++;
    }
    cout << "Quantity: ";
    cin >> temp_quantity;
    
    if(updateInventorySpace_inAddRecord((temp_quantity*shopPtr[index].stockSize), inventorySpace, totalOcuppiedSpace)) //check if adding quantity will result in exceeding space
    {
        if(shopPtr[index].numOfRestockRec == 0) //No record before
        {
            shopPtr[index].restockRec = new restockRecord[++(shopPtr[index].numOfRestockRec)]; //initialize dynamic array for the first record
        }
        else //there are record before
        {
            grow_record(shopPtr[index].restockRec, shopPtr[index].numOfRestockRec, ++(shopPtr[index].numOfRestockRec)); //enlarge the record array size
        }
        
        int index_emptyRecord = shopPtr[index].numOfRestockRec-1;
        
        shopPtr[index].restockRec[index_emptyRecord].deliveryTime.tm_year = tmep_year;
        shopPtr[index].restockRec[index_emptyRecord].deliveryTime.tm_mon = tmep_mon;
        shopPtr[index].restockRec[index_emptyRecord].deliveryTime.tm_mday = temp_mday;
        shopPtr[index].restockRec[index_emptyRecord].quantity = temp_quantity;
        
        shopPtr[index].stockNum += shopPtr[index].restockRec[index_emptyRecord].quantity; //add(+) to total number of stock
        cout<<"Record added!\n"<<endl;
    }
}

void addSales(commodity* shopPtr, int index, int inventorySpace, int &totalOcuppiedSpace)
{
    string date, temp;
    int temp_quantity;
    cout << "Sales time (YYYY-MM-DD): ";
    cin >> date;
    cout << "Quantity: ";
    cin >> temp_quantity;
    
    if(shopPtr[index].stockNum - temp_quantity < 0 ) //cause negative stock number
    {
        cout << "Error! Your action will result in negatve stock number";
        cout << "(From " << shopPtr[index].stockNum << " -> " << shopPtr[index].stockNum - temp_quantity << " )" << endl;
    }
    else
    {
        if(shopPtr[index].numOfSalesRec == 0) //No record before
        {
            shopPtr[index].salesRec = new salesRecord[++(shopPtr[index].numOfSalesRec)]; //initialize dynamic array for the first record
        }
        else //there are record before
        {
            grow_record(shopPtr[index].salesRec, shopPtr[index].numOfSalesRec, ++(shopPtr[index].numOfSalesRec)); //enliarge the record array size
        }
        int index_emptyRecord = shopPtr[index].numOfSalesRec;
        int columns = 0;
        istringstream dateStr (date); //tramsform the string to the restock structure
        while(getline(dateStr, temp, '-'))
        {
            switch (columns) {
                case 0:
                    shopPtr[index].salesRec[index_emptyRecord].date.tm_year = stoi(temp);
                    break;
                case 1:
                    shopPtr[index].salesRec[index_emptyRecord].date.tm_mon = stoi(temp);
                    break;
                case 2:
                    shopPtr[index].salesRec[index_emptyRecord].date.tm_mday = stoi(temp);
                    break;
            }
            columns++;
        }
        shopPtr[index].salesRec[index_emptyRecord].quantity = temp_quantity;
        
        shopPtr[index].stockNum -= shopPtr[index].salesRec[index_emptyRecord].quantity; //minus(-) to total number of stock
        totalOcuppiedSpace -= shopPtr[index].stockSize * shopPtr[index].salesRec[index_emptyRecord].quantity; //minus the size of sales quantity to the total Ocuppied Space
        cout<<"Record added!\n"<<endl;
    }
    
}

void searchBefore_recordAdding(commodity* shopPtr, int numberOfCommodity, int &targetRecordIndex)
{
    string knowTheProductCode;
    int searchProductCode;
    cout << "Do you know the product code of the commodity that you want to update?(Y/N) ";
    cin >> knowTheProductCode;
    if(knowTheProductCode == "N") //user need to search for the productCode if they dont know
    {
        cout << "~~Please first search the commodity and change the record by product code~~" << endl;
        search(shopPtr, numberOfCommodity);
    }
    
    
    cout << "\n"
    "Please enter the product code of the commodity that you want to add record to: ";
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

void  restockOrSales(commodity* shopPtr, int &numberOfCommodity, int inventorySpace, int &totalOcuppiedSpace)
{
    int choice=0;;
    cout << "\n*****************************************\n"
    "You are updating sales and restock record\n"
    "*****************************************\n";
    int targetRecordIndex = -1;//initiate with not found
    searchBefore_recordAdding(shopPtr, numberOfCommodity, targetRecordIndex);
    if(targetRecordIndex == -1) //check if product code found?
    {
        cout << "The product code you entered does not exist" << endl;
    }
    else
    {
        while(choice != 3)
        {
            cout << "Choice 1.Adding Sales record\n"
            "       2.Adding Restock record\n"
            "       3.Quit\n";
            cout << "Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                    cout << "You are adding record of sales of " << shopPtr[targetRecordIndex].name;
                    cout << " (" << shopPtr[targetRecordIndex].productCode << ")" << endl;
                    addSales(shopPtr, targetRecordIndex, inventorySpace, totalOcuppiedSpace);
                    
                    break;
                case 2:
                    cout << "You are adding record of restock of " << shopPtr[targetRecordIndex].name;
                    cout << " (" << shopPtr[targetRecordIndex].productCode << ")" << endl;
                    addRestock(shopPtr, targetRecordIndex, inventorySpace, totalOcuppiedSpace);
                    break;
                default:
                    break;
            }
        }
        cout<<"\nExiting record change\n"<<endl;
    }
}

bool updateInventorySpace_inAddRecord(int addSize,int inventorySpace, int &totalOcuppiedSpace)
{
    if(addSize+totalOcuppiedSpace<=inventorySpace)
    {
        totalOcuppiedSpace += addSize;
        return 1;
    }
    else
    {
        cout << "Action will result in exceeding available inventory space " << addSize+totalOcuppiedSpace << "/" << inventorySpace << endl;
        return 0;
    }
}
