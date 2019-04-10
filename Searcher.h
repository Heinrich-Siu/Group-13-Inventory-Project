#ifndef Searcher_h
#define Searcher_h

using namespace std;

void ranger(int &max, int &min, int absoulteMax){
    //ask if larger, smaller, or between
    cout<<"You are searching by 1.Larger or equal than  2. Smaller or equal than   3.Between two numbers\n";
    int mode =0; cin>>mode;
    if (mode==1){
        cout<<"The number is larger or equal than:";
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

void searcher(int type, int* &position, int numberOfCommodity){
    //poaition goes from 0 to number-1
    int option = -1;
    switch (type) {
        case 1:{
            cout<<"Search by 1. Specific index  2. Range of index\n";
            cin>>option;
            //find by specific number
            if (option==1) {
                int target = -1;
                cout<<"\nYour target index is : ";
                cin>>target;
                for (int i=0; i<numberOfCommodity; i++) {
                    if (i==target) continue;
                    position[i]=-1;
                }
            }
            //find by range
            else{
            int max, min;
            ranger(max, min, numberOfCommodity-1);
            //Larger or equal to: from 0 to min = -1;
            //Smaller or equal to: from max to numberOfCommodity = -1;
            //Between two numbers: from 0 to min = -1 AND from max to numberOfCommodity = -1;
            for (int j=0; j<min; j++) position[j]=-1;
            for (int k=max+1; (k>max)&&(k<numberOfCommodity); k++) position[k]=-1;
            }
        }
            break;
            
        default:
            break;
    }
}
void optionPrinter(int i){ //print the columns
    switch (i) {
            //"1. Index 2.ProductCode 3.Name 4.Price 5.StockNum 6.StockSize 7.NumOfSalesRec 8.numOfRestockRec"
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
            cout.width(21); cout<<left<<"Number of Sales Record";
            break;
        case 8:
            cout.width(24); cout<<left<<"Number of Restock Record";
            break;
        case 9:
            cout.width(15); cout<<left<<"Manufacturer";
            
        default:
            break;
    }
}
void specPrinter(int i, commodity * product){ //print product info according to request
    switch (i) {
            //"1. Index 2.ProductCode 3.Name 4.Price 5.StockNum 6.StockSize 7.NumOfSalesRec 8.numOfRestockRec 9.manufacturer"
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
            cout<<"$"; cout.width(14); cout<<left<<product->stockNum;
            break;
        case 6:
            cout.width(15); cout<<left<<product->stockSize;
            break;
        case 7:
            cout.width(21); cout<<left<<product->numOfSalesRec;
            break;
        case 8:
            cout.width(24); cout<<left<<product->numOfRestockRec;
            break;
        case 9:
            cout.width(15); cout<<left<<product->manufacturer;
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
    cout<<"1. Index 2.Product Code 3.Name 4.Price 5.Stock Number 6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer\n";
    int* fields = new int[9];
    int a=0;
    for (int k=0; a!=-1; k++) {
        cin>>a;
        fields[k] = a;
    }
    for (int i=0; (fields[i])!=-1; i++) optionPrinter(fields[i]); //print the columns
    cout<<endl;
    for (int i=0; i<numberOfCommodity; i++) recordPrinter(shopPtr+i,fields); //print the data one by one
    delete [] fields;
}

#endif /* Searcher_h */
