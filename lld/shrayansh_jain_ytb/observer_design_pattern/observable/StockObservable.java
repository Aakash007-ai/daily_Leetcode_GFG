package lld.shrayansh_jain_ytb.observer_design_pattern.observable;

import lld.shrayansh_jain_ytb.observer_design_pattern.observer.NotificationAlertObserver;

public interface StockObservable {
    public void add(NotificationAlertObserver observer);

    public void remove(NotificationAlertObserver observer);

    public void notifySubscribers();

    public void setStocksCount(int newStockAdded);

    public int getStockCount();
}
