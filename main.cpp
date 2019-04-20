#include <iostream>
#include "inventorysys.h"
#include "readrecord.h"
#include "searcher.h"
#include "printer.h"
#include "controlrecord.h"
#include "Save_Record_to_file.h"

using namespace std;


void printMainUI()
{
    string ui = "*********XXX Company Commodity Inventory system*********\n"
    "1. Show all inventory record\n"
    "2. Search an Commodity\n"
    "3. Add new commodity\n"
    "4. Check Inventory Space\n"
    "5. Update commodity\n"
    "6. Stock sales/restock\n"
    "7. Check Sales History\n"
    "8. Check Restock History\n"
    "9. Save Record to File\n"
    "10. Exit";
    cout << ui << endl;
    cout << "Please input a command: ";
}

int main()
{
    const int inventorySpace = 5000; //Maximum storage size is 5000
    int totalOcuppiedSpace = 0;
    commodity *shopPtr = 0; //initialize a commodity to use
    int numberOfCommodity = 0;
    string fileName;
    loadAllRecord(shopPtr, numberOfCommodity, fileName);
    checkInventorySpace(shopPtr, numberOfCommodity, totalOcuppiedSpace);
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
                    addCommodity(shopPtr, numberOfCommodity);
                    break;
                    
                case 4: //Check inventory Space
                    inventorySpacePrinter(totalOcuppiedSpace, inventorySpace);
                    break;
                    
                case 5: //Change commodity inventory record
                    changeRecord(shopPtr, numberOfCommodity);
                    break;
                    
                case 6:
                    restockOrSales(shopPtr, numberOfCommodity, inventorySpace, totalOcuppiedSpace);
                    break;
                    
                case 7:
                    checkSalesHistory(shopPtr, numberOfCommodity);
                    break;
                    
                case 8:
                    checkRestockHistory(shopPtr, numberOfCommodity);
                    break;
                    
                case 9:
                    saveRecordToFile(shopPtr, numberOfCommodity, fileName);
                    break;
                default:
                    break;
            }
        }
        else cout << "Your input is invalid" << endl;
        
        if (userInput==10) break;
        printMainUI();
        cin >> userInput;
    }
    cout << "Program end Sucessfully" << endl; //inform the user the program end successfully
}
