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

int main()
{
    commodity apple;
    apple.index = 1;
    apple.name = "Japan Apple";
    //cout << apple.index << endl;
    //cout << apple.name << endl;
    //printUI();

    string line = "11,22,33,44,55,66,77";
    int lineArrIndicator = 0;

    //getline(myfile,type);
    istringstream ss(line);
    string temp;
    while(getline(ss,temp,','))
    {
         cout<<temp<<endl;
    }

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
