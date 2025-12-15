package observer_design_pattern.with_observer;

import java.util.ArrayList;

public class WeatherStation implements Observable {
    private ArrayList<Observer> observers;

    private float temperature;
    private float humidity;
    private float pressure;

    public WeatherStation(){
        observers = new ArrayList<>();
    }

    public void registerObserver(Observer observer){
        observers.add(observer);
    }

    public void removeObserver(Observer obs){
        observers.remove(obs);
    }

    public void notifyObserver(){
        for(Observer observer : observers){
            observer.update(temperature, humidity, pressure);
        }
    }

    public void updateWeather(float temperature, float humidity, float pressure){
        this.humidity = humidity;
        this.temperature = temperature;
        this.pressure = pressure;
        notifyObserver();
    }

}
