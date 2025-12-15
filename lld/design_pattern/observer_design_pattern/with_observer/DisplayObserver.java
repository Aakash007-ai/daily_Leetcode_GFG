package observer_design_pattern.with_observer;

public class DisplayObserver implements Observer {
    
    public void update(float temperature, float humidity, float pressure){
        System.out.println("Update values " + temperature);
    }
}
