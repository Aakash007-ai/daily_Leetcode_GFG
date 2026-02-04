package Practice.ElevatorSystem.state;

import Practice.ElevatorSystem.entities.Elevator;
import Practice.ElevatorSystem.entities.Request;
import Practice.ElevatorSystem.enums.Direction;

public interface ElevatorState {
    void move(Elevator elevator);
    void addRequest(Elevator elevator , Request request);
    Direction getDirection();
}
