package shreyansh_jain.observer_design_pattern.high_level.Observer;

import shrayansh_jain_ytb.observer_design_pattern.observer.NotificationAlertObserver;
import shreyansh_jain.observer_design_pattern.high_level.Observable.InventoryObservable;

public class MobileAlertObserver implements NotificationAlertObserver {

    String userName ;
    InventoryObservable observable;
    public void update(){
        System.out.println("MobileAlertobserver service called ");
    }
}
