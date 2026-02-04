package Practice.ElevatorSystem.observer;

import Practice.ElevatorSystem.entities.Elevator;

public class ElevatorDisplay implements ElevatorObserver {

    @Override
    public void update(Elevator elevator) {
        System.out.println("[Display] Elevator "+ elevator.getId() +" | Current Floor : " + elevator.getCurrentFloor() + " | Direction : " );
    }

}
