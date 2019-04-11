//
//  Searcher.h
//  1340 project testing ground
//
//  Created by Heinrich Siu on 10/4/2019.
//  Copyright © 2019 Heinrich Siu. All rights reserved.
//

#ifndef Searcher_h
#define Searcher_h
#include <string>
#include <limits>
using namespace std;

void ranger(int &max, int &min, int absoulteMax){
    //ask if larger, smaller, or between
    //then output the max and min as a result of the enquiry
    cout<<"You are searching by 1.Larger or equal than  2. Smaller or equal than   3.Between two numbers\n";
    int mode =0; cin>>mode;
    if (mode==1){
        cout<<"The number is larger or equal than: ";
        cin>>min;
        if (min<0) min=0;
        max=absoulteMax;
    }
    else if (mode==2){
        cout<<"The number is smaller or equal than: ";
        cin>>max;
        if (max>absoulteMax) max=absoulteMax;
        min=0;
    }
    else{
        cout<<"The number is larger or equal than: ";
        cin>>min;
        cout<<"The number is smaller or equal than: ";
        cin>>max;
        if (min<0) min=0;
        if (max>absoulteMax) max=absoulteMax;
    }
    cout<<endl;
}


double typeInNumberToValue(commodity* commod, int type){
    switch(type) //columnNum determine the information type
    {//1,2,4,5,6,7,8
            //"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount\n"
        case 1:
            return commod->index;
            break;
        case 2:
            return commod->productCode;
            break;
        case 4:
            return commod->price;
            break;
        case 5:
            return commod->stockNum;
            break;
        case 6:
            return commod->stockSize;
            break;
        case 7:
            return commod->numOfSalesRec;
            break;
        case 8:
            return commod->numOfRestockRec;
            break;
        case 10:
            return commod->taxAmount;
            break;
        default:
            return -1;
            break;
    }

}
string commdityStringValueReturn(commodity*commod, int type){
    if (type==3) return commod->name;
    else if (type==9) return commod->manufacturer;
    else return "false";
}



void searchingInDifferentWays(int type, int* &position, int numberOfCommodity, commodity * shopPtr){ //search and destroy, "destroy" all items not meeting criteria
    
    string optionArray[]={"Nothing Here","Index", "Product Code", "Name", "Price","Stock Number","Stock Size", "Number Of Sales Record", "Number Of Restock Record","Manufacturer","Tax Amount"};
    string pointArray[]={"Nothing Here", "index","productCode","name","price","stockNum","stockSize","numOfSalesRec","numOfRestockRec","manufacturer","taxAmount"};
    
    //"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount\n"
    //1,2,4,5,6,7,8, 10 use same code by number search
    //3,9,10 use same code by string search
    
    //Start generic search by number
    if (type==1 or type==2 or type==4 or type==5 or type==6 or type==7 or type==8 or type==10) {
        cout<<"Search by 1. Specific "<<optionArray[type]<<"  2. Range of "<<optionArray[type]<<endl;
        int option = -1;
        cin>>option;
        if (option==1){
            //specific attribute
            cout<<"Your target "<<optionArray[type]<<" is : ";
            double number;
            cin>>number;
            for (int i=0; i<numberOfCommodity; i++) {
                //loop and find, if not equal, position[i] == -1
                if (typeInNumberToValue(shopPtr+i, type) != number) position[i]=-1;
            }
        }
        else { //range
            int max, min;
            ranger(max, min, (numeric_limits<int>::max)());
            //Larger or equal to: from 0 to min = -1;
            //Smaller or equal to: from max to numberOfCommodity = -1;
            //Between two numbers: from 0 to min = -1 AND from max to numberOfCommodity = -1;
            for (int j=0; j<numberOfCommodity; j++) {
                double current = typeInNumberToValue(shopPtr+j, type);
                if (current>max or current<min) position[j]=-1; //if value is not in range, position = -1 to indicate negative
            }
        }
    } //end of number search
    else if (type==3 or type==9){
        cout<<"Enter the "<<optionArray[type]<<"you wan to search. Can be a sub string of the "<<optionArray[type]<<endl;
        string targetText;
        cin>>targetText;
        for (int k=0; k<numberOfCommodity; k++) {
            //first return string one by one
            //then check if userinput is a substring of that value
            if (commdityStringValueReturn(shopPtr+k, type).find(targetText)==string::npos) position[k]= -1;
        }
    }
}
    
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
    cout<<"Choose what to show in sequence and enter -1 when done\n"<<"Here are the options: \n";
    cout<<"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL\n";
    int* fields = new int[11]; //dynamic array that store the aspects need to print
    int a=0, all=-1;
    for (int k=0; a!=-1; k++) { //load in different aspects from user
        cin>>a;
        if (a==11)all=1; break;
        fields[k] = a;
    }
    if (all){//print all
        for (int i=0; i<11; i++) fields[i]=i;
        fields[11]=-1;
    }
    for (int i=0; (fields[i])!=-1; i++) optionPrinter(fields[i]); //print the columns
    cout<<endl;
    for (int i=0; i<numberOfCommodity; i++) recordPrinter(shopPtr+i,fields); //print the data one by one
    delete [] fields;
}


void search(commodity* shopPtr, int numberOfCommodity){ //"2. Search an Commodity\n"
    //position is used to check if is excluded
    int* position = new int [numberOfCommodity];
    for (int i=0; i<numberOfCommodity; i++) position[i]=i; //position store value equal to its index
        int constrainType=0;
        while (true) {

            cout<<"Find by choosing constrain. Enter -1 when finish"<<endl;
            cout<<"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number \n6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount\n";
            cin>>constrainType;
            if (constrainType==-1) break;
            
            //returns position as a dynamic array
            searchingInDifferentWays(constrainType,position,numberOfCommodity, shopPtr);
            
            //print all items that is not == -1 using inventory shower
            
            //make array to store all non excluded items
            int itemsNonExcluded = 0;
            commodity * tempPtr = new commodity [numberOfCommodity];
            for (int i=0; i<numberOfCommodity; i++){
                if (position[i]!=-1) {
                    tempPtr[itemsNonExcluded]=shopPtr[i];
                    itemsNonExcluded+=1;
                }
            }
            inventoryShower(tempPtr, itemsNonExcluded);
            delete [] tempPtr;
            cout<<endl;
        }
    delete [] position;
}

#endif /* Searcher_h */
