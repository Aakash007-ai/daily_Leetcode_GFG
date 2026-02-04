package LRUCache;

import java.util.*;


public class LRUCache<K,V> {
    private Map<K, Node<K,V>> cache;
    private int capacity;
    private DoubleLinkedList<K,V> dll;
    
    public LRUCache(int capacity){
        this.capacity = capacity;
        cache = new HashMap<>();
        dll = new DoubleLinkedList<K,V>();
    }

    public synchronized V get(K key){
        if(!cache.containsKey(key)){
            return null;
        }

        Node<K,V> node = cache.get(key);
        dll.moveToFront(node);
        return node.value;
    }

    public synchronized void put(K key, V value){
        Node<K,V> temp;
        if(cache.containsKey(key)){
            temp = cache.get(key);
            temp.value = value;
            dll.moveToFront(temp);
            return;
        }

        temp = new Node<K,V>(key, value);
        cache.put(key, temp);
        dll.insertToTail(temp);

        if(cache.size() > capacity){
            Node<K,V> deleteNode = dll.deleteHead();
            cache.remove(deleteNode.key);
        }
    }
}
