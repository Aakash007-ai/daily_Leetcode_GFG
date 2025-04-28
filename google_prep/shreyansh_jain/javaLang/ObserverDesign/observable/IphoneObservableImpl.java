package javaLang.ObserverDesign.observable;

import java.util.ArrayList;
import java.util.List;
import javaLang.ObserverDesign.observer.NotificationAlertObserver;

public class IphoneObservableImpl implements StocksObservable {
    List<NotificationAlertObserver> observerList = new ArrayList<>();
    int stockCount = 0;

    public void add(NotificationAlertObserver observer) {
        observerList.add(observer);
        // throw new UnsupportedOperationException("Unimplemented method 'add'");
    }


    public void remove(NotificationAlertObserver observer) {
        observerList.remove(observer);
        // throw new UnsupportedOperationException("Unimplemented method 'remove'");
    }

    public void notifySubscriber() {
        for(NotificationAlertObserver observer : observerList){
            observer.update();
        }
    }

    public void setStockCount(int newStock) {
        if(newStock == 0) notifySubscriber();
        if(stockCount != newStock){
            stockCount = newStock;
        }
    }

    public int getStockCount() {
        return stockCount;
    }
    
}
