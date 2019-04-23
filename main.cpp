#include <iostream>
#include "inventorysys.h"
#include "readrecord.h"
#include "searcher.h"
#include "printer.h"
#include "controlrecord.h"
#include "sort.h"
#include "Save_Record_to_file.h"
#include "inventoryStatus.h"

using namespace std;

void printMainUI()
{
    string ui = "*********XXX Company Commodity Inventory system*********\n"
    "1.  Show all inventory record\n"
    "2.  Search an Commodity\n"
    "3.  Add new commodity\n"
    "4.  Check Inventory Space\n"
    "5.  Update commodity\n"
    "6.  Stock sales/restock\n"
    "7.  Check Sales History\n"
    "8.  Check Restock History\n"
    "9.  Save Record to File\n"
    "10. Check inventory status\n"
    "11. Exit";
    cout << ui << endl;
    cout << "Please input a command: ";
}

int main()
{
    const int inventorySpace = 50000; //Maximum storage size is 50000
    int totalOcuppiedSpace = 0;
    commodity *shopPtr = 0; //initialize a commodity to use
    int numberOfCommodity = 0;
    string fileName;
    loadAllRecord(shopPtr, numberOfCommodity, fileName);
    checkInventorySpace(shopPtr, numberOfCommodity, totalOcuppiedSpace);
    printMainUI();
    int userInput;
    cin >> userInput;

    while(userInput != 12){ //while userInput no equal to the quit choice
        if(userInput >= 0 && userInput <=11){
            switch(userInput){
                case 1: //Show all inventory record
                    cout<<"\n*********Showing all inventory record*********\n"<<endl;
                    inventoryShower(shopPtr, numberOfCommodity);
                    cout<<"\n*********All results shown*********\nReturning to main page...\n"<<endl;
                    break;

                case 2: //Search an Commodity
                    search(shopPtr, numberOfCommodity);
                    cout<<"Returning to main page...\n"<<endl;
                    break;

                case 3: //Add new commodity
                    cout<<"\nPreparing to add a new commodity...\n"<<endl;
                    addCommodity(shopPtr, numberOfCommodity);
                    break;

                case 4: //Check inventory Space
                    cout<<endl;
                    inventorySpacePrinter(totalOcuppiedSpace, inventorySpace);
                    break;

                case 5: //Change commodity inventory record
                    changeRecord(shopPtr, numberOfCommodity);
                    break;

                case 6:
                    restockOrSales(shopPtr, numberOfCommodity, inventorySpace, totalOcuppiedSpace);
                    cout<<"Returning to main page...\n"<<endl;
                    break;

                case 7: //Sorting record by different parameter
                    sortingInventory(shopPtr, numberOfCommodity);
                    cout<<"Returning to main page...\n"<<endl;
                    break;

                case 8:
                    cout<<"\nPreparing to show sales record...\n"<<endl;
                    historyCheck(shopPtr, numberOfCommodity, true);
                    cout<<"Returning to main page...\n"<<endl;
                    break;

                case 9:
                    cout<<"\nPreparing to show restock record...\n"<<endl;
                    historyCheck(shopPtr, numberOfCommodity, false);
                    cout<<"Returning to main page...\n"<<endl;
                    break;

                case 10:
                    saveRecordToFile(shopPtr, numberOfCommodity, fileName);
                    cout<<"Returning to main page...\n"<<endl;
                    break;
                case 11:
                    cout<<"\nShowing sales prediction:"<<endl;
                    checkInventoryStatus(shopPtr, numberOfCommodity);
                    cout<<"Returning to main page...\n"<<endl;
                    break;
                default:
                    break;
            }
        }
        else cout << "Your input is invalid" << endl;

        if (userInput==12) break;
        printMainUI();
        cin >> userInput;
    }
    cout << "Program end Sucessfully. Thanks for using our programme :) " << endl; //inform the user the program end successfully
}
