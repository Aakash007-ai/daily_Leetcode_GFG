package Practice.ElevatorSystem.state;

import Practice.ElevatorSystem.entities.Elevator;
import Practice.ElevatorSystem.entities.Request;
import Practice.ElevatorSystem.enums.Direction;
import Practice.ElevatorSystem.enums.RequestSource;

public class MovingUpState implements ElevatorState {

    @Override
    public void move(Elevator elevator) {
        if(elevator.getUpRequest().isEmpty()){
            elevator.setElevatorState(new IdleState());
            return;
        }

        Integer nextFloor = elevator.getUpRequest().first();
        elevator.setCurrentFloor(elevator.getCurrentFloor()+1);

        if(elevator.getCurrentFloor() == nextFloor){
            System.out.println("Elevator "+ elevator.getId() + " stopped at floor " + nextFloor);
            elevator.getUpRequest().pollFirst();
        }

        if(elevator.getUpRequest().isEmpty()){
            elevator.setElevatorState(new IdleState());
        }
    }

    @Override
    public void addRequest(Elevator elevator, Request request) {
        if (request.getRequestSource() == RequestSource.INTERNAL) {
            if (request.getTargetFloor() > elevator.getCurrentFloor()) {
                elevator.getUpRequest().add(request.getTargetFloor());
            } else {
                elevator.getDownRequest().add(request.getTargetFloor());
            }
            return;
        }

              // External requests
        if (request.getDirection() == Direction.UP && request.getTargetFloor() >= elevator.getCurrentFloor()) {
            elevator.getUpRequest().add(request.getTargetFloor());
        } else if (request.getDirection() == Direction.DOWN) {
            elevator.getDownRequest().add(request.getTargetFloor());
        }

    }

    @Override
    public Direction getDirection() {
     return Direction.UP; 
    }
    
}
