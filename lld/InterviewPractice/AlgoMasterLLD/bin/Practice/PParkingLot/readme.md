##Problem statement
The parking lot should have multiple levels, each level with a certain number of parking spots.
The parking lot should support different types of vehicles, such as cars, motorcycles, and trucks.
Each parking spot should be able to accommodate a specific type of vehicle.
The system should assign a parking spot to a vehicle upon entry and release it when the vehicle exits.
The system should track the availability of parking spots and provide real-time information to customers.
The system should handle multiple entry and exit points and support concurrent access.

//----------------------------------------------

## Step 1 :- So first find entities

e.g a floor has a parking Lot, its displayBoard, its parking spot, list of entrance and exits
if we break down Parking spot we have mulitple type of parking spot for different kind of vehicles

Also we have multiple type of vehicle , each will acoomadate to particular parking spot
means car cannot take spot of bike, also parking spot has different price based on its type

so basic entity came to known is parking spot and vehicle
design it
so it can be based on enum , but we have multiple properities associated with parking spot so we use abstract class and create concrete method

### so we define define entities in DTO as they represent as Data

\*\*\* learnings
first define entities, then their relationship , then class based diagrams

e.g.
Entities
Parking Spot ,ParkingLot , Vehicle, Entrance, Exit, GlobalDisplay, Admin, PArkingAttendent ParkingTicket

Relationship
A Parking Lot
have multiple entrances, exit, parking spots, a global display
Admin can add/remove entracnes or exit
Parking Attendent create parking ticket
System will genereate parking ticket, update display board

Class Based relationship (actually defining methods, members, data variables)
--start with the basic

ParkingSpot
int id
int floorNo
int amount
boolean isFree
^
| is a
Compact

ParkingLot
List<EntrancePanel> entrances;
List<ExitPanel> exits;
List<ParkingSpots> parkingSPots
Displayboard displayboard

Entrance Panel
String name

ParkingTicket
int id,
ParkingSpot parkingSpot,
Vehicle vehicle,
LocalDate dateTime;

Displayboard board
list of all parking spot

// so for time constraints sometimes build simplest version first
here we converge DisplayBoard to show only free count spots of all type of spots,
since all operations of count should done at one place we have to use a singleton class and used by multiple methods

now we have ParkingSpot, Vehicle, Entrance, ParkingTicket, DisplayBoard --- all basic entities
now aggregate or composition entitie, e.g. ParkingLot
A ParkingLot
will have list of free parkingSpot, occupiedParkingSpot, displayBoard, list of entracne, exit and is singleton

---

either define interfaces of service class with actual method we will use, e.g. parkingSpot createSpot method, parkingSpotService entry,exit method, displayBoard update method

then write concrete services with nameing ends with Impl

so we don't know further what are required class and how it works
so let's work on fucntional implementation, create parkingLot , now work on make code running rather than addding features
