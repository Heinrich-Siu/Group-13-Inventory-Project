## Check restock record

1. With known product code
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
Please input a command: <b>9</b>

Preparing to show restock record...

Do you know the product code of the commodity that you want to check?(Y/N) <b>Y</b>
Please enter the product code of the commodity record that you want to check: <b>301</b>

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>1</b>

Enter the value of n: 2
Enter the ending month(included in the search) of the search
Please enter the result in (YYYY-MM, e.g. 2019-12) format: <b>2019-06</b>
Total 4 record in the last 2 months found.

Date (YYYY-MM-DD)   Quantity
2019-6-14           100   
2019-6-2            300   
2019-5-21           100   
2019-5-3            200   

Total restock in the last 2 months is 700.

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>2</b>
Total 6 record found.

Date (YYYY-MM-DD)   Quantity
2019-4-1            100   
2019-4-25           100   
2019-5-3            200   
2019-5-21           100   
2019-6-2            300   
2019-6-14           100   

Total restock in the whole history is 900.

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>3</b>
Returning to main page...
</pre>

2. Without known product code
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
Please input a command: <b>9</b>

Preparing to show restock record...

Do you know the product code of the commodity that you want to check?(Y/N) <b>N</b>
~~Please first search the commodity and check the record by productCode~~

*********Commodity searching*********

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: <b>5</b>
Search by 1. Specific Stock Number  2. Range of Stock Number
Enter your choice here: <b>2</b>

You are searching by 1.Larger or equal than  2. Smaller or equal than   3.Between two numbers
Enter your choice here: <b>1</b>

The number is larger or equal than: <b>100</b>

Choose how to show your search result
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
6         301            Commodity G         $21       224            1              12                     6                         Man G                    $2             
8         303            Commodity I         $42       167            14             4                      2                         Man I                    $0             

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: <b>11</b>

Exiting search...

Please enter the product code of the commodity record that you want to check: 
</pre>


