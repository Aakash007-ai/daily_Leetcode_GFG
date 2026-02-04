package LRUCache;

public class Node<K,V> {
    public K key;
    public V value;
    public Node<K,V> next;
    public Node<K,V> prev;

    Node(K key, V val){
        this.key = key;
        this.value = val;
        next = null;
        prev = null;
    }

    // Node(){
    //     next = null;
    //     prev = null;
    // }
}
