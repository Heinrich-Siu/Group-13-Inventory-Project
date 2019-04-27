## Sample file handling test case

1. Case 1
Load a record and save the file(to try if the function works).   
Then save the file with another name(Non-overwriting) and quit the programme.
<pre>
Please input the file name of the record: <b>Sample Record.txt</b>
Loading record....
Loading CSV....
All record loaded

Out of stock warning: 
Index     Product Code   Name                Number of stock
5         203            Commodity F         0                   

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
Please input a command: <b>11</b>
Do you want to overwrite record to current file instead of creating a new file?   Enter Y/N: <b>Y</b>

All records saved!

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
Please input a command: <b>11</b>
Do you want to overwrite record to current file instead of creating a new file?   Enter Y/N: <b>N</b>

Enter the file name you want to create: <b>another sample record.txt</b>

All records saved!

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
Please input a command: <b>12</b>

Are you sure to end the Programme?
Press "Y" to terminate the programme, press "N" to continue: <b>Y</b>
Program end Sucessfully. Thanks for using our programme :) 
</pre>

## Case 2
Enter nothing for the input file name part, and try to save file.   
Get error message and save to a new file.    
Then try to exit programme but do not, the actually exit programme.   
<pre>
Please input the file name of the record: //Nothing here, directly press enter key
Loading record....
Loading CSV....
All record loaded
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
Please input a command: <b>11</b>
Do you want to overwrite record to current file instead of creating a new file?   Enter Y/N: <b>Y</b>

Unable to open 
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
Please input a command: <b>11</b>
Do you want to overwrite record to current file instead of creating a new file?   Enter Y/N: <b>N</b>

Enter the file name you want to create: <b>new file name.txt</b>

All records saved!

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
Please input a command: 12

Are you sure to end the Programme?
Press "Y" to terminate the programme, press "N" to continue: <b>N</b>

Continuing programme...

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
Please input a command: <b>12</b>

Are you sure to end the Programme?
Press "Y" to terminate the programme, press "N" to continue: <b>Y</b>
Program end Sucessfully. Thanks for using our programme :) 
</pre>
