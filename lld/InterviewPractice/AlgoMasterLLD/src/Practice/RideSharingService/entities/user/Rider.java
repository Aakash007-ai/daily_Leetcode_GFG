package Practice.RideSharingService.entities.user;

import Practice.RideSharingService.entities.Trip;
import Practice.RideSharingService.observer.TripObserver;

public class Rider extends User implements TripObserver {

    public Rider(String name, String phone) {
        super(name, phone);
    }

    @Override
    public void onUpdate(Trip trip) {

    }

}
