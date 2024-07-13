package lld.shrayansh_jain_ytb.observer_design_pattern.observer;

import lld.shrayansh_jain_ytb.observer_design_pattern.observable.StockObservable;

public class EmailAlertObserverImpl implements NotificationAlertObserver {
    String emailId;
    StockObservable observable;

    public EmailAlertObserverImpl(String emailId, StockObservable observable){
        this.emailId=emailId;
        this.observable=observable;
    }

    @Override
    public void update(){
        sendMail(emailId,"product is in stock");
    }

    private void sendMail(String emailId, String msg){
        System.out.println("mail sent to: "+ emailId);
    }
}
