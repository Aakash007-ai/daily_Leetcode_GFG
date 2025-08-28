package shreyansh_jain.observer_design_pattern.high_level.Observer;

// import shrayansh_jain_ytb.observer_design_pattern.observable.StockObservable;
import shreyansh_jain.observer_design_pattern.high_level.Observable.InventoryObservable;

public class EmailAlertObserverImpl implements NotifcationAlertObserver {
    String email;
    InventoryObservable observable;

    public EmailAlertObserverImpl(String email, InventoryObservable observable){
        this.observable = observable;
        this.email = email;
    }
    
    public void update(){
        System.out.println("Email Alert Service called ");
        sendMail();
    }

    private void sendMail(){
        System.out.println("Sending mail to user" + this.email);
    }
}
