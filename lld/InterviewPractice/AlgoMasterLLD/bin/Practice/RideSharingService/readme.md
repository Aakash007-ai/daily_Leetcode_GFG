The ride sharing service should allow passengers to request rides and drivers to accept and fulfill those ride requests.
Passengers should be able to specify their pickup location, destination, and desired ride type (e.g., regular, premium).
Drivers should be able to see available ride requests and choose to accept or decline them.
The system should match ride requests with available drivers based on proximity and other factors.
The system should calculate the fare for each ride based on distance, time, and ride type.
The system should handle payments and process transactions between passengers and drivers.
The system should provide real-time tracking of ongoing rides and notify passengers and drivers about ride status updates.
The system should handle concurrent requests and ensure data consistency.

---

entitie
User
id, name, Address

Passenger
Driver

Ride
Passenger
Driver
RideType
localtimeStarted
localTimeRideEnd
from Address, to Address
calculateFare() : int

Ride Observable
list of RideObserver
addObserver(RideObserver)
notifyObserver()

RideObserver - Passenger, Driver
onUpdate()

startegy

proximityBasedSearch()

paymentStrategy

fareCalcaulationStrategy
calculateFare

-- distance, time , rideType ( enum with )

Vehicle regular, premium

in real world we calcuate distance + get pricing + regular/premium pricicing

---

serviceLayer

addCustomer
addDriver

requestRide(Address src,Address dest, User)
-- based on strategy search drivers and notify all driver for these ride
-- then either rider will accept or reject them
-- then rider update status to move to pickup location
-- then ride got started
-- then ride completed
-- then payment
