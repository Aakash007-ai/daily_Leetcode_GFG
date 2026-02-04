The elevator system should consist of multiple elevators serving multiple floors.
Each elevator should have a capacity limit and should not exceed it.
Users should be able to request an elevator from any floor and select a destination floor.
The elevator system should efficiently handle user requests and optimize the movement of elevators to minimize waiting time.
The system should prioritize requests based on the direction of travel and the proximity of the elevators to the requested floor.
The elevators should be able to handle multiple requests concurrently and process them in an optimal order.
The system should ensure thread safety and prevent race conditions when multiple threads interact with the elevators.

so entities
Elevator
weightCapacity // its capacity
currWeight // current weight it carrying
int floor // at which floor it is
Direction going up or down
target flooor

State Idle, Running

DisplayBoard observe elevator

Strategy to move based on direction of travel or proximity of elevator to requested floor

---

so there is Elevator service, has list of elevators, facade pattern take only parameters to target floor current floor

## so there is a speed of elevator no. of floor per second 1 floor per second, merge request
