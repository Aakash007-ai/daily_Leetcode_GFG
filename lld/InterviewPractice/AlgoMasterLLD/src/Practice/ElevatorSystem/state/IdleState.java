package Practice.ElevatorSystem.state;

import Practice.ElevatorSystem.entities.Elevator;
import Practice.ElevatorSystem.entities.Request;
import Practice.ElevatorSystem.enums.Direction;

public class IdleState implements ElevatorState {
    @Override
    public void move(Elevator elevator) {
        if(!elevator.getUpRequest().isEmpty()){
            // set moving up state
            elevator.setElevatorState(new MovingUpState());
        }else if(!elevator.getDownRequest().isEmpty()){
            // set down state
        }
    }

    @Override
    public void addRequest(Elevator elevator, Request request) {
        if(request.getTargetFloor() > elevator.getCurrentFloor()){
            elevator.getUpRequest().add(request.getTargetFloor());
        }else if(request.getTargetFloor() < elevator.getCurrentFloor()){
            elevator.getDownRequest().add(request.getTargetFloor());
        }
    }

    @Override
    public Direction getDirection() {
        return Direction.IDLE;
    }

}
