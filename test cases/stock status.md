## Stock status test case
First add a sales record.   
Then show stock status, sales prediction. After that, delete obsolete commodity, show result and exit function.    
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
Please input a command: <b>6</b>


You are updating sales and restock record

Do you know the product code of the commodity that you want to update?(Y/N) <b>Y</b>

Please enter the product code of the commodity that you want to add record to: <b>301</b>

Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>1</b>
You are adding record of sales of Commodity G (301)
Sales time (YYYY-MM-DD): <b>2019-6-17</b>
Quantity: <b>224</b>
Record added!

Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>3</b>

Exiting record change

Returning to main page...

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
Please input a command: <b>10</b>

Showing inventory status:
1. Show stock status
2. Show sales prediciton
3. Delete obsoleted commodity
4. Quit
Enter your choice here: <b>1</b>

Showing stock status:

Note: the current month will be included in the prediction
Enter current date in (YYYY-MM, e.g. 2019-12) format: <b>2019-07</b>
Choose the number of month(s) for prediction: <b>3</b>

Out of stock warning: 
Index     Product Code   Name                Number of stock
5         203            Commodity F         0                   

6         301            Commodity G         0                   


Predicted out of stock warning: 
Index     Product Code   Name                Current stock       Predicted sales in 3 month    Difference          
2         103            Commodity C         200                 350                           -150                
6         301            Commodity G         0                   253.667                       -253.667            

1. Show stock status
2. Show sales prediciton
3. Delete obsoleted commodity
4. Quit
Enter your choice here: <b>2</b>

Note: the current month will be included in the prediction
Enter current date in (YYYY-MM, e.g. 2019-12) format: <b>2019-07</b>
Choose the number of month(s) for prediction: <b>3</b>
Index     Product Code   Name                Current stock       Predicted sales in 3 month
0         101            Commodity A         100                 33.3333             
1         102            Commodity B         137                 24.3333             
2         103            Commodity C         200                 350                 
3         201            Commodity D         94                  0.666667            
4         202            Commodity E         10                  0                   
5         203            Commodity F         0                   0                   
6         301            Commodity G         0                   253.667             
7         302            Commodity H         96                  46.3333             
8         303            Commodity I         167                 77.6667             

1. Show stock status
2. Show sales prediciton
3. Delete obsoleted commodity
4. Quit
Enter your choice here: <b>3</b>

Searching for outdated commodity
Delete commodity without sales in the last n months
Enter value of n: <b>3</b>
From when (YYYY-MM, e.g. 2019-12) to 3 months before: <b>2019-08</b>
Are you sure to delete Commodity A?
Enter Yes or No by (Y/N): <b>N</b>
Are you sure to delete Commodity D?
Enter Yes or No by (Y/N): <b>Y</b>
Selected commodity deleted!
Are you sure to delete Commodity E?
Enter Yes or No by (Y/N): <b>N</b>
Are you sure to delete Commodity F?
Enter Yes or No by (Y/N): <b>N</b>

Outdated commodity deleted

1. Show stock status
2. Show sales prediciton
3. Delete obsoleted commodity
4. Quit
Enter your choice here: <b>4</b>
Returning to main page...

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
0         101            Commodity A         $2        100            1              1                      2                         Man A                    $0             
1         102            Commodity B         $34       137            2              3                      2                         Man B                    $1             
2         103            Commodity C         $42       200            14             4                      3                         Man C                    $1.5           
3         202            Commodity E         $54       10             2              0                      1                         Man E                    $5             
4         203            Commodity F         $22       0              14             0                      0                         Man F                    $1             
5         301            Commodity G         $21       0              1              13                     6                         Man G                    $2             
6         302            Commodity H         $340      96             2              5                      3                         Man H                    $17.51         
7         303            Commodity I         $42       167            14             4                      2                         Man I                    $0             

All results have shown

Returning to main page...
</pre>
