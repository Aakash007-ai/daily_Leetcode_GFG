package observer_design_pattern.with_observer;

public interface Observable {
    public void registerObserver(Observer observer);
    public void removeObserver(Observer observer);
    public void notifyObserver();
    public void updateWeather(float temperature, float humidity, float pressure);
}
