## Check sales history test cases
User inputs are in **bold**     
1. With known product code, show sales of 2 months(2019-06 and 2019-07) as well as whole sales history
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
Please input a command: <b>8</b>

Preparing to show sales record...

Do you know the product code of the commodity that you want to check?(Y/N) <b>Y</b>
Please enter the product code of the commodity record that you want to check: <b>103</b>

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>1</b>

Enter the value of n: 2
Enter the ending month(included in the search) of the search
Please enter the result in (YYYY-MM, e.g. 2019-12) format: <b>2019-07</b>
Total 1 record in the last 2 months found.

Date (YYYY-MM-DD)   Quantity
2019-6-2            150   

Total restock in the last 2 months is 150.

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>2</b>
Total 4 record found.

Date (YYYY-MM-DD)   Quantity
2019-5-12           300   
2019-5-14           100   
2019-5-25           500   
2019-6-2            150   

Total sales in the whole history is 1050.

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>3</b>
Returning to main page...
</pre>

2. Without known product code, search for product code first

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
Please input a command: <b>8</b>

Preparing to show sales record...

Do you know the product code of the commodity that you want to check?(Y/N) <b>N</b>
~~Please first search the commodity and check the record by productCode~~

*********Commodity searching*********

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: <b>3</b>
Enter the Name you want to search. Can be a sub string of the Name
Enter your word here: <b>A</b>

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

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: <b>11</b>

Exiting search...

Please enter the product code of the commodity record that you want to check: 
</pre>
