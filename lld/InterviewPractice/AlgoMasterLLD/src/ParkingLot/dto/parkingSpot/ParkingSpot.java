package ParkingLot.dto.parkingSpot;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * So, basic entity ParkingSpot abstract class
 * it will have cost , and its id
 */

public abstract class ParkingSpot {
    private int id;
    private int amount;

    private boolean isFree;
    private int floorNum;
    private static AtomicInteger x = new AtomicInteger();

    public ParkingSpot(int amount, int floorNum) {
        this.amount = amount;
        this.floorNum = floorNum;
        this.isFree = false;
        id = x.incrementAndGet();
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }
}
