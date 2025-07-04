Project Plan: Virtual Restaurant Simulator

Project Overview
The Virtual Restaurant Simulator is an interactive software that simulates the operations of a
restaurant. It allows users (restaurant managers) to handle various aspects of restaurant management,
including managing the menu, seating customers, processing and serving orders, tracking inventory, and 
monitoring employee performance. The simulator provides a real-world simulation experience of running a 
restaurant, complete with file management for saving and loading restaurant data such as inventory, 
menu, and customer orders.

Objectives:
Menu Management: Adding, displaying, and saving menu items.
Customer Management: Seating customers, placing orders, processing, and serving orders.
Order Management: Handling the order workflow from customer selection to fulfillment.
Inventory Management: Managing ingredients, restocking items, and checking availability.
Employee Management: Tracking and managing restaurant staff and their respective tasks.
File Operations: Saving and loading data such as menus, orders, and inventory to/from text files.

User Roles and Key Functions
1. Restaurant Manager (User)
The Restaurant Manager is the primary user interacting with the system. The manager is responsible for:

Adding menu items.
Managing customer orders.
Restocking inventory.
Tracking employee performance.
Saving and loading restaurant data.
2. Restaurant Employees
Restaurant employees include:

Chef: Responsible for preparing food orders.
Waiter: Responsible for serving food to customers.
Manager: Oversees the operations of the restaurant.
Head Chef: Manages the kitchen and oversees the chefs.

Use Case Descriptions
1. Menu Management
Objective: The manager can add new menu items, display the menu to customers, 
and save/load the menu from a file.

Add Menu Item:
Restaurant Manager
Steps:
The manager inputs the menu item’s name, price, preparation time, and ingredient.
The system adds the item to the menu.
Expected Outcome: The item is added to the menu and can be displayed or saved.

Display Menu:
 Restaurant Manager
Steps:
The manager requests to view the menu.
The system displays a list of all items on the menu with details.
Expected Outcome: The menu is displayed with all items, their prices, and preparation times.

Save Menu to File:
 Restaurant Manager
Steps:
The manager requests to save the menu to a file.
The system writes the menu data to a text file.
Expected Outcome: The menu is saved in a file (menu.txt).

2. Customer Management
Objective: Manage customer seating, order placement, and order completion.

Seat Customer:
 Restaurant Manager, Customer
Steps:
The manager inputs customer details (name, table number).
The system seats the customer at the specified table.
Expected Outcome: The customer is seated and ready to place an order.

Place Order:
 Restaurant Manager, Customer
Steps:
The customer selects items from the menu.
The system verifies the order and processes it.
Expected Outcome: The order is recorded, and ingredients are deducted from inventory.

Serve Order:
 Restaurant Manager, Waiter
Steps:
After processing the order, the waiter serves the order to the customer.
The order is saved to the order file.
Expected Outcome: The order is served, and the table is freed.

3. Order Management
Objective: Manage customer orders, from placement to fulfillment.

Process Order:
 Restaurant Manager, Chef
Steps:
After placing the order, the chef prepares the food based on available ingredients.
The system checks the inventory for the required ingredients.
Expected Outcome: The order is processed, and ingredients are deducted.

Save Order to File:
 Restaurant Manager
Steps:
After serving an order, the system saves the order details to a file.
Expected Outcome: The order is saved to orders.txt.

4. Inventory Management
Objective: Manage restaurant inventory, including restocking ingredients and checking stock levels.

Restock Ingredients:
 Restaurant Manager
Steps:
The manager inputs the ingredient and quantity to restock.
The system updates the inventory with the new quantity.
Expected Outcome: The ingredient is restocked.

Check Ingredient Availability:
 Restaurant Manager, Chef
Steps:
The chef checks whether an ingredient is available before preparing an order.
Expected Outcome: The system indicates whether the ingredient is available.

Save and Load Inventory:
 Restaurant Manager
Steps:
The manager requests to save the inventory to a file.
The manager can also load inventory data from a file.
Expected Outcome: The inventory is saved or loaded correctly.

5. Employee Management
Objective: Manage employees, assign tasks, and track performance.

Add Employees:
 Restaurant Manager
Steps:
The manager adds employees such as chefs, waiters, and managers.
The system stores employee details.
Expected Outcome: Employees are successfully added to the system.

Track Employee Performance:
 Restaurant Manager
Steps:
The manager tracks the tasks performed by each employee.
Expected Outcome: The system displays the tasks performed by each employee.

6. File Operations
Objective: Save and load restaurant data such as menu, orders, and inventory from files.

Save Menu and Inventory to File:
 Restaurant Manager
Steps:
The manager requests to save the menu and inventory to separate files.
Expected Outcome: The menu is saved in menu.txt and inventory in inventory.txt.

Load Menu and Inventory from File:
 Restaurant Manager
Steps:
The manager requests to load menu and inventory data from the saved files.
Expected Outcome: The data is loaded correctly from the files.
