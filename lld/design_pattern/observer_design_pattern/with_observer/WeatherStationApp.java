package observer_design_pattern.with_observer;

public class WeatherStationApp {
    public static void main(String[] args){

        Observable weatherStation = new WeatherStation();

        Observer displayObserver1 = new DisplayObserver();
        Observer displayObserver2 = new DisplayObserver();

        weatherStation.registerObserver(displayObserver1);
        weatherStation.registerObserver(displayObserver2);

        weatherStation.updateWeather(0, 0, 0);
    }
}
