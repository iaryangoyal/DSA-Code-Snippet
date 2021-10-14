/* Algorithm to implement Linked List : Zaky


1. Start
2. Create a Node and in that node create a data and and another node that should hold the
   address of the next node in the linked list.
3. create a pointer to node which will be used for traversal and we will call it as the head.
   And upon traversal getting NULL will be the termination of the linked list. 
4. Next we have the insertion in the linked list. We can insert at any position in the linked list.
5. We have two special cases of insertions which is at the end of the list or at the beginning.
6. Once the insertion process is complete we can now print all the nodes in our linked list.
7. Printing condition will be to print nodes untill we reach the NULL of the list.
8. Similarly we can delete specific nodes
9. We can delete nodes in between two nodes or we can delete at the beginning
10. We can search in the linked list and we will return bool
. Stop.
*/

/* Note: The Commented code are used for specific purpose like searching in the linked list */

#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int value){
        data= value;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int value ){
        
        Node* n = new Node(value);
        n->next = head;
        head = n;

}
void insertAtTail(Node* &head, int value){
    Node* n = new Node(value);

    if (head==NULL)
    {
        head=n;
        return;
    }
    
    Node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    
    temp->next = n;
}

void deleteAtHead(Node* &head){
    Node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(Node* &head, int value){
    
    if (head==NULL)
    {
        return;
    }
    else if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    

    Node* temp = head;
    while (temp->next->data!=value)
    {
        temp=temp->next;
    }

    Node* todelete = temp->next;
    temp->next = temp->next->next;
    
    delete todelete;
}

bool search(Node* head, int key){

        Node* temp = head;
        while (temp!=NULL)
        {
            if(temp->data ==key){
                return true;
            }
            temp=temp->next;
        }
        return false;     
}

void print(Node* head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;  
}

int main()
{

    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    cout<<"Original linked list: ";
    print(head);
    // insertAtHead(head,5);
    // print(head);
    // cout<<search(head, 8)<<endl;
    
    deletion(head,3);
    cout<<"Linked list after deletion: ";
    print(head);

    cout<<"Linked list after deleting the first node: ";
    deleteAtHead(head);
    print(head);

return 0;
}


