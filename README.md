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

## Function operations:

<details>
  <summary>1.  Show all inventory record</summary>
  
### 1. Show all inventory record
Show all inventiry record is a function that allows you to see all commodities in your inventory and their detail inforamtion. To call this function, enter `1` in the main menu and press `enter`  
You will then see the following prompt
```
*********Showing all inventory record*********

Input the number one by one in any sequence and input -1 when done or enter 11 to print All
*** E.g. Enter your choice here: 1 2 5 4 -1 ***
Here are the options: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11.ALL
Enter your choice here: 
```
These are the information that every commodity contains, you can choose specific kinds of information to show on the screen. After `Enter choice here`, you can input which kind of information to show. You can indicated the kinds of information you want by entering the corresponding number.  
You should enter the corresponding number one by one and separate it with `space` or press `enter` after each entry.  
Finally enter one more `space` and then enter `-1` to indicate all kinds of information in question is inputed. 
You can also enter `11` to show all information available.
  
***
Examples:  

<details>
  <summary>1. Show Index, Name and Stock number </summary>
  
    
Enter `1 3 5 -1` and press `enter`  
Note that `1 3 5` is the field that corresponse to Index, Name and Stock number, `-1` is to indicate everything in question is inputed. 
You should see
```
*********Enquiry result*********
Index     Name                Stock Number   
0         Banana              300            
1         Kiwi                21             
2         Papaya              90             
3         Redcurrant          1   
...
...
```

</details>

  

<details>
  <summary>2. Show Tax amount, Name and Price </summary>
  
    
Enter `10 3 4 -1` and press `enter` 
You should see  
```
*********Enquiry result*********
Tax Amount     Name                Price     
$2.5           Banana              7         
$2.5           Kiwi                15        
$2.5           Papaya              13        
$2.5           Redcurrant          18.5 
...
...
```

</details>


<details>
  <summary>3. Show all information</summary>
  
      
Enter `11` and press `enter`
You should see
```
*********Enquiry result*********
Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer   Tax Amount     
0         133            Banana              7         300            4              2                      3                         Fuji           $2.5           
1         134            Kiwi                15        21             2              2                      3                         Fuji           $2.5           
2         135            Papaya              13        90             3              2                      3                         Fuji           $2.5           
3         231            Redcurrant          18.5      1              5              2                      3                         Fuji           $2.5           
4         232            Avocado             21        69             5              2                      3                         Fuji           $2.5 
```
</details>




***
  
After a display is done, you will be transfered to the main menu again 
To enter another display, just press `1` again to initiate another display of commodity information
</details>
