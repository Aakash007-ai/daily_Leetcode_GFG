package lld.shrayansh_jain_ytb.observer_design_pattern.observable;

import lld.shrayansh_jain_ytb.observer_design_pattern.observer.NotificationAlertObserver;

import java.util.ArrayList;
import java.util.List;


public class IphoneObservableImpl implements StockObservable{
    public List<NotificationAlertObserver> observerList = new ArrayList<>();
    public int stockCount = 0;

    @Override
    public void add(NotificationAlertObserver observer){
        observerList.add(observer);
    }
 
    @Override
    public void remove(NotificationAlertObserver observer){
        observerList.remove(observer);
    }

    @Override
    public void notifySubscribers(){
        for(NotificationAlertObserver observer:observerList){
            observer.update();
        }
    }

    public void setStocksCount(int newStocksCount){
        if(stockCount == 0){
            notifySubscribers();
        }
        stockCount += newStocksCount;
    }

    public int getStockCount(){
        return stockCount;
    }
}
