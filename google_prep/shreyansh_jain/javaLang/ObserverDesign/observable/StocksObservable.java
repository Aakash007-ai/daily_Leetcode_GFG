package javaLang.ObserverDesign.observable;

import javaLang.ObserverDesign.observer.NotificationAlertObserver;

public interface StocksObservable {
    public void add(NotificationAlertObserver observer);
    
    public void remove(NotificationAlertObserver observer);

    public void notifySubscriber();

    public void setStockCount(int newStock);

    public int getStockCount();
    //what is template
}
