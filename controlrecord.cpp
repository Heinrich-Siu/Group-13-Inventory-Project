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
void addInventory(commodity* shopPtr, int &numberOfCommodity);
void changeRecord(commodity* shopPtr, int &numberOfCommodity);
void changeProductCode(commodity* shopPtr, int index);
void changeProductName(commodity* shopPtr, int index);
void changePrice(commodity* shopPtr, int index);
void changeSizeOfStock(commodity* shopPtr, int index);
void changeTaxAmount(commodity* shopPtr, int index);
void changeManufacturerName(commodity* shopPtr, int index);
void searchBefore_recordAdding(commodity* shopPtr, int numberOfCommodity, int &targetRecordIndex);
void addRestock(commodity* shopPtr, int index);
void addSales(commodity* shopPtr, int index);
void restockOrSales(commodity* shopPtr, int &numberOfCommodity);
void  grow_record(salesRecord *&recordPtr, int originSize, int grownSize);
void grow_record(restockRecord *&recordPtr, int originSize, int grownSize);

/*
Input: shopPtr-pointer point to the inventory Record
       numberOfCommodity-Number of commodity type in the inventory
*/
void addInventory(commodity* shopPtr, int &numberOfCommodity) //Noy finished
{
    grow_commodityRecord(shopPtr, numberOfCommodity, ++numberOfCommodity); //Increase the size of dynamic array of commodity to hold new commodity
    cout << "Please enter the commodity name:";
    cin >> shopPtr[numberOfCommodity-1].name;

    cout << "Please enter the product code";
    cin >> shopPtr[numberOfCommodity-1].productCode;

    cout << "Please enter the price";
    cin >> shopPtr[numberOfCommodity-1].price;

    cout << "Please enter the number of stock";
    cin >> shopPtr[numberOfCommodity-1].stockNum;

    cout << "Please enter the size of stock";
    cin >> shopPtr[numberOfCommodity-1].stockSize;

    //initiate the saled record
    shopPtr[numberOfCommodity-1].numOfSalesRec = 0;
    shopPtr[numberOfCommodity-1].salesRec = 0;


    //initiate the restock record
    shopPtr[numberOfCommodity-1].numOfRestockRec = 0;
    shopPtr[numberOfCommodity-1].restockRec = 0;

    cout << "Please enter the tax amount";
    cin >> shopPtr[numberOfCommodity-1].taxAmount;

    cout << "Please enter the name of the manufacturer";
    cin >> shopPtr[numberOfCommodity-1].manufacturer;



}

void changeRecord(commodity* shopPtr, int &numberOfCommodity)
{
    int searchProductCode;
    int targetRecordIndex = -1;//initiate with not found
    string knowTheProductCode;
    cout << "Do you know the product code of the commodity that you want to change?(Y/N) ";
    cin >> knowTheProductCode;
    if(knowTheProductCode == "N") //user need to search for the productCode if they dont know
    {
        cout << "~~Please first search the commodity and change the record by productCode~~" << endl;
        search(shopPtr, numberOfCommodity);
    }


    cout << "***************************************************************************************\n"
            "Please enter the productCode of the commodity that you want to change:";
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

        int choice;
        cin >> choice;
        while(choice != 7) //continue in change/update mode unless the input is 10
        {
            switch(choice){
              case 1: //Product Code
                  changeProductCode(shopPtr, targetRecordIndex);
                  break;

              case 2: //Product Name
                  changeProductName(shopPtr, targetRecordIndex);
                  break;

              case 3: //Price
                  changePrice(shopPtr, targetRecordIndex);
                  break;

              case 4: //Size of stock
                  changeSizeOfStock(shopPtr, targetRecordIndex);
                  break;

              case 5: //Tax amount
                  changeTaxAmount(shopPtr, targetRecordIndex);
                  break;

              case 6: //Name of manufacturer
                  break;

            }
            cout << "**************************************************\n"
                    "*~~~What record do you want to change/update?     *\n"
                    "*1. Product Code                                 *\n"
                    "*2. Product Name                                 *\n"
                    "*3. Price                                        *\n"
                    "*4. Size of stock                                *\n"
                    "*5. Tax amount                                   *\n"
                    "*6. Name of manufacturer                         *\n"
                    "*7. Quit                                         *\n"
                    "**************************************************" << endl;
            cin >> choice;
        }
    }
}

void changeProductCode(commodity* shopPtr, int index)
{
    int input;
    cout << "Change from " << shopPtr[index].productCode << " to: ";
    cin >> shopPtr[index].productCode;
    cout << "The product code is now: " << shopPtr[index].productCode << endl;
}

void changeProductName(commodity* shopPtr, int index)
{
    string input;
    cout << "Change from " << shopPtr[index].name << " to: ";
    cin >> shopPtr[index].name;
    cout << "The product name is now: " << shopPtr[index].name << endl;
}

void changePrice(commodity* shopPtr, int index)
{
    double input;
    cout << "Change from " << shopPtr[index].price << " to: ";
    cin >> shopPtr[index].price;
    cout << "The product price is now: " << shopPtr[index].price << endl;
}


void changeSizeOfStock(commodity* shopPtr, int index)
{
    int input;
    cout << "Change from " << shopPtr[index].stockSize << " to: ";
    cin >> shopPtr[index].stockSize;
    cout << "The size of product is now: " << shopPtr[index].stockSize << endl;
}

void changeTaxAmount(commodity* shopPtr, int index)
{
    double input;
    cout << "Change from " << shopPtr[index].taxAmount << " to: ";
    cin >> shopPtr[index].taxAmount;
    cout << "The tax amount of product is now: " << shopPtr[index].taxAmount << endl;
}

void changeManufacturerName(commodity* shopPtr, int index)
{
    string input;
    cout << "Change from " << shopPtr[index].manufacturer << " to: ";
    cin >> shopPtr[index].manufacturer;
    cout << "The manufacturer of product is now: " << shopPtr[index].manufacturer << endl;
}

void searchBefore_recordAdding(commodity* shopPtr, int numberOfCommodity, int &targetRecordIndex)
{
    string knowTheProductCode;
    int searchProductCode;
    cout << "Do you know the product code of the commodity that you want to change?(Y/N) ";
    cin >> knowTheProductCode;
    if(knowTheProductCode == "N") //user need to search for the productCode if they dont know
    {
        cout << "~~Please first search the commodity and change the record by productCode~~" << endl;
        search(shopPtr, numberOfCommodity);
    }


    cout << "***************************************************************************************\n"
            "Please enter the productCode of the commodity that you want to add record to:";
    cin >> searchProductCode;
    cout << "***************************************************************************************" << endl;

    for(int i=0; i < numberOfCommodity; i++) //loop through all productCode to find match
    {
          if(shopPtr[i].productCode == searchProductCode)
          {
              targetRecordIndex = i; // found
          }
    }
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


void addRestock(commodity* shopPtr, int index)
{
    if(shopPtr[index].numOfRestockRec == 0) //No record before
    {
        shopPtr[index].restockRec = new restockRecord[++(shopPtr[index].numOfRestockRec)]; //initialize dynamic array for the first record
    }
    else //there are record before
    {
        grow_record(shopPtr[index].restockRec, shopPtr[index].numOfRestockRec, ++(shopPtr[index].numOfRestockRec)); //enliarge the record array size
    }

    int index_emptyRecord = shopPtr[index].numOfRestockRec-1;
    string date, temp;
    cout << "Delivery time (YYYY-MM-DD): ";
    cin >> date;
    int columns = 0;
    istringstream dateStr(date); //tramsform the string to the restock structure
    while(getline(dateStr, temp, '-'))
    {
        switch (columns) {
            case 0:
                shopPtr[index].restockRec[index_emptyRecord].deliveryTime.tm_year = stoi(temp);
                break;
            case 1:
                shopPtr[index].restockRec[index_emptyRecord].deliveryTime.tm_mon = stoi(temp);
                break;
            case 2:
                shopPtr[index].restockRec[index_emptyRecord].deliveryTime.tm_mday = stoi(temp);
                break;
        }
        columns++;
    }
    cout << "Quantity: ";
    cin >> shopPtr[index].restockRec[index_emptyRecord].quantity;

    shopPtr[index].stockNum += shopPtr[index].restockRec[index_emptyRecord].quantity; //add(+) to total number of stock
}

void addSales(commodity* shopPtr, int index)
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
    string date, temp;
    cout << "Sales time (YYYY-MM-DD): ";
    cin >> date;
    cout << "Quantity: ";
    cin >> shopPtr[index].salesRec[index_emptyRecord].quantity;

    if(shopPtr[index].stockNum - shopPtr[index].salesRec[index_emptyRecord].quantity < 0 ) //cause negative stock number
    {
        cout << "Error! Your action will result in negatve stock number";
        cout << "(From " << shopPtr[index].stockNum << " -> " << shopPtr[index].stockNum - shopPtr[index].salesRec[index_emptyRecord].quantity << " )" << endl;
    }
    else
    {
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

      shopPtr[index].stockNum -= shopPtr[index].salesRec[index_emptyRecord].quantity; //minus(-) to total number of stock
    }

}


void restockOrSales(commodity* shopPtr, int &numberOfCommodity)
{
    int choice;
    cout << "*****************************************\n"
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
      cout << "choice 1.Adding Sales record\n"
              "       2.Adding Restock record\n"
              "       3.Quit\n";
      cout << "Choice: ";
      cin >> choice;
      while(choice != 3)
      {
          switch(choice)
          {
              case 1:
                  cout << "You are adding record of sales of " << shopPtr[targetRecordIndex].name;
                  cout << " (" << shopPtr[targetRecordIndex].productCode << ")" << endl;
                  addSales(shopPtr, targetRecordIndex);
                  break;
              case 2:
                  cout << "You are adding record of restock of " << shopPtr[targetRecordIndex].name;
                  cout << " (" << shopPtr[targetRecordIndex].productCode << ")" << endl;
                  addRestock(shopPtr, targetRecordIndex);
                  break;
          }
          cout << "choice 1.Adding Sales record\n"
                  "       2.Adding Restock record\n"
                  "       3.Quit\n";
          cout << "Choice: ";
          cin >> choice;
      }
    }

}
