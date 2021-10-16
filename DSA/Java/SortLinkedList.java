import java.util.Scanner;
class Node{
       public int data;
        public Node next;
        
        Node(int data){
            this.data = data;
            next = null;
        }
    }
class MyLinkedList{
    
    public Node head;
    
    public boolean isEmpty(){
        return (head == null);
    }
    
    public void addAtEnd(int data){
        Node ptr = head;
        if(head == null){
            Node newNode = new Node(data);
            head = newNode;
            return;
        }
        while(ptr.next != null){
            ptr = ptr.next;
        }
        Node newNode = new Node(data);
        ptr.next = newNode;
    }
    
    public void display(){
        if(head == null){
            System.out.println("The linked list is empty");
            return;
        }
        Node ptr = head;
        while(ptr != null){
            System.out.print(ptr.data+" ");
            ptr = ptr.next;
        }
        System.out.println();
    }
    
    void sort(){
        Node i,j;
        for(i = head ; i.next != null ; i=i.next){
            for(j = i.next ; j != null ; j=j.next){
                if(i.data > j.data){
                    int temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }
            }
        }
    }
}

public class SortLinkedList{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        MyLinkedList ll = new MyLinkedList();
        ll.addAtEnd(22);
        ll.addAtEnd(11);
        ll.addAtEnd(0);
        ll.addAtEnd(44);
        ll.addAtEnd(33);
        ll.sort();
        ll.display();
    }
}
