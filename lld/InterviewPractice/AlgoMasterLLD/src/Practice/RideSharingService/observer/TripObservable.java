package Practice.RideSharingService.observer;

import java.util.ArrayList;
import java.util.List;

import Practice.RideSharingService.entities.Trip;

public abstract class TripObservable {
    private List<TripObserver> observers = new ArrayList<>();

    protected void addObserver(TripObserver tripObserver){
        this.observers.add(tripObserver);
    }

    protected void removeObserver(TripObserver tripObserver){
        this.observers.remove(tripObserver);
    }

    protected void notifyObserver(){
        for(TripObserver observer : observers){
            observer.onUpdate( (Trip) this);
        }
    }
}
