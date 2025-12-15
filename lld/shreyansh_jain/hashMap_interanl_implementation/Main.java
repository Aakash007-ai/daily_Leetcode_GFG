package shreyansh_jain.hashMap_interanl_implementation;

/**
 * when defining map we usually use as
 * Map<Integer,Interger> = new HashMap<>();
 * 
 * map.put(i,'w')
 * 
 * map.get(i);
 * 
 * 
 * so what is default size , load factor, collision  and its internal implementation
 * 
 * so when we see we create map , without any size, so internally by default it has size,
 * and its default is is in power of 2 to avoid collision
 * 
 * 
 * let's assume inititiaily size is 16
 * 
 * initially we get key , then using hashcode we store it at that value e.g key % 16
 * assume its value is 13
 * 
 * so 13 -> [value , nextNode] -> [value, next Node] : { 15, null}
 */

  /**
   * why maximum capacity of hashmap is in power of 2
   * 
   * maximum bytes allocated for interger is 32 bytes
   * for signed it is -2^31 to 2^31 -1
   * 
   * 
   */


class MyHashMap <K,V> {
    private static int INITIAL_SIZE = 1 << 4;
    private static int MAXIMUM_CAPACITY = 1 << 30;

    public Entry[] hashTable;

    public MyHashMap(){
        hashTable = new Entry[INITIAL_SIZE];
    }

    public MyHashMap(int capacity){
        int tableSize = tableSizeFor(capacity);
        hashTable = new Entry[tableSize];
    }

    final int tableSizeFor(int cap){
        int n = cap -1 ; // >>> unsigned right shift operation 
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return (n < 0) ? 1 : ( n>= MAXIMUM_CAPACITY ) ? MAXIMUM_CAPACITY : n + 1; 
    }

        class Entry<K,V> {
        public K key;
        public V value;
        public Entry next;

        Entry(K k , V v ){
            key = k;
            value = v;
        }
    }


    public void put(K key, V value){
        int hashcode = key.hashCode() % hashTable.length;
        Entry node = hashTable[hashcode];

        if(node == null){
            Entry newNode = new Entry(key, value);
            hashTable[hashcode] = newNode;
        } else {
            Entry prevNode = node;
            while(node!=null){
                if(node.value == key){
                    node.value = value;
                    return;
                }
                prevNode = node ;
                node = node.next;
            }
            Entry newNode = new Entry(key,value);
            prevNode.next = newNode;
        }
    }

    public V get(K key){
        int hashCode = key.hashCode() % hashTable.length;
        Entry node = hashTable[hashCode];

        while(node.key != null){
            if(node.key.equals(key)){
                return (V) node.value;
            }
        }

        return null;
    }
}

public class Main {
    public static void main(String[] args){
        MyHashMap map = new MyHashMap<Integer, String>(7);
        map.put(1, "hi");
        map.put(2, "John");


        System.out.println(map.get(2));

    }
}


/**
 * what is contract betwwen hashcode and equals
 * 
 * if we use hashCode on same value , at any n time , it will lead to  same hascode
 * also if we apply hascode for differnt object it may be possible it lead to same hascode
 * 
 * internally java use this
 * int h
 * return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16)   this help in less collision why xor, how it is working
 * 
 * 
 * load factor .75
 * whenever our hashmap got filled by 75% we do resize 
 * 
 * so assume initially size is 2^4 = 16
 * we increment size to 2^5
 * 
 * Trefying threshold = 8 ( no of nodes in consecutive linked list) to avoid o(n) TC
 * we convert it to self balanced tree
 */