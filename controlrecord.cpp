#include <iostream>
//#include "readrecord.h"
#inlcude "controlrecord.h"

using namespace std;
/*
Input: shopPtr-pointer point to the inventory Record
       numberOfCommodity-Number of commodity type in the inventory
*/
void addInventory(commodity* shopPtr, int &numberOfCommodity) //Noy finished
{
    grow_commodityRecord(shopPtr, numberOfCommodity, ++numberOfCommodity) //Increase the size of dynamic array of commodity to hold new commodity
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
    int targetProductCode;
    int targetRecordIndex;
    string knowTheProductCode;
    cout << "Do you know the product code of the commodity that you want to change/update?(Y/N) "
    cin >> knowTheProductCode;
    if(knowTheProductCode == "N") //user need to search for the productCode if they dont know
    {
        cout << "~~Please first search the commodity and change/update the record by productCode~~" << endl;
        search(commodity* shopPtr, int &numberOfCommodity);
    }


    cout << "***************************************************************************************\n"
            "Please enter the productCode of the commodity that you want to change/update:";
    cin >> targetProductCode = -1; //initiate with not found
    cout >> "***************************************************************************************" << endl;
    for(int i=0, i<numberOfCommodity; i++) //loop through all productCode to find match
    {
          if(shopPtr[i].productCode == targetProductCode)
          {
              targetRecordIndex = i; // found
          }
    }

    if(targetRecordIndex == -1) //check if product code found?
    {
        cout << "The product code you entered do not exist" << endl;
    }
    else //Product Code exist
    {
        recordPrinterByIndex(commodity * shopPtr, int targetRecordIndex);
        cout << "**************************************************\n"
                "*~~What record do you want to change/update?     *\n"
                "*1. Product Code                                 *\n"
                "*2. Product Name                                 *\n"
                "*3. Price                                        *\n"
                "*4. Number of Stocks                             *\n"
                "*5. Size of stock                                *\n"
                "*6. Sales record                                 *\n"
                "*7. Restock record                               *\n"
                "*8. Tax amount                                   *\n"
                "*9. Name of manufacturer                         *\n"
                "**************************************************"


        int choice;
        cin <<
        while
    }


}
