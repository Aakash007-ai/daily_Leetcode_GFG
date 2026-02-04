package Practice.ElevatorSystem.state;

import Practice.ElevatorSystem.entities.Elevator;
import Practice.ElevatorSystem.entities.Request;
import Practice.ElevatorSystem.enums.Direction;
import Practice.ElevatorSystem.enums.RequestSource;


public class MovingDownState implements ElevatorState {
    @Override
    public void move(Elevator elevator) {
        if (elevator.getDownRequest().isEmpty()) {
            elevator.setElevatorState(new IdleState());
            return;
        }

        Integer nextFloor = elevator.getDownRequest().first();
        elevator.setCurrentFloor(elevator.getCurrentFloor() - 1);

        if (elevator.getCurrentFloor() == nextFloor) {
            System.out.println("Elevator " + elevator.getId() + " stopped at floor " + nextFloor);
            elevator.getDownRequest().pollFirst();
        }

        if (elevator.getDownRequest().isEmpty()) {
            elevator.setElevatorState(new IdleState());
        }
    }

    @Override
    public void addRequest(Elevator elevator, Request request) {
        // Internal requests always get added to the appropriate queue
        if (request.getRequestSource() == RequestSource.INTERNAL) {
            if (request.getTargetFloor() > elevator.getCurrentFloor()) {
                elevator.getUpRequest().add(request.getTargetFloor());
            } else {
                elevator.getDownRequest().add(request.getTargetFloor());
            }
            return;
        }

        // External requests
        if (request.getDirection() == Direction.DOWN && request.getTargetFloor() <= elevator.getCurrentFloor()) {
            elevator.getDownRequest().add(request.getTargetFloor());
        } else if (request.getDirection() == Direction.UP) {
            elevator.getUpRequest().add(request.getTargetFloor());
        }
    }

    @Override
    public Direction getDirection() { return Direction.DOWN; }
}