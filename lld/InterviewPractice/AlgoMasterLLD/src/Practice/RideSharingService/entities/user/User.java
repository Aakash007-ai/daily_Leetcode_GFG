package Practice.RideSharingService.entities.user;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import Practice.RideSharingService.entities.Trip;

public abstract class User {
    private final String id;
    private final String name;
    private final String phone;
    private final List<Trip> tripHistory;

    public User(String name, String phone){
        this.id = UUID.randomUUID().toString();
        this.name = name;
        this.phone = phone;
        this.tripHistory = new ArrayList<>();
    }

    public void addToTripHistory(Trip trip){
        tripHistory.add(trip);
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getPhone() {
        return phone;
    }
}
