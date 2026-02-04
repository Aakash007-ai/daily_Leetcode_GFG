package Practice.ElevatorSystem.entities;

import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;
import java.util.concurrent.atomic.AtomicInteger;

import Practice.ElevatorSystem.observer.ElevatorObserver;
import Practice.ElevatorSystem.state.ElevatorState;
import Practice.ElevatorSystem.state.IdleState;

public class Elevator implements Runnable {

    private final int id;
    private AtomicInteger currentFloor;
    private ElevatorState elevatorState;
    public ElevatorState getElevatorState() {
        return elevatorState;
    }

    public void setElevatorState(ElevatorState elevatorState) {
        this.elevatorState = elevatorState;
    }

    private volatile boolean isRunning = true;
    private final TreeSet<Integer> upRequest;
    private final TreeSet<Integer> downRequest;
    private final List<ElevatorObserver> observers = new ArrayList<>();

    public Elevator(int id) {
        this.id = id;
        this.currentFloor = new AtomicInteger(1);
        this.upRequest = new TreeSet<>();
        this.downRequest = new TreeSet<>((a,b) -> b-a);
        this.elevatorState = new IdleState();
    }

    public int getId() {
        return id;
    }

    public int getCurrentFloor() {
        return currentFloor.get();
    }

    public boolean isRunning() {
        return isRunning;
    }

    public void setRunning(boolean isRunning) {
        this.isRunning = isRunning;
    }

    @Override
    public void run() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'run'");
    }

    public TreeSet<Integer> getUpRequest() {
        return upRequest;
    }

    public TreeSet<Integer> getDownRequest() {
        return downRequest;
    }

    public void setCurrentFloor(int currentFloor) {
        this.currentFloor.set(currentFloor);
        notifyObservers();
    }

    public void notifyObservers(){
        for(ElevatorObserver observer : observers){
            observer.update(this);
        }
    }


}
