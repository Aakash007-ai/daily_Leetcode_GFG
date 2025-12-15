package dto.parkingSpot;

import java.util.concurrent.atomic.*;

public abstract class ParkingSpot {
    private static final AtomicInteger x = new AtomicInteger();
    private int id;
    private boolean isFree;
    private int floor;
    private int amount;

    public ParkingSpot(){};

    public ParkingSpot(int floor, int amount) {
        this.floor = floor;
        this.amount = amount;
        this.isFree = true;
        id = x.incrementAndGet();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public boolean isFree() {
        return isFree;
    }

    public void setFree(boolean isFree) {
        this.isFree = isFree;
    }

    public int getFloor() {
        return floor;
    }

    public void setFloor(int floor) {
        this.floor = floor;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }
}
