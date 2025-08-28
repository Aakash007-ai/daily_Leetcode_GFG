package shreyansh_jain.observer_design_pattern.high_level.Observable;

import java.util.ArrayList;

import shrayansh_jain_ytb.observer_design_pattern.observer.NotificationAlertObserver;

public class IphoneInventoryObservable implements InventoryObservable {
    private Integer stockCount;
    private ArrayList<NotificationAlertObserver> observertList = new ArrayList<NotificationAlertObserver>();

    @Override
    public void addToObserverList(NotificationAlertObserver notificationAlertObserver) {
        this.observertList.add(notificationAlertObserver);
    }

    @Override
    public void removeObserver(NotificationAlertObserver notificationAlertObserver) {
        this.observertList.remove(notificationAlertObserver);
    }

    @Override
    public void notifyObserver() {
        for(NotificationAlertObserver observer : observertList){
            observer.update();
        }
    }

    @Override
    public void setStocksCount(Integer number) {
        this.stockCount = number;
    }

    @Override
    public Integer getStockCount() {
        if(this.stockCount > 0){
            return this.stockCount;
        }else{
            return 0;
        }
    }
    
}
