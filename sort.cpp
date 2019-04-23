#include <iostream>
//#include <string>
#include "sort.h"

void swap(commodity *xp, commodity *yp)
{
    commodity temp = *xp;
    *xp = *yp;
    *yp = temp;
}
bool compareParameter(commodity *arr, int j, int min_idx, int option, int order)
{
    switch (option) {
        case 1: //product code
            if(order==1)
            return arr[j].productCode < arr[min_idx].productCode;
            else if(order==2)
            return arr[j].productCode < arr[min_idx].productCode;
            break;

        case 2: //name
            if(order==1)
            return arr[j].name < arr[min_idx].name;
            else if(order==2)
            return arr[j].name < arr[min_idx].name;
            break;

        case 3: //price
            if(order==1)
            return arr[j].price < arr[min_idx].price;
            else if(order==2)
            return arr[j].price < arr[min_idx].price;
            break;

        case 4: //number of stock
            if(order==1)
            return arr[j].stockNum < arr[min_idx].stockNum;
            else if(order==2)
            return arr[j].stockNum < arr[min_idx].stockNum;
            break;

        case 5: //size of stock
            if(order==1)
            return arr[j].stockSize < arr[min_idx].stockSize;
            else if(order==2)
            return arr[j].stockSize < arr[min_idx].stockSize;
            break;

        case 6: //numOfSalesRec
            if(order==1)
            return arr[j].numOfSalesRec < arr[min_idx].numOfSalesRec;
            else if(order==2)
            return arr[j].numOfSalesRec < arr[min_idx].numOfSalesRec;
            break;

        case 7: //numOfRestockRec
            if(order==1)
            return arr[j].numOfRestockRec < arr[min_idx].numOfRestockRec;
            else if(order==2)
            return arr[j].numOfRestockRec < arr[min_idx].numOfRestockRec;
            break;

        case 8: //taxAmount
            if(order==1)
            return arr[j].taxAmount < arr[min_idx].taxAmount;
            else if(order==2)
            return arr[j].taxAmount < arr[min_idx].taxAmount;
            break;

        case 9: //manufacturer
            if(order==1)
            return arr[j].manufacturer < arr[min_idx].manufacturer;
            else if(order==2)
            return arr[j].manufacturer < arr[min_idx].manufacturer;
            break;
    }
}
void selectionSort(commodity *arr, int n, int choice, int order)
{
    int i, j, min_idx, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (compareParameter(arr, j, min_idx, choice, order))
            {
                min_idx = j;
            }


        // Swap the found minimum element with the first element
        swap(arr+min_idx, arr+i);
    }
}

void sortMenu()
{
    cout << endl;
    cout << "Sort by: 1.  Product Code\n"
            "         2.  Name\n"
            "         3.  Price\n"
            "         4.  Number of stock\n"
            "         5.  Size of stock\n"
            "         6.  Numeber of Sales Record\n"
            "         7.  Numeber of Restock Record\n"
            "         8.  Tax Amount\n"
            "         9.  Manufacturer\n"
            "         10. Quit\n"
            "Choice: ";
}

void orderMenu()
{
    cout << endl;
    cout << "In: 1. Ascending Order\n"
            "    2. Descending Order\n"
            "    3. Abort and Quit\n"
            "Choice: ";
}

void sortingInventory(commodity *shopPtr, int numberOfCommodity)
{
    int choice = 0, order = 0;
    sortMenu(); //print sorting menu
    cin >> choice;
    if(choice>=1 && choice<=10) //check validity of input
    {
        if(choice==10) //quit the function
        {
            cout << endl << "Quited Sorting funtion" << endl;
        }
        else
        {
            orderMenu(); //print Ascending/Descending Order menu
            cin >> order;
            if(order>=1 && order<=3) //check validity of input
            {
                if(order==3) //abort and quit the function
                {
                    cout << endl << "Aborted and quited Sorting funtion" << endl;
                }
                else //excute sorting if all input is valid
                {
                    selectionSort(shopPtr, numberOfCommodity, choice, order);

                    //rearrange the order
                    indexer(shopPtr, numberOfCommodity);

                    cout << "Sorting completed" << endl;
                }
            }
            else
            {
                cout << "Your input is not valid!";
            }
        }
    }
    else
    {
        cout << "Your input is not valid!";
    }


}
