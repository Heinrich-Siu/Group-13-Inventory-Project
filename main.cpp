#include <iostream>
#include <string>
#include <fstream>
#include <inventorysys.h>

using namespace std;

void printMainUI()
{
    string ui = "*********XXX Company Commodity Inventory system*********"
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
}

/*input:  thisRecord: pointer to salesRecord in commodity Struct
          line: the whole string containing information of sales record
          numOfRec: number of record, store back to commodity Struct

Remark: **Declare first**
        salesRecord *thisRecord;
        int numOfRec;
*/
void readSalesRecord(salesRecord *&thisRecord, string line, int &numOfRec)
{
  istringstream wholeLine(line);  //line as input stream
  string temp_wholeLine, temp_yearAndDate;
  int count = -1; //count number of record, started at -1 because the first column is number of record
  while(getline(wholeLine,temp_wholeLine,';'))  //reading commodity information per item in line
  {

      //cout<<temp_wholeLine<<endl;
      if(count == -1) //first set is the number of record
      {
          numOfRec = stoi(temp_wholeLine);  //read the number of record
          thisRecord = new salesRecord[numOfRec]; //initiate Dynamic array for the record using the numOfRec
          count++;
          //cout<<numOfRec<<endl;
      }
      else
      {
          istringstream yearAndDate(temp_wholeLine); //string act like input stream
          int times = 0; //column count
          while(getline(yearAndDate,temp_yearAndDate,'-')) //string split by '-'
          {
              //cout<<temp_yearAndDate<<endl;
              switch(times)
              {
                  case 0:
                      thisRecord[count].date.tm_year = stoi(temp_yearAndDate); //first column is year
                      break;
                  case 1:
                      thisRecord[count].date.tm_mon = stoi(temp_yearAndDate); //Second column is month
                      break;
                  case 2:
                      thisRecord[count].date.tm_mday = stoi(temp_yearAndDate);  //Third column is day of month
                      break;
                  case 3:
                      thisRecord[count].quantity = stoi(temp_yearAndDate);  //Fourth column is quantity
                      break;
              }
              times++; //go to next column
          }
          count++;
      }

  }
  //For Debugging
  //cout << numOfRec << endl;
  /*for(int i=0; i<numOfRec; i++)
  {
      //cout << thisRecord[i].date.tm_year << "-" << thisRecord[i].date.tm_mon << "-" << thisRecord[i].date.tm_mday << ":" << thisRecord[i].quantity << endl;
  }*/
}

/*input:  thisRecord: pointer to restock record in commodity Struct
          line: the whole string containing information of sales record
          numOfRec: number of record, store back to commodity Struct

Remark: **Declare first**
        salesRecord *thisRecord;
        int numOfRec;
*/
void readRestockRecord(restockRecord *&thisRecord, string line, int &numOfRec)
{
  istringstream wholeLine(line);  //line as input stream
  string temp_wholeLine, temp_yearAndDate;
  int count = -1; //count number of record, started at -1 because the first column is number of record
  while(getline(wholeLine,temp_wholeLine,';'))  //reading commodity information per item in line
  {

      //cout<<temp_wholeLine<<endl;
      if(count == -1)
      {
          numOfRec = stoi(temp_wholeLine);  //read the number of record
          thisRecord = new salesRecord[numOfRec]; //initiate Dynamic array for the record using the numOfRec
          count++;
          //cout<<numOfRec<<endl;
      }
      else
      {
          istringstream yearAndDate(temp_wholeLine);  //string act like input stream
          int times = 0;  //column count
          while(getline(yearAndDate,temp_yearAndDate,'-')) //string split by '-'
          {
              //cout<<temp_yearAndDate<<endl;
              switch(times)
              {
                  case 0:
                      thisRecord[count].date.tm_year = stoi(temp_yearAndDate);  //first column is year
                      break;
                  case 1:
                      thisRecord[count].date.tm_mon = stoi(temp_yearAndDate); //Second column is month
                      break;
                  case 2:
                      thisRecord[count].date.tm_mday = stoi(temp_yearAndDate);  //Third column is day of month
                      break;
                  case 3:
                      thisRecord[count].quantity = stoi(temp_yearAndDate);   //Fourth column is quantity
                      break;
              }
              times++;  //go to next column
          }
          count++;
      }

  }
  //For Debugging
  //cout << numOfRec << endl;
  /*for(int i=0; i<numOfRec; i++)
  {
      //cout << thisRecord[i].date.tm_year << "-" << thisRecord[i].date.tm_mon << "-" << thisRecord[i].date.tm_mday << ":" << thisRecord[i].quantity << endl;
  }*/
}

void readCSVinventoryRec(commodity &commod, string data, int columnNum)
{
    switch(columnNum) //columnNum determine the information type
    {
        case 0: //int index
            //cout << "now is 0" << endl;
            commod.index = stoi(data);
            break;
        case 1: //int productCode
            commod.productCode = stoi(data);
            break;
        case 2: //string name
            commod.name = data;
            break;
        case 3: //double price
            commod.price = stod(data);
            break;
        case 4: //double stockNum
            commod.stockNum = stod(data);
            break;
        case 5: //int stockSize
            commod.stockSize = stoi(data);
            break;
        case 6: //salesRecord *salesRec
            commod.salesRec = readSalesRecord(data);
            break;
        case 7: //tm *restockRec
            commod.restockRec = readRestockRecord(data);
            break;
        case 8: //double taxAmount
            commod.taxAmount = stod(data);
            break;
        case 9: //string manufacturer
            commod.manufacturer = data;
            break;
    }
}

void grow_commodityRecord(commodity *&shopPtr, int originSize, int grownSize) //increase the size of Dynamic array of commodity to hold record
{
    commodity grownRecordPtr = new commodity[grownSize];

    for(int i=0; i<originSize; i++)
    {
        grownRecordPtr[i] = shopPtr[i];
    }
    delete [] shopPtr; //free original Dynamic array in shopPtr

    shopPtr = grownRecordPtr; //point shopPtr pointer to the grown Dynamic array
}



/*
input:  shopPtr: shop pointer pointed to nothing with type commodity
        numberOfCommodity: number of Commodity by reference
*/
void loadAllRecord(commodity *&shopPtr, int &numberOfCommodity)
{

    shopPtr = new commodity[numberOfCommodity+1]; //initiate the Dynamic array with size 1
    string shopRecFileName = "";  //file name of the record
    cout << "Please input the file name of the record: ";
    cin >> shopRecFile; //user input file name of the record
    cout << "Loading record...." << endl;
    ifstream shop1 (shopRecFile); //data will be comma-seperated(,)

    string line;
    While(getline(shop1, line)) //get commodity information per line
    {
        if(numberOfCommodity>0) //when more than 1 commodity
        {
            grow_commodityRecord(shopPtr, numberOfCommodity, numberOfCommodity+1); //increase the size of the record array by 1 to hold one more record
        }
        int columnNum = 0;
        for(int i=0; i<=9; i++)
        {
            readCSVinventoryRec(shopPtr[numberOfCommodity], line, columnNum); //read CSV of commodity to dynamic array
            columnNum++;
        }

        numberOfCommodity++; //incrase one after one record is stored
    }
    cout << "All record loaded"
}

void printSubUI() {
  string ui = "";
        cout << ui << endl;
}

int main()
{
    commodity *shopPtr;
    int numberOfCommodity = 0;
    loadAllRecord(shopPtr, numberOfCommodity);
    printUI();
    int userInput;
    cout << "Please input a command: "
    cin >> userInput;

    while(userInput != (Exit))
    {
        if(userInput >= 0 || userInput <=9)
        {
            switch(userInput)
            {
                case 1:
                break;

                case 2:
                break;

                case 3:
                break;

                case 4:
                break;

                case 5:
                break;

                case 6:
                break;

                case 7:
                break;

                case 8:
                break;

                case 9:
                break;
          }
      else
      {
      cout << "Your input is invalid" << endl;
      }

      cin >> userInput;


        }
    }
    cout << "Program end Sucessfully" << endl;
}
