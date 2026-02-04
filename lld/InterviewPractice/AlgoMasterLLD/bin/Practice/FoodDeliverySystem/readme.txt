The food delivery service should allow customers to browse restaurants, view menus, and place orders.
Restaurants should be able to manage their menus, prices, and availability.
Delivery agents should be able to accept and fulfill orders.
The system should handle order tracking and status updates.
The system should support multiple payment methods.
The system should handle concurrent orders and ensure data consistency.
The system should be scalable and handle a high volume of orders.
The system should provide real-time notifications to customers, restaurants, and delivery agents.


entities
Restaurants 
ordersCustomers
Menu 
DeliveryAgents


Restaurants
id,
Menu -> List of Food items
Working Hours
Capacity

Menu 
List of Food Items 

Food Item 
id, name, price , description

User
id 


Order State
created, cooking, dispatching, delivering , completed 

Observer
User will observer its order state

Restaurant Observer

Delivery Agents (observer)


Handle multiple payment mehtod ( single pay method)
-------------------------
User browse restaurants 
view menu , place order 


Order State (since it have very less methods and more states, we assume as enum)
Orders is an observable 
it will notify when its state got changed


User is a observer with notify (taking OrderState)

---------------------------------
this question have multiple things , start with basic entites 

searching strategy
Restaurants, Food Item , Users

