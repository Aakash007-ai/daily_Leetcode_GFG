package Practice.RideSharingService.observer;

import Practice.RideSharingService.entities.Trip;

public interface TripObserver {
    void onUpdate(Trip trip);
}
