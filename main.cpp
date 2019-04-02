#include <iostream>
#include <string>
#include <inventorysys.h>

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
