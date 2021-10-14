#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *temp = NULL;
/*
In this algorithm we have a pointer that runs from one to node to other in single steps and another pointer which runs in two steps. If both the pointers eventually point at the same node then a Cycle is detected otherwise not.
*/
//creating new node
Node* createNewNode(int data){
    Node *New = new Node();
    New->data = data;
    New->next = NULL;
    return New;
}
//pushing new element
void push(Node** ptr){
    (*ptr)->next = temp;
    temp = (*ptr);
}
// function to detect Cycle
void detectCycle(){
    Node *pt1 = temp;
    Node *pt2 = temp;
    while(pt1 && pt2 && pt2->next){
        pt1 = pt1->next;
        pt2 = pt2->next->next;
        if(pt1==pt2){
            cout << "Cycle Detected!";
            return;
        }
    }
    cout << "No Cycle Detected!";
    return;
}

int main(){
    Node *newNode;
    newNode = createNewNode(30);
    push(&newNode);
    newNode = createNewNode(20);
    push(&newNode);
    newNode = createNewNode(10);
    push(&newNode);
    newNode = createNewNode(50);
    push(&newNode);
    newNode = createNewNode(90);
    push(&newNode);

    //Making the first element point to the last element to make a Cycle
    temp->next->next->next->next->next = temp;  //Making this line a comment will give the output "No Cycle Detected!"

    detectCycle();

    return 0;
}