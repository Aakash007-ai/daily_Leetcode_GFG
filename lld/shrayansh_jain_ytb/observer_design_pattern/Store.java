package lld.shrayansh_jain_ytb.observer_design_pattern;

import lld.shrayansh_jain_ytb.observer_design_pattern.observable.IphoneObservableImpl;
import lld.shrayansh_jain_ytb.observer_design_pattern.observable.StockObservable;
import lld.shrayansh_jain_ytb.observer_design_pattern.observer.EmailAlertObserverImpl;
import lld.shrayansh_jain_ytb.observer_design_pattern.observer.MobileAlertObserverImpl;
import lld.shrayansh_jain_ytb.observer_design_pattern.observer.NotificationAlertObserver;

public class Store {
    public static void main(String args[]){
        StockObservable iphonStockObservable = new IphoneObservableImpl();

        NotificationAlertObserver observer1 = new EmailAlertObserverImpl("xyz@gmail.com", iphonStockObservable);
        NotificationAlertObserver observer2 = new EmailAlertObserverImpl("xyz2@gmail.com", iphonStockObservable);
        NotificationAlertObserver observer3 = new MobileAlertObserverImpl("xyz_username", iphonStockObservable);

        iphonStockObservable.add(observer1);
        iphonStockObservable.add(observer2);
        iphonStockObservable.add(observer3);

        iphonStockObservable.setStocksCount(10);
    }
}
