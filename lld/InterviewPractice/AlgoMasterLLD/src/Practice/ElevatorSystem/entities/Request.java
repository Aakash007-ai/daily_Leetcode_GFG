package Practice.ElevatorSystem.entities;

import Practice.ElevatorSystem.enums.Direction;
import Practice.ElevatorSystem.enums.RequestSource;

public class Request {
    private final int targetFloor;
    private final Direction direction;
    private final RequestSource requestSource;
    
    public Request(int targetFloor, Direction direction, RequestSource requestSource) {
        this.targetFloor = targetFloor;
        this.direction = direction;
        this.requestSource = requestSource;
    }
    
    public int getTargetFloor() {
        return targetFloor;
    }
    public Direction getDirection() {
        return direction;
    }
    public RequestSource getRequestSource() {
        return requestSource;
    }
}
