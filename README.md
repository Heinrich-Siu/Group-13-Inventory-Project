# 1340-test-repo
# Commodity inventory system

**Problem statement:**
To control and manage ordering and storage of inventory, an inventory management system is very important. It can optimize the management process. A retail chain shore company request a commodity inventory system to manage their commodity. In this project, our aims is to build a commodity inventory system for staff to perform management in the inventory, such as manage and record commodity inventory in multiple shops, providing necessary data for procurements and delivering alerts when exceptional events happened.

**Problem setting**
The company need a inventory system to manage the inventory in different retail shop. This system should be able to store and alter the inventory record, also other additional function. The target user is the warehouse team. They will use the system to manage the inventory.

**Assumption**
1. Maximum storage size is 500 and measure in quantity.

**Function and feature**
1) Load commodity inventory record of different shop from files; 

2) search commodity according to different filters (e.g. in-stock/out-of-stock);

3) insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement,

4) delete obsolete commodity;

5) update commodity information;

6) automatic change of inventory status according to the amount of commodity that is currently available (e.g. when the amount reaches zero, the inventory status would become “out-of-stock”);

7) deliver alerts when the commodity is “out-of-stock”. Imagine putting the system into reality and please suggests a function
that is not mentioned above, to be a function of your system.

**-----------------------------------------------------------------------------------**
A readme.md detailing the problem statement (i.e., what problem to solve), problem setting
(e.g., reasonable assumptions), functionalities and features, input/output specifications,
compilation and execution instructions. Simply put, this serves like a manual to your program

Inventory management is important for renowned brands to control and manage the ordering and
storage of inventory. In order to optimize the management process, an inventory system is usually
implemented. In this idea, we aim to build a commodity inventory system that allows staff to **manage
and record commodity inventory** in **different retail shops** for monitoring inventory status, providing
necessary **data for procurements** and delivering **alerts** when exceptional events happened (e.g. some
commodity becomes **out-of-stock**). Minimally, the system shall include basic features: 

**1) search commodity according to different filters (e.g. in-stock/out-of-stock);**

**2) insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement,**

**3) delete obsolete commodity;**

**4) update commodity information;**

**5) automatic change of inventory status according to the amount of commodity that is currently available (e.g. when the amount reaches zero, the inventory status would become “out-of-stock”);**

**6) deliver alerts when the commodity is “out-of-stock”. Imagine putting the system into reality and please suggests a function
that is not mentioned above, to be a function of your system.**


Suggestions:
Propose feature to be added

A) Predict stock using different methods (3 months average, 6 month average, user specify length)
B) Reserve stock for specific stores or from other store
C) Addition to (5) out of stock alert, add feature to suggestion A to remind add stock
D) In addition to C), add contact details to the supplier
E) In addition to D), add predicted delivery time/promised delivery time
F) Filter for 1) can be in/out of stock, value per item/total value, last sale, longest in inventory time
G) Need a way to change date/time?
H) Indicate as DOA, damaged, returned units
I) Tax


Commodity Information should include:

1.Wholesale Price
2.Retail Price
3.Number of stock in different store
4.Sales record (Whole history, 3 months, 6 months, 1 year)
5.Last restock, last slaes
6.Stock distribution at different store/inventory
7.Past delivery record (time from order to in inventory)
8.Tax amount
9.Manufacturer
10.Product code

Operations:
1.Set date/time
2.Add Commodity type
3.Check stock condition
4.Stock commodity
5.Change stock status
6.Logistics operations (delivery and return)





