## Test cases of Update commodity

1. Commodity changing with known product code
<pre>
*********XXX Company Commodity Inventory system*********
1.  Show all inventory record
2.  Search an Commodity
3.  Add new commodity
4.  Check Inventory Space
5.  Update commodity
6.  Stock sales/restock
7.  Sort working record
8.  Check Sales History
9.  Check Restock History
10. Check inventory status
11. Save working record to file
12. Exit
Please input a command: <b>5</b>

Preparing to modify commodity... 
Do you know the product code of the commodity that you want to update?(Y/N) <b>Y</b>

Please enter the product code of the commodity that you want to update: 101

Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer             Tax Amount     
0         101            Commodity A         2         100            1              1                      2                         Man A                    $0             

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: 1
Change from 101 to: <b>100</b>
The product code is now: <b>100</b>
Commodity updated

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: <b>2</b>
Change from Commodity A to: <b>Modified A</b>
The product name is now: Modified A
Commodity updated

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: <b>3</b>
Change from 2 to: <b>3</b>
The product price is now: 3
Commodity updated

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: <b>4</b>
Change from 1 to: <b>2</b>
The size of product is now: 2
Commodity updated

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: <b>5</b>
Change from 0 to: <b>0.5</b>
The tax amount of product is now: <b>0.5</b>
Commodity updated

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: <b>6</b>
Change from Man A to: <b>Man A up</b>
The manufacturer of product is now: Man A up
Commodity updated

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: <b>7</b>

Exiting commodity update...

*********XXX Company Commodity Inventory system*********
1.  Show all inventory record
2.  Search an Commodity
3.  Add new commodity
4.  Check Inventory Space
5.  Update commodity
6.  Stock sales/restock
7.  Sort working record
8.  Check Sales History
9.  Check Restock History
10. Check inventory status
11. Save working record to file
12. Exit
Please input a command: <b>1</b>
</pre>

Below is the result shown by print all commodity

<pre>

*********Showing all inventory record*********

Input the number one by one in any sequence and input -1 when done or enter 11 to print All
*** E.g. Enter your choice here: 1 2 5 4 -1 ***
Here are the options: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11.ALL
Enter your choice here: <b>11</b>

*********Enquiry result*********

Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer             Tax Amount     
0         100            Modified A          3         100            2              1                      2                         Man A up                 $0.5             
1         102            Commodity B         34        137            2              3                      2                         Man B                    $1             
2         103            Commodity C         42        200            14             4                      3                         Man C                    $1.5           
3         201            Commodity D         64        94             1              3                      1                         Man D                    $0.33          
4         202            Commodity E         54        10             2              0                      1                         Man E                    $5             
5         203            Commodity F         22        0              14             0                      0                         Man F                    $1             
6         301            Commodity G         21        224            1              12                     6                         Man G                    $2             
7         302            Commodity H         340       96             2              5                      3                         Man H                    $17.51         
8         303            Commodity I         42        167            14             4                      2                         Man I                    $0             

All results have shown

Returning to main page...
</pre>

2. Without knowing the product code
<pre>

</pre>
