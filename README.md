# Group-13-Inventory-Project
# Commodity inventory system

**Problem statement:**
To control and manage ordering and storage of inventory, an inventory management system is very important. It can optimize the management process. A retail chain shore company request a commodity inventory system to manage their commodity. In this project, our aims is to build a commodity inventory system for staff to perform management in the inventory, such as manage and record commodity inventory in multiple shops, providing necessary data for procurements and delivering alerts when exceptional events happened.

**Problem setting**
The company need a inventory system to manage the inventory in different retail shop. This system should be able to store and alter the inventory record, also other additional function. The target user is the warehouse team. They will use the system to manage the inventory.

**Assumption**
1. Maximum storage size is 5000 and measure in quantity.

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

1. Add sales and restock record<br/>
2. Add Commodity type<br/>
3. Check stock condition<br/>
4. Stock commodity<br/>
5. Change stock status<br/>
6. Sorting inventory record by different parameter(eg. name, price, etc.)<br/>
7. Search sales and restock record(Whole history, customize number of month) and return total sales/restock in the period

