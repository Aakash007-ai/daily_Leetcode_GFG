package Practice.FoodDeliverySystem.observer;

import java.util.ArrayList;
import java.util.List;

import Practice.FoodDeliverySystem.entities.Order.Order;

public abstract class OrderObservable {
    private final List<OderObserver> observers = new ArrayList<>();

    public void adddObserver(OderObserver observer){
        this.observers.add(observer);
    }

    public void notifyObservers(){
        this.observers.forEach(o -> o.onUpdate((Order)this));
    } 
}
