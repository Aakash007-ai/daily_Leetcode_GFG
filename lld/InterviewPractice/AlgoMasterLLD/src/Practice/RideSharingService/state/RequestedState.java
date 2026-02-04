package Practice.RideSharingService.state;

import Practice.RideSharingService.entities.Trip;
import Practice.RideSharingService.entities.user.Driver;
import Practice.RideSharingService.enums.TripStatus;

public class RequestedState implements TripState{

    @Override
    public void request(Trip trip) {
         System.out.println("Trip is already in requested state.");
    }

    @Override
    public void assign(Trip trip, Driver driver) {
        trip.assignDriver(driver);
        trip.setTripStatus(TripStatus.ASSIGNED);
        trip.setTripState(new AssignedState());
    }

    @Override
    public void start(Trip trip) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'start'");
    }

    @Override
    public void end(Trip trip) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'end'");
    }
    
}
