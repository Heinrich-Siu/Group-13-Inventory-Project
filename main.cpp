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

/*
void lineToDataArr(commodity *&shopPtr, int numberOfCommodity, string line)
{
  string currentWord = "";
  for(int j=0; j<line.length(); j++)  //loop through all character in line
  {
    if(line[j]== ',') //check if the character is comma
    {
      cout << currentWord; //store full word to array
      currentWord = ""; //restore to initial state
      cout << " ";
    }
    else
    {
      currentWord += line[j]; //append character to word string
    }
    if(j==line.length()-1 && isalpha(line[j])) //for final character in the line
    {
      cout << currentWord; //store full word to array


    }

  }
    //shopPtr[numberOfCommodity]
}*/


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
  int count = -1;
  while(getline(wholeLine,temp_wholeLine,';'))  //reading commodity information per item in line
  {

      //cout<<temp_wholeLine<<endl;
      if(count == -1)
      {
          numOfRec = stoi(temp_wholeLine);
          thisRecord = new salesRecord[numOfRec];
          count++;
          //cout<<numOfRec<<endl;
      }
      else
      {
          istringstream yearAndDate(temp_wholeLine);
          int times = 0;
          while(getline(yearAndDate,temp_yearAndDate,'-'))
          {
              //cout<<temp_yearAndDate<<endl;
              switch(times)
              {
                  case 0:
                      thisRecord[count].date.tm_year = stoi(temp_yearAndDate);
                      break;
                  case 1:
                      thisRecord[count].date.tm_mon = stoi(temp_yearAndDate);
                      break;
                  case 2:
                      thisRecord[count].date.tm_mday = stoi(temp_yearAndDate);
                      break;
                  case 3:
                      thisRecord[count].quantity = stoi(temp_yearAndDate);
                      break;
              }
              times++;
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
  int count = -1;
  while(getline(wholeLine,temp_wholeLine,';'))  //reading commodity information per item in line
  {

      //cout<<temp_wholeLine<<endl;
      if(count == -1)
      {
          numOfRec = stoi(temp_wholeLine);
          thisRecord = new salesRecord[numOfRec];
          count++;
          //cout<<numOfRec<<endl;
      }
      else
      {
          istringstream yearAndDate(temp_wholeLine);
          int times = 0;
          while(getline(yearAndDate,temp_yearAndDate,'-'))
          {
              //cout<<temp_yearAndDate<<endl;
              switch(times)
              {
                  case 0:
                      thisRecord[count].date.tm_year = stoi(temp_yearAndDate);
                      break;
                  case 1:
                      thisRecord[count].date.tm_mon = stoi(temp_yearAndDate);
                      break;
                  case 2:
                      thisRecord[count].date.tm_mday = stoi(temp_yearAndDate);
                      break;
                  case 3:
                      thisRecord[count].quantity = stoi(temp_yearAndDate);
                      break;
              }
              times++;
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

void loadAllRecord(commodity *&shopPtr, int &numberOfCommodity)
{
    shopPtr = new commodity[];
    string shopRecFileName = ""
    cout << "Please input the file name of the record: ";
    cin >> shopRecFile;
    cout << "Loading record" << endl;
    ifstream shop1 (shopRecFile); //data will be comma-seperated(,)

    string line;
    While(getline(shop1, line))
    {

        numberOfCommodity++;
    }
}

void printSubUI() {
  string ui = "";
        cout << ui << endl;
}

int main()
{
    commodity *shopPtr = new commodity[];
    int numberOfCommodity = 0;
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
