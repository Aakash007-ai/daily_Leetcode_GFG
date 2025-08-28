package shreyansh_jain.observer_design_pattern.high_level.Observable;

import shrayansh_jain_ytb.observer_design_pattern.observer.NotificationAlertObserver;

public interface InventoryObservable {
    public void addToObserverList(NotificationAlertObserver notificationAlertObserver);

    public void removeObserver(NotificationAlertObserver notificationAlertObserver);

    public void notifyObserver();

    public void setStocksCount(Integer number);

    public Integer getStockCount();
}
