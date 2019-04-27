# Group-13-Inventory-Project
# Commodity inventory system

**Problem statement:**
To control and manage ordering and storage of inventory, an inventory management system is very important. It can optimize the management process. A retail chain shore company request a commodity inventory system to manage their commodity. In this project, our aims is to build a commodity inventory system for staff to perform management in the inventory, such as manage and record commodity inventory in multiple shops, providing necessary data for procurements and delivering alerts when exceptional events happened.

**Problem setting**
The company need a inventory system to manage the inventory in different retail shop. This system should be able to store and alter the inventory record, also other additional function. The target user is the warehouse team. They will use the system to manage the inventory.

**Assumption**
1. Maximum storage size is 50000 and measure in quantity.
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
<details>
  <summary>Sample Record for test case</summary>
  <details>
  <summary>sample.txt</summary>
  
  ```
  *********Enquiry result*********

  Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer             Tax Amount
  0         333            Apple A             10        40             5              2                      3                         Fuji                     $2.5
  1         334            Orange              11        60             5              2                      3                         Fuji                     $2.5
  2         335            DragonFruit         13        19             6              2                      3                         Fuji                     $2.5
  3         133            Banana              7         300            4              2                      3                         Fuji                     $2.5
  4         134            Kiwi                15        21             2              2                      3                         Fuji                     $2.5
  5         135            Papaya              13        90             3              2                      3                         Fuji                     $2.5
  6         233            Cherry              11        72             3              2                      3                         Fuji                     $2.5
  7         232            Avocado             21        69             5              2                      3                         Fuji                     $2.5
  8         231            Redcurrant          18.5      1              5              2                      3                         Fuji                     $2.5
  ```
  ***************
  Inventory Space
  ```
  Calculating...
  Inventory Space: 2692/50000
  ```
  </details>
  
  <details>
  <summary>sample2.txt</summary>
  
  ```
  *********Enquiry result*********

  Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer             Tax Amount
  0         333            Apple               10        70             5              2                      3                         Fuji                     $2.5
  1         964            Orange              20        0              5              0                      0                         China                    $3.5
  ```
  </details>
  
  </details>
  
<details>
  <summary>Testcase 1 - exceeding inventory space</summary>
  
### `input 1`
```
sample.txt 6 Y 333 2 2019-04-27 9462
```
`sample.txt`: Import sample record file to the system
`6`: updating sales and restock record  
`Y`: Say you the product code of the commodity  
`333`: The product code of the commodity add record to  
`2`: Choice to add restock record  
`2019-04-27`: Date of restock record  
`9462`: Quantity of restock  



### `output 1`
Beacuse `2692+9462*5 = 50002`, exceeding the total inventory space, therefore
```
Action will result in exceeding available inventory space 50002/50000
```
  </details>

<details>
  <summary>Testcase 2 - negative stock number</summary>
  
### `input 2`
```
sample.txt 6 Y 333 1 2019-04-27 41
```
`sample.txt`: Import sample record file to the system
`6`: updating sales and restock record  
`Y`: Say you the product code of the commodity  
`333`: The product code of the commodity add record to 
`1`: Choice to add sales record  
`2019-04-27`: Date of sales record  
`41`: Quantity of sales  

### `output 2`
Beacuse `40-41 = -1`, resulting in negative stock number, therefore
```
Error! Your action will result in negatve stock number(From 40 -> -1 )
```
  </details>
  
<details>
  <summary>Testcase 3 - zero stock warning at start</summary>

### `input 3`
```
sample2.txt
```
`sample2.txt`: Import sample record file to the system
### `output 3`
As the number of stock of Orange is 0, the system will automaticlly remind the user everytime the user start the program.
```
Out of stock warning:
Index     Product Code   Name                Number of stock
1         964            Orange              0
```
  </details>


**Function and feature**
------------------------
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
-----------------------------------------

1. Wholesale/Retail Price<br/>
2. Space used of one unit of the Commodity <br/>
3. Number of stock in different store<br/>
4. Sales and restock record (Whole history)<br/>
5. Tax amount<br/>
6. Manufacturer<br/>
7. Product code<br/>

**Operations:<br/>**
--------------------

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
    
You will recieve a out of stock warning if any commodity is out of stock    
For example, you might see
```
Out of stock warning: 
Index     Product Code   Name                Number of stock
1         134            Kiwi                0     
...
...
``` 

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
    
Note: You can enter the same attributes multiple times but no not enter more than 12 attributes at onece. Also, if your input contains `11`, it will ignore other inputs and print all attributes in order.   

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

<!---
function 2 description
--> 


<details>
  <summary>2.  Search an Commodity</summary>

It is a function that allows you to search all commodities in your inventory with different specifed or range of information and their detail inforamtion.    
The search function will narrow down the result each time you search, such that only the result in the previous search will be considered.  
The scope will be reseted if you exit the function.   
  To call this function, enter `2` in the main menu and press `enter`
  You will then see the following prompt  
  
  ```  
  *********Commodity searching*********  
  
  Find by choosing one of the constrain below. Enter -1 if you are done searching  
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number  
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount  
  Type in the constrain number:  
  ```  
  
  These are the information that every commodity contains, you can choose specific kinds of constrain to search commodity(s). After `Type in the constrain number`, you can input which kind of constrain to be use. You can indicated the constrain of information you want by entering the corresponding number, and press `Enter`.  
  For digits type, commodity can be search by `specific number` or `range of number`.  
  For string type, you can search by `substring`.    
  
  ### Showing the result
  ```
  Choose how to show your search result
  Input the number one by one in any sequence and input -1 when done or enter 11 to print All
  *** E.g. Enter here: 1 2 5 4 -1 ***
  Here are the options:
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL
  Enter here:  
  ```
  These are the information that every commodity contains, you can choose specific kinds of information to show on the screen. After `Enter here`, you can input which kind of information to show. You can indicated the kinds of information you want by entering the corresponding number.   
Note: refer to function `1. Show all commodity`   
  You should enter the corresponding number one by one and separate it with `space` or press `enter` after each entry.  
  Finally enter one more `space` and then enter `-1` to indicate all kinds of information in question is inputed. 
  You can also enter `11` to show all information available.  
    
  You can continue to search in the searching result by adding constrain or enter`-1` to exit the search function. 
  
  ***
  Examples:
  <details>
  <summary>1.Search Price which is 13</summary>
  
  Enter`4`for searching price.   
  
  ```  
  *********Commodity searching*********
  
  Find by choosing one of the constrain below. Enter -1 if you are done searching
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount
  Type in the constrain number: 4
  ```
  
  Enter`1`for searching specific price.  
  ```
  Search by 1. Specific Price  2. Range of Price
  Enter your choice here: 1
  ```
  
  Enter`13`to search commodity with price of 13.
  ```
  Your target Price is : 13
  ```
  
  Enter`11`for showing all information of result.
  
  ```
  Choose how to show your search result
  Input the number one by one in any sequence and input -1 when done or enter 11 to print All
  *** E.g. Enter here: 1 2 5 4 -1 ***
  Here are the options:
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL
  Enter here: 11

  *********Enquiry result*********
  Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer   Tax Amount
  2         335            DragonFruit         13        19             6              2                      3                         Fuji           $2.5
  5         135            Papaya              13        90             3              2                      3                         Fuji           $2.5
  ```
  
  Enter`-1`for exiting the function. 
  
  ```
  *********Commodity searching*********

  Find by choosing one of the constrain below. Enter -1 if you are done searching
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount
  Type in the constrain number: -1

  Exiting search...

  Returning to main page...
  ```
  </details>
  <details>
  <summary>2.Search Product code between 100 and 200, and Price higher than 10</summary>
  
  Enter`2` in the main menu to search `commodity` by `product code`.
  
  ```
  *********Commodity searching*********

  Find by choosing one of the constrain below. Enter -1 if you are done searching
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount
  Type in the constrain number: 2
  Search by 1. Specific Product Code  2. Range of Product Code
  Enter your choice here: 2
  ```
  
  Enter `2` to search by range of product code.
  ```
  Search by 1. Specific Product Code  2. Range of Product Code
  Enter your choice here: 2
  ```
  
  Enter`3` to search with in a range.
  ```
  You are searching by 1.Larger or equal than  2. Smaller or equal than   3.Between two numbers
  Enter your choice here:
  3
  ```
  
  Enter`100`indicating the lower boundary is 100.
  ```
  The number is larger or equal than: 100
  ```
  
  Enter`200`indicating the upper boundary is 200.
  ```
  The number is smaller or equal than: 200
  ```
  
  Enter`11`to show all information of results.
  ```
  Choose how to show your search result
  Input the number one by one in any sequence and input -1 when done or enter 11 to print All
  *** E.g. Enter here: 1 2 5 4 -1 ***
  Here are the options:
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL
  Enter here: 11

  *********Enquiry result*********
  Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer   Tax Amount
  3         133            Banana              7         300            4              2                      3                         Fuji           $2.5
  4         134            Kiwi                15        21             2              2                      3                         Fuji           $2.5
  5         135            Papaya              13        90             3              2                      3                         Fuji           $2.5
  ```
  
  Enter`4`to search within the results by price.
  ```
  *********Commodity searching*********

  Find by choosing one of the constrain below. Enter -1 if you are done searching
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount
  Type in the constrain number: 4
  ```
  
  Enter`2`to search in range.
  ```
  Search by 1. Specific Price  2. Range of Price
  Enter your choice here: 2
  ```
  
  Enter`1`to search price higher than.
  ```
  You are searching by 1.Larger or equal than  2. Smaller or equal than   3.Between two numbers
  Enter your choice here:
  1
  ```
  
  Enter`10`to indicate lower boundary is 10.
  ```
  The number is larger or equal than: 10
  ```
  
  Enter`11`to show all information of results.
  ```
  Choose how to show your search result
  Input the number one by one in any sequence and input -1 when done or enter 11 to print All
  *** E.g. Enter here: 1 2 5 4 -1 ***
  Here are the options:
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL
  Enter here: 11

  *********Enquiry result*********
  Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer   Tax Amount
  4         134            Kiwi                15        21             2              2                      3                         Fuji           $2.5
  5         135            Papaya              13        90             3              2                      3                         Fuji           $2.5
  ```
  
  Enter`-1`to exit the function.    
  You should see the following if exited correctly.    
  ```
  *********Commodity searching*********

  Find by choosing one of the constrain below. Enter -1 if you are done searching
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount
  Type in the constrain number: -1

  Exiting search...

  Returning to main page...
  ```
  </details>
  
 <!---
function 3 description
--> 
  
  
  <details>
  <summary>3.Search name with substring "an"</summary>
  
  Enter`3`to search by name.
  
  ```
  *********Commodity searching*********

  Find by choosing one of the constrain below. Enter -1 if you are done searching
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount
  Type in the constrain number: 3
  ```
  
  Enter`an`to search by substring "an".
  ```
  Enter the Nameyou wan to search. Can be a sub string of the Name
  Enter your word here:
  an
  ``` 
  
  Enter`11`to show all information of results.
  ```
  Choose how to show your search result
  Input the number one by one in any sequence and input -1 when done or enter 11 to print All
  *** E.g. Enter here: 1 2 5 4 -1 ***
  Here are the options:
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount 11.ALL
  Enter here: 11

  *********Enquiry result*********
  Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer   Tax Amount
  1         334            Orange              11        60             5              2                      3                         Fuji           $2.5
  3         133            Banana              7         300            4              2                      3                         Fuji           $2.5
  8         231            Redcurrant          18.5      1              5              2                      3                         Fuji           $2.5
  ```
  
  Enter`-1`to exit the function.
  ```
  *********Commodity searching*********

  Find by choosing one of the constrain below. Enter -1 if you are done searching
  1. Index 2.Product Code 3.Name 4.Price 5.Stock Number
  6.Stock Size 7.Number Of Sales Record 8.Number Of Restock Record 9.Manufacturer 10.Tax Amount
  Type in the constrain number: -1

  Exiting search...

  Returning to main page...
  ```
  </details>
  
  ***
  
  </details>
  
  <details>
  <summary>3. Add new commodity</summary>
  
  It is a function for you to add new type of commodity to the inventory. Before adding, please prepare information of `name`, `product code`, `price`, `size of stock`, `tax amount`, and `manufacturer` of the product.  
  To call this function, enter `3` in the main menu and press `enter`  
  You will then see the following prompt
  ### 1.Name
  Asking you to enter the `commodity name` and press `Enter`.
  ```
  Preparing to add a new commodity...

  Please enter the commodity name: Apple
  ```
  
  ### 2.Product code
  Enter an interger for the product `code`    
  You are use different number of digit(s) for the product code   
  For example `533` as below
  ```
  Please enter the product code: 533
  ```
  
  ### 3.Price
  Enter an interger value for the `price`   
  For example `3`
  ```
  Please enter the price: 3
  ```
  
  ### 4.Size of stock
  Enter an interger value for the `size of stock`.    
  For example `2` for size of stock   
  
  ```
  Please enter the size of stock: 2
  ```
  
  ### 5.Tax amount
  Enter the `commodity tax` of the commodity    
  For example `1`for tax amount.    
  Can be an interger or a number with decimals
  ```
  Please enter the tax amount: 1
  ```
  
  ### 6.Manufacturer
  Enter the name of the `manufacture` such as `Fuji`for manufacturer.
  ```
  Please enter the name of the manufacturer: Fuji
  ```
  The following prompt will be shown when the commodity has all the required data.
  ```
  Commodity added! Returning to main screen...
  ```
  </details>
 
 
<!---
function 4 description
--> 
 
  <details>
  <summary>4.  Check Inventory Space</summary>
  
  This function allow you to check the `occupied space` of the inventory. 
  To call this function, enter `4` in the main menu and press `enter`  
  You will then see the following prompt
  
  ```
  Calculating...
  Inventory Space: 2692/50000
  ```
  
  `2692` is the occupied space.  
  `50000` is the total space of the inventory
</details>
  
  
  <!---
function 5 description
--> 
  
  <details>
  <summary>5.  Update commodity</summary>
  
  You can use this function to update `name`, `product code`, `price`, `size of stock`, `tax amount`, and `manufacturer` of the product by `product code`.  
  To call this function, enter `5` in the main menu and press `enter`  
  You will then see the following prompt
  ```
  Preparing to modify commodity...
  Do you know the product code of the commodity that you want to update?(Y/N) 
  ```
Input `Y` and press `enter` if you **do** know the product code   
Input `N` and press `enter` if you **do not** know the product code 

1. If you press `N`, you will see the prompt below    
```
~~Please first search the commodity and change the record by product code~~

*********Commodity searching*********

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: 
```
This is the search function as descibed in `2.  Search an Commodity`  
Search the commodity under interest and input `11` to end search


2. After searching or if you pressed `Y` , you will be asked to enter the `product code` you want to update   
  
  ```
  ***************************************************************************************
  Please enter the productCode of the commodity that you want to update:
  ```
  Enter the`product code`, for example `333`.
  You will see information of it for your reference. From the menu, enter your choice after `Enter your choice here:` with the corresponding number to the options shown.   
  
  ```
  Index     Product Code   Name                Price     Stock Number   Stock Size     Number of Sales Record Number of Restock Record  Manufacturer   Tax Amount
  0         333            Apple A             10        40             5              2                      3                         Fuji           $2.5    

What attribute of the commodity do you want to change/update?
1. Product Code
2. Product Name
3. Price
4. Size of stock
5. Tax amount
6. Name of manufacturer
7. Quit
Enter your choice here: 
  ```
  For example, enter`1`to update the product code.  
  it will display the current product code, and prompt you to enter the new one.
  ```
  Change from 333 to:
  ```
  if you enter`456`, you will see the following prompt.
  ```
  The product code is now: 456
  Commodity updated
  ```
  Such that the `product code` is now changed from `333` to `456`
  
  You can continue updating the commodity's imformation by enter number between `1-6` or quit the function by `7`.  
  If you enter `7`, you will see the following prompt meaning you have successfully quit the function.
  ```
  Exiting commodity update...
  ```
You will then be transfer back to the main menu.  
  </details>
  
   
<!---
function 6 description
--> 
 
  
<details>
<summary>6.  Stock sales/restock </summary>
This function allows you to make sales or restock record to change the number of stock      
You will be prompted by the following       
    
```  
You are updating sales and restock record

Do you know the product code of the commodity that you want to update?(Y/N) 
```
Input `Y` and press `enter` if you **do** know the product code   
Input `N` and press `enter` if you **do not** know the product code   
  
1. If you press `N`, you will see the prompt below    
```
~~Please first search the commodity and change the record by product code~~

*********Commodity searching*********

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: 
```
This is the search function as descibed in `2.  Search an Commodity`  
Search the commodity under interest and input `11` to end search 

  
If you pressed `Y` or finished searching, you will then be asked to enter the `product code` in question  
`Please enter the product code of the commodity that you want to add record to: `    
Enter the `product code` and press `enter`  
    
You will then have three choice as below
```
Choice 1.Adding Sales record
       2.Adding Restock record
       3.Quit
Choice: 
```
Enter the number corresponding the function you want to use and press `enter`   
        
       
1. Adding Sales record
You will be asked to enter the date of the sales in `YYYY-MM-DD` format and the quantity of the sales made      
Below will be an example of the operation, `Record added!` indicate the record is succesfuly added     
```
You are adding record of sales of Redcurrant (231)
Sales time (YYYY-MM-DD): 2019-11-11
Quantity: 1
Record added!
```
If the sales is lager than the number of stock, an error message would show up      
`Error! Your action will result in negatve stock number(From <original number> -> <expected final number> )`    
    
2. Adding Restock record
You will be asked to enter the date of the restock in `YYYY-MM-DD` format and the quantity of the restock made 
Below will be an example of the operation, `Record added!` indicate the record is succesfuly added     
```
You are adding record of restock of Redcurrant (231)
Delivery time (YYYY-MM-DD): 2019-12-12
Quantity: 100
Record added!
```
If the restock quantity is lager than the available inventory space, an error message would show up    
Action will result in exceeding available inventory space <value that is exceeded>/<total space>        
        
3. Quit
This will transfer you back to the main menu
  
  
  
</details>
  
   
<!---
function 7 description
--> 
 
  
<details>
<summary>7.  Sort working record </summary>
Sort record is a function that changes the order of how the data is stored in the working programme   
You should see the prompt below as you enter `7` in the main menu   
  
```
Sort by: 1.  Product Code
         2.  Name
         3.  Price
         4.  Number of stock
         5.  Size of stock
         6.  Numeber of Sales Record
         7.  Numeber of Restock Record
         8.  Tax Amount
         9.  Manufacturer
         10. Quit
```

There will be two types of sort, one is by `value` and one is by `lexicographical order`    
Option `1`,`3`,`4`,`5`,`6`,`7` and `8` will be sort by their `value`    
Option `2` and `9` will be sorted by thier `lexicographical order`
* [Lexicographical order](https://en.wikipedia.org/wiki/Lexicographical_order)   
    
You should see when for all types of sorting
```
In: 1. Ascending Order
    2. Descending Order
    3. Abort and Quit
```
The programme will show to indicate the wroking commodity list is sorted
`Sorting completed`     
`Returning to main page...`  
    
Note: You can see the result by choosing to `1.  Show all inventory record` in the main menu

</details>
  
   
<!---
function 8 description
--> 
 
  <details>
  <summary>8.  Check Sales History </summary>
  
  This function is used to check the sales record of a commodity    
  You will need to enter the `Product code` to indicate which commodity is under interest   
  You should see such prompt when this function is called   
```
Preparing to show sales record...

Do you know the product code of the commodity that you want to check?(Y/N) 
```
Input `Y` and press `enter` if you **do** know the product code   
Input `N` and press `enter` if you **do not** know the product code   
  
1. If you press `N`, you will see the prompt below    
```
~~Please first search the commodity and check the record by productCode~~

*********Commodity searching*********

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: 
```
This is the search function as descibed in `2.  Search an Commodity`  
Search the commodity under interest and input `11` to end search 

  
If you pressed `Y` or finished searching, you will then be asked to enter the `product code` in question  
`Please enter the product code of the commodity record that you want to check: `    
Enter the `product code` and press `enter`  
  
Then, you will be given these choices below:  
```
Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: 
```
1. n Months 
  You will be asked to input the the value of n and the time at the end of the `n months`   
  An example is as below
```
Enter the value of n: 12
From when (YYYY-MM, e.g. 2019-12) to 12 months before: 2019-12
Total 2 record in the last 12 months found.
```
Then you should see the result
```
Date (YYYY-MM-DD)   Quantity
2019-4-7            2     
2019-4-6            3 
```
  
2. Whole history
The programme will return all sales history of this commodity as below
```
Date (YYYY-MM-DD)   Quantity
2019-4-7            2     
2019-4-6            3 
...
...
```
  
3. Quit
This will bring you back to the main menu   
  

  </details>
   
   
<!---
function 9 description
--> 
 
  
  <details>
  <summary>9.  Check Restock History </summary>
  
  Note: This function is similar to function 8
  This function is used to check the restock record of a commodity    
  You will need to enter the `Product code` to indicate which commodity is under interest   
  You should see such prompt when this function is called   
```
Preparing to show restock record...

Do you know the product code of the commodity that you want to check?(Y/N) 
```
Input `Y` and press `enter` if you **do** know the product code   
Input `N` and press `enter` if you **do not** know the product code   
  
1. If you press `N`, you will see the prompt below    
```
~~Please first search the commodity and check the record by productCode~~

*********Commodity searching*********

Find by choosing one of the constrain below: 
1. Index            2.Product Code           3.Name
4.Price             5.Stock Number           6.Stock Size
7.Number Of Sales Record                     8.Number Of Restock Record
9.Manufacturer      10.Tax Amount            11:End search
Type in the constrain number: 
```
This is the search function as descibed in `2.  Search an Commodity`  
Search the commodity under interest and input `11` to end search 

  
If you pressed `Y` or finished searching, you will then be asked to enter the `product code` in question  
`Please enter the product code of the commodity record that you want to check: `    
Enter the `product code` and press `enter`  
  
Then, you will be given these choices below:  
```
Check by:
          1. n Months
          2. Whole history
          3. Quit
Choice: 
```
1. n Months 
  You will be asked to input the the value of n and the time at the end of the `n months`   
  An example is as below
```
Enter the value of n: 12
From when (YYYY-MM, e.g. 2019-12) to 12 months before: 2019-12
Total 2 record in the last 12 months found.
```
Then you should see the result that shows all the restock history in the period of n months before the date inputed and the inputed date  
```
Date (YYYY-MM-DD)   Quantity
2019-4-7            2     
2019-4-6            3 
```
  
2. Whole history
The programme will return all restock history of this commodity as below
```
Date (YYYY-MM-DD)   Quantity
2019-4-7            2     
2019-4-6            3 
...
...
```
  
3. Quit
This will bring you back to the main menu   
  
  
  
  </details>
   
<!---
function 10 description
--> 
 
  <details>
  <summary>10. Check inventory status </summary>
  
  There are 3 main functions that can be achieve by `check inventory status`    
  These are mainly to recieve predictions   
  To enter this function, inout `10` at the main menu and press `enter` 
  You should see the 3 main functions listed out below  
  ```
  Showing inventory status:
1. Show stock status
2. Show sales prediciton
3. Delete obsoleted commodity
4. Quit
Enter your choice here:
``` 
Enter the number that corresponse to the choice and press `enter`
Detail functionality and use is as below    
<details>
<summary>1. Show stock status </summary> 
    
You will be ask to enter `current date` and `number of months` used in the prediction
The prediction is based on `n-month average`
Such that predicted sales will be the sales average of the last `n` month  
Example input will be as below  
```
Enter current date in (YYYY-MM, e.g. 2019-12) format: 2019-12
Choose the number of month(s) for prediction: 12 
```
This function will show
    - [ ] Stock out alert (if any)
    - [ ] Predicted out of stock warning: 
* For stock out alert it will show the `Index`, `Product Code`, `Name` and `Number of Stock` which will be `0`  
For example:    
```
Out of stock warning: 
Index     Product Code   Name                Number of stock
1         134            Kiwi                0           
...
...
```
* For Predicted out of stock warning: 
This will show `Index`,`Product Code`,`Name`,`Current stock`,`Predicted sales in n month` and `Difference` 
`Predicted sales` will be calculated by `n-month` average    
`Difference` will be calulated by `Current stock` - `Predicted sales`   
```
Predicted out of stock warning: 
Index     Product Code   Name                Current stock       Predicted sales in 12 month   Difference          
1         134            Kiwi                0                   0.416667                      -0.416667  
...
...
```
User can see if they have enough stock to handle last n-month average sales 
</details>  
  
  
  
<details>
<summary>2. Show sales prediciton </summary> 
  
    
This has a similar function to `Show stock status`, however it can show the predicted sales of all commodities    
You will be asked to enter length of the prediction and the date to predict from 
Example input will be as below  
```
Choose the average of sales in the last x months: 6
From when (YYYY-MM, e.g. 2019-12) to 6 months before: 2019-12
```
    
Output will be the `Index`, `Product Code`, `Name`, `Current Stock` and `Predicted sales in n month`
You should see similar output as below   
```
From when (YYYY-MM, e.g. 2019-12) to 6 months before: 2019-12
Index     Product Code   Name                Current stock       Predicted sales in 6 month
0         133            Banana              300                 0.833333            
1         134            Kiwi                0                   0.833333            
2         135            Papaya              90                  0.833333            
...
...
```

</details>

<details>
<summary>3. Delete obsoleted commodity </summary> 

This function helps you delete commodity with no sales record in the last n monts   
You should see a prmompt as below, enter an interger for n  
Enter the date following the `YYYY-MM` format
Example is as follows
```
Searching for outdated commodity
Delete commodity without sales in the last n months
Enter value of n: 3
From when (YYYY-MM, e.g. 2019-12) to 3 months before: 2019-12
 ```
1. If there are commodities that doesn't have sales record in the last n month, you will be asked   
```
Are you sure to delete <commodity name>?
Enter Yes or No by (Y/N): 
```
* If you want to delete such commodity, press `Y` and press `enter`
You will be shown `Selected commodity deleted!` if successfully deleted 
* If you want to leave it in place, press `N` and press `enter`. The delete process will be skipped
Finally if you have deleted any items, you will be shown `Outdated commodity deleted`   
If you didn't delete any commodity, you will be shown `No commodity deleted`

2. If there are no commodity that don't have sales in the last n months     
    You will be shown `No commodity to be deleted!` 

</details> 
  
  
  
After outputing the result, you will be transfer back to the Check inventory status menu
  </details>
 
 
<!---
function 11 description
--> 
 
  <details>
  <summary>11. Save working record to file </summary>
    
  This function allows you to save a file to the file you had loaded from or create a new file to save to.  
  **You are recommended to use `.txt` as the file extension**
  
  To enter this function, enter `11` in the main menu and press `enter` .   
  Then you should see the following prompt:     
  ```
  `Do you want to overwrite record to current file instead of creating a new file?   Enter Y/N` 
  ```
  1. To save to the file you have loaded from when you were asked to 
  `Please input the file name of the record: ` at the start of using this function  
  Input `Y` and press `enter`   
    
  2. If you want to save to another file or create a file to save to   
  Input `N` and press `enter`   
  You will then be prompted by `Enter the file name you want to create: `    
  input the file name that you want to write the file to and press `enter`  
    
  After the procedures above, you will then be prompted by
  ```
  All records saved!
  ```
  This indicates that your records are saved then you will be transfer back to the main menu.       
    
  Note: If the file name you used is unable to be opened/modified, it will show `Unable to open <file name>` to indicated the file can't be used. You will then be guided back to the main menu.   
  

  </details>

</details>









