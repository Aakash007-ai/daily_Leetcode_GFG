package LRUCache;

public class DoubleLinkedList<K,V> {
    private Node<K,V> head;
    private Node<K,V> tail;
    
    public DoubleLinkedList(){
        head = new Node<K,V>(null,null);
        tail = new Node<K,V>(null,null);
        head.next = tail;
        tail.prev = head;
    }

    public void deleteNode(Node<K,V> node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public void insertToTail(Node<K,V> node){
        tail.prev.next = node;
        node.prev = tail.prev;

        node.next = tail;
        tail.prev = node;
    }

    public Node<K,V> deleteHead(){
        Node<K,V> tempHead = head.next;
        this.deleteNode(tempHead);
        return tempHead;
    }

    public void moveToFront(Node<K,V> node){
        deleteNode(node);
        insertToTail(node);
    }
}
