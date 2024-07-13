package lld.shrayansh_jain_ytb.observer_design_pattern.observer;

import lld.shrayansh_jain_ytb.observer_design_pattern.observable.StockObservable;

public class MobileAlertObserverImpl implements NotificationAlertObserver{
    String userName;
    StockObservable observable;

    public MobileAlertObserverImpl(String userName,StockObservable observable){
        this.observable = observable;
        this.userName = userName;
    }

    @Override
    public void update(){
        sendMsgMobile(userName,"product is in stock hurry up!!");
    }

    private void sendMsgMobile(String userName,String msg){
        System.out.println("msg sent to: "+ userName);
    }
}
