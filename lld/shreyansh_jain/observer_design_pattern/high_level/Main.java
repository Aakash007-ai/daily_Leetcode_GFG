package shreyansh_jain.observer_design_pattern.high_level;

import shrayansh_jain_ytb.observer_design_pattern.observer.NotificationAlertObserver;
import shreyansh_jain.observer_design_pattern.high_level.Observable.IphoneInventoryObservable;
import shreyansh_jain.observer_design_pattern.high_level.Observer.EmailAlertObserverImpl;

public class Main {
    public static void main(String[] args){
        IphoneInventoryObservable iphoneinventory = new IphoneInventoryObservable();
        NotificationAlertObserver emailAlert = new  EmailAlertObserverImpl();

        iphoneinventory.setStocksCount(0);
        iphoneinventory.addToObserverList(emailAlert);
        iphoneinventory.setStocksCount(3);

    }
    
}
