#include <iostream>
#include <string>
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
    printUI();
}
