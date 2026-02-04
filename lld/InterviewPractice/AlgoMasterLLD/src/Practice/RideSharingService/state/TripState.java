package Practice.RideSharingService.state;

import Practice.RideSharingService.entities.Trip;
import Practice.RideSharingService.entities.user.Driver;

public interface TripState {
    void request(Trip trip);
    void assign(Trip trip, Driver driver);
    void start(Trip trip);
    void end(Trip trip);
}
