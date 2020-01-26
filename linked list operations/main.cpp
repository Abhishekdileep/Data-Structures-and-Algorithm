#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
    struct node
    {
      int data;
      struct node *next;
    };
typedef node* Node;
void traverse(Node temp ){
    while(temp != NULL){
        cout<<"\n-->"<<temp->data;
        temp = temp->next;

    }
}
void createNode (Node head){   //Send the node to which you want to add the head
    Node temp = (node *)malloc(sizeof(node *)*1);
    head->next = temp;
    temp->next = NULL;
}
void insertion(Node prev){
    cout<<"Enter the number you want to insert  " ;
    int data;
    cin>>data;
    createNode(prev);
    Node temp = prev->next;
    if(temp==NULL){
        cout<<"Temp value is inserted " ;
        return;
    }
    temp->data = data;

}
int main()
{
    Node head;
    head = (node *)malloc(sizeof(node *)*1);
    head->data = 10;
    head->next=NULL;
    cout<<head->data;
    cout<<"Enter the number of nodes you want to insert ";
    int num;
    cin>>num;
    Node travel;
    travel =head;
    while(num!=0){
    insertion(travel);

    travel = travel->next;
    num--;
    }
traverse(head);
    return 0;
}
