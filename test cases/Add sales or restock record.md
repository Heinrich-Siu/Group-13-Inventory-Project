## Add sales or restock record
User input are in **bold**    
1. If the product code is known
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

Please enter the product code of the commodity that you want to add record to: <b>203</b>

Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>2</b>
You are adding record of restock of Commodity F (203)
Delivery time (YYYY-MM-DD): <b>2019-05-01</b>
Quantity: <b>-10</b>
Action illegal: Adding zero or negative stock quantity restock record

Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>2</b>
You are adding record of restock of Commodity F (203)
Delivery time (YYYY-MM-DD): <b>2019-05-01</b>
Quantity: <b>100</b>
Record added!

Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>1</b>
You are adding record of sales of Commodity F (203)
Sales time (YYYY-MM-DD): <b>2019-05-10</b>
Quantity: <b>-10</b>
Action illegal: Adding zero or negative stock quantity sales record

Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>1</b>
You are adding record of sales of Commodity F (203)
Sales time (YYYY-MM-DD): <b>2019-05-10</b>
Quantity: <b>101</b>
Error! Your action will result in negatve stock number(From 100 -> -1 )
Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>1</b>
You are adding record of sales of Commodity F (203)
Sales time (YYYY-MM-DD): <b>2019-05-10</b>
Quantity: <b>99</b>
Record added!

Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: <b>3</b>

Exiting record change

Returning to main page...
</pre>
This is the end of adding slaes/restock record    
Below is the proof of the added record
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
Please enter the product code of the commodity record that you want to check: <b>203</b>

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>2</b>
Total 1 record found.

Date (YYYY-MM-DD)   Quantity
2019-5-10           99    

Total sales in the whole history is 99.

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>3</b>
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
Please input a command: <b>9</b>

Preparing to show restock record...

Do you know the product code of the commodity that you want to check?(Y/N) <b>Y</b>
Please enter the product code of the commodity record that you want to check: <b>203</b>

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>2</b>
Total 1 record found.

Date (YYYY-MM-DD)   Quantity
2019-5-1            100   

Total restock in the whole history is 100.

Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: <b>3</b>
Returning to main page...
</pre>

2. If the product code is not known

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

Do you know the product code of the commodity that you want to update?(Y/N) <b>N</b>
~~Please first search the commodity and change the record by product code~~

*********Commodity searching*********

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: <b>1</b>
Search by 1. Specific Index  2. Range of Index
Enter your choice here: <b>2</b>

You are searching by 1.Larger or equal than  2. Smaller or equal than   3.Between two numbers
Enter your choice here: <b>1</b>

The number is larger or equal than: <b>0</b>

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
3         201            Commodity D         $64       94             1              3                      1                         Man D                    $0.33          
4         202            Commodity E         $54       10             2              0                      1                         Man E                    $5             
5         203            Commodity F         $22       1              14             1                      1                         Man F                    $1             
6         301            Commodity G         $21       224            1              12                     6                         Man G                    $2             
7         302            Commodity H         $340      96             2              5                      3                         Man H                    $17.51         
8         303            Commodity I         $42       167            14             4                      2                         Man I                    $0             

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: <b>11</b>

Exiting search...


Please enter the product code of the commodity that you want to add record to: 
</pre>

3. If the product code entered does not exist
<pre>
Please enter the product code of the commodity that you want to add record to: <b>1</b>

The product code you entered does not exist
Returning to main page...
</pre>
