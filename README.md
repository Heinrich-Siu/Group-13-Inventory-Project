# Group-13-Inventory-Project
# Commodity inventory system

**Problem statement:**
To control and manage ordering and storage of inventory, an inventory management system is very important. It can optimize the management process. A retail chain shore company request a commodity inventory system to manage their commodity. In this project, our aims is to build a commodity inventory system for staff to perform management in the inventory, such as manage and record commodity inventory in multiple shops, providing necessary data for procurements and delivering alerts when exceptional events happened.

**Problem setting**
The company need a inventory system to manage the inventory in different retail shop. This system should be able to store and alter the inventory record, also other additional function. The target user is the warehouse team. They will use the system to manage the inventory.

**Assumption**
1. Maximum storage size is 5000 and measure in quantity.
--------------------------------------------------------

**Inventory record:<br/>**
-----------------------------------------

|information              |Data type|
|:---                     |  :---:  |
|Product code             |Int      |
|Product name             |String   |
|Price                    |Double   |
|Number of stock          |Double   |
|Stock size               |Int      |
|Number of sales record   |Int      |
|Number of restock record |Int      |
|Quantity                 |Int      |
|Tax amount               |Double   |
|manufacturer             |String   |


Any file in the root directory with the following structure:  
```(Product code),(Product name),(Price),(Number of stock),(Stock size),((Number of sales record);(YYYY-MM-DD-Quantity)*n),((Number of restock record);(YYYY-MM-DD-Quantity)*n),(Tax amount),(Manufacturer)```  
eg.  
```333,Apple,10,70,5,2;2019-4-6-3;2019-4-7-2,3;2019-3-14-5;2019-3-16-7;2019-3-27-10,2.5,Fuji```  

**if the commodity do not have sales/restock record:**  
```964,Orange,20,0,5,0;,0;,3.5,China```  
leave ```(YYYY-MM-DD-Quantity)``` this part empty

**Usage:<br/>**
----------------
### `makefile`
```sh
$ make
```
Recompiling the program

### `main.out`
```sh
$ ./main.out
```
To execute the program.

**Run the code on test case:<br/>**
-----------------------------------
Testcase 1 
### `input1`
```
content
```


Testcase 2
### `input2`
```
content
```

Testcase 3
### `input3`
```
content
```


**Function and feature**
1) Load commodity inventory record of different shop from files; 

2) Search commodity according to different filters (e.g. in-stock/out-of-stock, range of price, size, etc.);

3) Insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement,

4) Delete obsolete commodity;

5) Update commodity information;

6) Automatic change of inventory status according to the amount of commodity that is currently available (e.g. when the amount reaches zero, the inventory status would become “out-of-stock”);

7) Deliver alerts when the commodity is “out-of-stock”.

8) Addition to (7) out of stock alert, add feature to suggestion A to remind add stock<br/>

9) Check Inventory Space and make alerts<br/>

**Commodity Information should include:**

1. Wholesale/Retail Price<br/>
2. Space used of one unit of the Commodity <br/>
3. Number of stock in different store<br/>
4. Sales and restock record (Whole history)<br/>
5. Tax amount<br/>
6. Manufacturer<br/>
7. Product code<br/>

**Operations:<br/>**

1.  Show all inventory record  
2.  Search an Commodity  
3.  Add new commodity  
4.  Check Inventory Space    
5.  Update commodity  
6.  Stock sales/restock 
7.  Sort working record by different parameter(eg. name, price, etc.)   
8.  Check Sales History (Whole history, customize number of month) and return total in the period   
9.  Check Restock History (Whole history, customize number of month) and return total in the period 
10. Check inventory status (stock status, sales prediction, delete outdated commodity)  
11. Save working record to file 





# User guide:

<details>
  <summary>Basic operations</summary>
        
## Initializing the programme
Everytime the programme is executed, you will be asked to enter the filename of the record:
```
Please input the file name of the record: 
```
If this is the first time this programme is used, enter a file name to create a empty file to work with.    
You can choose to save to that file when necessary by choosing option _11. Save working record to file_.      
Alternativly, if you already have a working file, just simply enter the file name to start the programme.  
    
If done correctly, you should see
```
Loading record....
Loading CSV....
All record loaded
```
    
Note: The programme does not modify your file unless you choose to do so by choosing option _11. Save working record to file_ and choose to overwrite the file. 

## Understanding the operation basics of the main menu
After records are succesfully loaded, you should see the following main menu    

```
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
Please input a command: 
```
Choose the operation you want by entering a number that corresponse to the description of the menu above    
Then press `enter` to execute that function
For example you want to `Show all inventory record`, enter `1` and press the `enter` key  
Details of how to use the functions in the programme is included below  
    
## Ending the programme
After you are done with the programme, you can save the file first then exit or simply exit without saving  
To terminate the programme, press `12` and `enter` to exit the programme
YOu will be asked
```
Are you sure to end the Programme?
Press "Y" to terminate the programme, press "N" to continue: N
```
Press `Y` to end the programme and press `N` to continue using.

If ended correctly, you should see
`Program end Sucessfully. Thanks for using our programme :)`
</details>
