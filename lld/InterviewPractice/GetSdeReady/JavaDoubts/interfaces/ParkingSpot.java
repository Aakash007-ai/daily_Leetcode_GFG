package GetSdeReady.JavaDoubts.interfaces;

public abstract class ParkingSpot {
    private int floor;
    private int amount;
    
    public ParkingSpot(int floor, int amount){
        System.out.println("ParkingSpot constructor called");
        this.amount = amount;
        this.floor = floor;
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
