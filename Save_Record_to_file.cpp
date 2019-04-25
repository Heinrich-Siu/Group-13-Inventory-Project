#include "Save_Record_to_file.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//#include "inventorysys.h"
#include "readrecord.h"

using namespace std;

//function prototype
void saveRecordToFile(commodity *shopPtr, int numberOfCommodity, string oldFileName);
void fileToMake(string &name, bool change);



void fileToMake(string &name, bool change){
    cout<<"Do you want to overwrite record to current file instead of creating a new file?   "<<"Enter Y/N: ";
    string answer;
    cin>>answer;
    if (answer=="Y") change = false;
    else {
        cout<<"\nEnter the file name you want to create: ";
        cin>>name;
        change = true;
    }
    
}


void saveRecordToFile(commodity *shopPtr, int numberOfCommodity, string fileName){
    //save to same file or different file
    bool needChange=false;
    fileToMake(fileName, needChange);
    ofstream fout;
    fout.open(fileName);
    if(!fout.fail()){
        //start to write
        //file sturcuture is :
        //333,AppleA,10,40,5,  2;2019-4-6-3;2019-4-7-2 ,  3;2019-3-14-5;2019-3-16-7;2019-3-27-10, 2.5,Fuji
        //product code, productname, price, stockNum, stockSize, numOfSalesRec, sales record, numOfRestockRec, RestockRecord, tax manufactures
        for (int i=0; i<numberOfCommodity; i++) {
            fout<<shopPtr[i].productCode<<","<<shopPtr[i].name<<","<<shopPtr[i].price<<","<<shopPtr[i].stockNum<<","<<shopPtr[i].stockSize<<","<<shopPtr[i].numOfSalesRec<<";";
            //read sales record
            for (int j=0; j<shopPtr[i].numOfSalesRec; j++) {
                fout<<shopPtr[i].salesRec[j].date.tm_year << "-" << shopPtr[i].salesRec[j].date.tm_mon << "-" << shopPtr[i].salesRec[j].date.tm_mday;
                fout<< "-" << shopPtr[i].salesRec[j].quantity;
                if (j!=shopPtr[i].numOfSalesRec-1) {
                    fout<< ";";
                }
            }
            fout<<","<<shopPtr[i].numOfRestockRec<<";";
            for (int k=0; k<shopPtr[i].numOfRestockRec; k++) {
                fout<< shopPtr[i].restockRec[k].deliveryTime.tm_year << "-" << shopPtr[i].restockRec[k].deliveryTime.tm_mon << "-" << shopPtr[i].restockRec[k].deliveryTime.tm_mday;
                fout<< "-" << shopPtr[i].restockRec[k].quantity;
                if (k!=shopPtr[i].numOfRestockRec-1) {
                    fout<< ";";
                }
            }
            fout<<","<<shopPtr[i].taxAmount<<","<<shopPtr[i].manufacturer<<endl;
        }
        fout.close();
        cout<<"\nAll records saved!\n"<<endl;
    }
    else{
        cout<<"\nUnable to open "<<fileName<<endl;
    }
    
}
