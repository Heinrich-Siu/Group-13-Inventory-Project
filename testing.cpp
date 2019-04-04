#include <iostream>
#include <string>
#include <sstream>
#include "inventorysys.h"
//#include "inventorysys.cpp"

using namespace std;

void printUI()
{
    string ui = "1. \n"
                "2. \n"
                "3. \n"
                "4. \n"
                "5. \n"
                "6. \n"
                "7. \n"
                "8. \n"
                "9. Exit";
          cout << ui << endl;
}

void readCSVinventoryRec(commodity &commod, string data, int columnNum)
{
    switch(columnNum) //columnNum determine the information type
    {
        case 0: //index
            cout << "now is 0" << endl;
            commod.index = stoi(data);
            break;
        case 1: //
            commod.name = data;
            break;
        case 2: //
            commod.price = stod(data);
            break;
        case 3: //

            break;
        case 4: //

            break;
        case 5: //

            break;
        case 6: //

            break;
        case 7: //

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
    }
}

int main()
{
    commodity apple;
    //apple.index = 1;
    //apple.name = "Japan Apple";
    //cout << apple.index << endl;
    //cout << apple.name << endl;
    //printUI();

    string line = "11,22,33,44,55,66,77"; //simulating the commodity information in the file per line
    int lineArrIndicator = 0;

    //getline(myfile,type);
    istringstream ss(line);  //line as input stream
    string temp;
    int columnNum = 0;
    while(getline(ss,temp,','))  //reading commodity information per item in line
    {
         //cout<<temp<<endl;
        readCSVinventoryRec(apple, temp, columnNum);
        columnNum++;

    }

    cout << apple.index << " " << apple.name << " " << apple.price << endl;


    /*string currentWord = "";
    for(int j=0; j<line.length(); j++)  //loop through all character
    {
      if(line[j]== ',') //check if the character is alpha
      {
        cout << currentWord; //store full word to array
        currentWord = ""; //restore to initial state
        lineArrIndicator++;
        //lineArr[lineArrIndicator] = line[j];
        cout << " ";
        lineArrIndicator++;
      }
      else
      {
        currentWord += line[j]; //append character to word string
      }
      if(j==line.length()-1 && isalpha(line[j])) //for final character in the line
      {
        cout << currentWord; //store full word to array
        //lineArrIndicator++;

      }

    }*/


}
