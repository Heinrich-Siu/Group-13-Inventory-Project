#include <iostream>
#include "inventorysys.h"
#include "readrecord.h"
#include "searcher.h"
#include "printer.h"
#include "controlrecord.h"

using namespace std;

void printMainUI()
{
    string ui = "*********XXX Company Commodity Inventory system*********\n"
    "1. Show all inventory record\n"
    "2. Search an Commodity\n"
    "3. Add new commodity\n"
    "4. Check Inventory Space\n"
    "5. Change commodity inventory record\n"
    "6. Stock sales/restock\n"
    "7. \n"
    "8. Save Record to File\n"
    "9. Exit";
    cout << ui << endl;
    cout << "Please input a command: ";
}

int main()
{
    commodity *shopPtr = 0; //initialize a commodity to use
    int numberOfCommodity = 0;
    loadAllRecord(shopPtr, numberOfCommodity);
    printMainUI();
    int userInput;
    cin >> userInput;

    while(userInput != 10){ //while userInput no equal to the quit choice
        if(userInput >= 0 && userInput <=9){
            switch(userInput){
                case 1: //Show all inventory record
                    inventoryShower(shopPtr, numberOfCommodity);
                    break;

                case 2: //Search an Commodity
                    search(shopPtr, numberOfCommodity);
                    break;

                case 3: //Add new commodity
                    //addInventory(shopPtr, numberOfCommodity); //Not finished
                    break;

                case 4:
                    break;

                case 5: //Change commodity inventory record
                    changeRecord(shopPtr, numberOfCommodity);
                    break;

                case 6:
                    restockOrSales(shopPtr, numberOfCommodity);
                    break;

                case 7:
                    break;

                case 8:
                    break;

                case 9:
                    break;
            }
            /*string ui = "*********XXX Company Commodity Inventory system*********\n"
            "1. Show all inventory record\n"
            "2. Change/Update commodity inventory record\n"
            "3. Add new commodity\n"
            "4. Check Inventory Space\n"
            "5. \n"
            "6. \n"
            "7. \n"
            "8. \n"
            "9. Exit";
            cout << ui << endl;
            */
        }
        else cout << "Your input is invalid" << endl;

        if (userInput==9) break;
        printMainUI();
        cin >> userInput;
    }
    cout << "Program end Sucessfully" << endl; //inform the user the program end successfully
}
