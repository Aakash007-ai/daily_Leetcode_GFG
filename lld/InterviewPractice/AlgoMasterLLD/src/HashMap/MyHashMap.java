package HashMap;

class Entry<K,V>{
    public K key;
    public V value;
    public Entry next;

    Entry(K k, V v){
        this.key = k;
        this.value = v;
    }
}
public class MyHashMap<K,V> { // K, V to generate generice hashmap
    private static final int INITIAL_SIZE = 1<<4;
    // interger 4 bytes, 
    // 32 bits -2^31 to 2^31 -1
    // so we can take max size of hash map to 2^30
    private static final int MAXIMUM_CAPACITY = 1<<30;

    public Entry[] hashTable; // entry of our table

    public MyHashMap(){
        hashTable = new Entry[INITIAL_SIZE];
    }

    public MyHashMap(int capacity){ // creating table for that size
        int tableSize = tableSizeFor(capacity);
        hashTable = new Entry[tableSize];
    }

    // we create size of next element in power of 2^i
    /**
     * 
     * @param cap
     * @return
     * 
     * >> signed operator -> right number never touch sign operator
     * >>> unisgned -> right shift touch signed operator
     * 
     * e.g if n = 7 (111) , n = 8 -> 2^3 -> 1000
     * n = cap -1 motto to get most significant bit 1 (in case of 8 we do 1 less) 
     */
    final int tableSizeFor(int cap){
        int n = cap - 1;
        n |= n>>>1;
        n |= n>>>2;
        n |= n>>>4;
        n |= n>>>8;
        n |= n>>>16;

        return (n<0) ? 1 : (n>=MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n+1;
    }

    public void put(K key, V value){
        int hashCode = key.hashCode() % hashTable.length;
        Entry node = hashTable[hashCode];

        if(node == null){
            Entry newNode = new Entry(key, value);
        }else{
            Entry prevNode = node;
            while(node != null){
                if(node.key == key){
                    node.value = value;
                    return;
                }
                prevNode = new Entry(key, value);
                node = node.next;
            }
            Entry newNode = new Entry(key, value);
            prevNode.next = newNode;
        }
    }

    public V get(K key){
        int hashNode = key.hashCode() % hashTable.length;
        Entry node = hashTable[hashNode];

        while(node!= null){
            if(node.key.equals(key)){
                return (V) node.value;
            }
            node = node.next;
        }
        return null;
    }
    
    final int hash(K key){// we use ^ xor as it give equal probability of getting equal no
        int h;
        return (key == null ) ? 0 : (h = key.hashCode()) ^(h >>>16);
    }

    /**
     * load factor .75 , if haspmap capacity fill by 75 we have to resize it e.g 16*.75 = 
     * 
     * in wrost condition we have a large linked list which will make convert this linked list to tree
     * for this we have treefy_threshold
     */

    /**
     * hash code if we put hashcode to same object give same value,
     * but mulitple objects can have same hashCode
     * 
     */

    public static void main(String[] args){

    }
}


