package Practice.PubSubSystem.entities;

import java.util.HashSet;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

import Practice.PubSubSystem.interfaces.Subscriber;


public class Broker {
    private final ConcurrentHashMap<String, Set<Subscriber>> topicsMap;

    public static Broker broker;

    public static final Broker getInstance(){
        if(broker == null){
            broker = new Broker();
        }
        return broker;
    };

    private Broker() {
        this.topicsMap = new ConcurrentHashMap<>();
    }

    public void addTopic(String topic){
        if(this.topicsMap.containsKey(topic)){
            System.out.println("Topic already created");
        }else{
            this.topicsMap.put(topic, new HashSet<>());
        }
    }

    public void publish(String topic, String data){
        if(this.topicsMap.containsKey(topic)){
            this.topicsMap.get(topic).forEach(s -> s.update());
        }else{
            System.out.println("Subscribe to correct topic");
        }
    }

    public void subscribe(String topic, Subscriber subscriber){
        if(this.topicsMap.containsKey(topic)){
            this.topicsMap.get(topic).add(subscriber);
        }else{
            System.out.println("Subscribe to valid topic");
        }
    }

    public void unSubscribe(String topic, Subscriber subscriber){
        if(this.topicsMap.containsKey(topic)){
            if(this.topicsMap.get(topic).contains(subscriber)) this.topicsMap.get(topic).remove(subscriber);
            else System.out.println("Subscriber is not subscribe to this topic");
        }else{
            System.out.println("Please unscribe to valid topic");
        }
    }
}
