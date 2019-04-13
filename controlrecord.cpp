#include <iostream>
#include "readrecord.h"
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
