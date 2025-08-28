package shreyansh_jain.observer_design_pattern.simplified_way;

import java.util.ArrayList;

/**
 * in observer design patter, think of example first
 * user go to amazon item page, he click on notify me when available
 * 
 * now there is product we subscribe to 
 * 
 * at overall product will notify user , so product has a list whom to notify , 
 * who has list to notify , will notify to all users
 * 
 * We use observer design pattern ,
 * in this patter we havve 2 object one is observable, another is observer
 * 
 * whenever there is state change of observable , it update/notify all the observer
 * 
 * 
 * so observable will have add, remove , notify
 * so we define an interface observable who will ad observer to the list,
 * so observer interface will have a 
 * 
 * and observer will have have update
 */


interface observer  {
    public void display();
}

 class DisplayObserver implements observer{
    public void display(){
        System.out.println("Updated value of Observer is ");
    }
 }

 interface observable {
    public void notifyObserver();
 }

 class IphoneObservable implements observable {
    ArrayList<DisplayObserver> observerList = new ArrayList<DisplayObserver>();

    // IphoneObservable(DisplayObserver observer){
    //     this.observerList.add(observer);
    // }

    public void addToObserverList(DisplayObserver observer){
        System.out.println("IphoneObservable -> addToObserverList ");
        this.observerList.add(observer);
    }

    public void removeFromObserver(DisplayObserver observer){
        System.out.println("IphoneObservable -> removeFromObserver");
        this.observerList.remove(observer);
    }

    public void notifyObserver(){
        System.out.println("IphoneObservable");
        for(DisplayObserver obj : observerList){
            obj.display();
        }
    }

    public void setData(){
        this.notifyObserver();
    }
}

public class Main {
    public static void main(String[] args){
        IphoneObservable iphoneObservable = new IphoneObservable();
        DisplayObserver displayObserver = new DisplayObserver();

        iphoneObservable.addToObserverList(displayObserver);

        iphoneObservable.setData();

        // iphoneObservable.notifyObserver();
    }
    
}
