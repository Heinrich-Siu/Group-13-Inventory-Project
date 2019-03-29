#include <iostream>
#include <string>

using namespace std;

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
