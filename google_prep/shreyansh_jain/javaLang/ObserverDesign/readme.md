in Walmart question it is asked to desgin a system where user click on notify me and he got notified via, email or phoneNo

so we have to notify user, for which he subscribe to

// so what is observer design pattern
observer design pattern , we have 2 objects observable , and observer

whenver state change of observable , it notify everyone that its state change

so we have observable interface
it has add, remove, notify

and observer interface
update

so observable add means it add observer to list whom to send or notify so it has a Observer relationship as List of Observer

register observer,

now observable concrete class is a relationship with observable

ObservableConcreteClass {
list<\Observer> obj
add(Observable obj){
ObjList.add(obj)
}

    remove(Observer obj){
        objectList.remove(obj)
    }

    notify(){
        iterate for all observer : observer.invoke()
    }

    //
    setData(int t){
        data = t;
        notify()
    }

    // used by observer to be used by when we use has a relationship
    getData(){}

}

similary observer concrete class
ObserverConcreteClass {
update(){
//so if we want to know what has change
either we pass object instance in argument or make a has a object within ObserverConcreteClass
}
}
