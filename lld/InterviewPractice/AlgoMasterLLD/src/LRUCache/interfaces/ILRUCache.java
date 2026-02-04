package LRUCache.interfaces;

public interface ILRUCache<K,V> {
    public V get(K key);
    public void put(K key, V vlue);
}
