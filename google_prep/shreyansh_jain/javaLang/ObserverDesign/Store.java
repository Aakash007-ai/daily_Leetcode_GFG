package javaLang.ObserverDesign;

import javaLang.ObserverDesign.observable.IphoneObservableImpl;
import javaLang.ObserverDesign.observable.StocksObservable;
import javaLang.ObserverDesign.observer.EmailAlertObserverImpl;
import javaLang.ObserverDesign.observer.NotificationAlertObserver;

public class Store {
    public static void main(String args[]){
        StocksObservable iphonObservable = new IphoneObservableImpl();

        NotificationAlertObserver observer1 = new EmailAlertObserverImpl("abc.@abc.com", iphonObservable);
        
        iphonObservable.add(observer1);
        iphonObservable.setStockCount(1);
    }
}
