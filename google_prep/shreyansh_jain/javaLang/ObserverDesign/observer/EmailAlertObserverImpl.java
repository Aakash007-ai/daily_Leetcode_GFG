package javaLang.ObserverDesign.observer;

import javaLang.ObserverDesign.observable.StocksObservable;

public class EmailAlertObserverImpl implements NotificationAlertObserver {
    String userMail;
    StocksObservable observable;

    public EmailAlertObserverImpl(String emailId, StocksObservable observable){
        this.userMail = emailId;
        this.observable = observable;
    }

    public void update(){
        sendEmail(this.userMail);
    }

    private void sendEmail(String email){
        System.out.println("Sending email to user" + email);
    }
    
}
