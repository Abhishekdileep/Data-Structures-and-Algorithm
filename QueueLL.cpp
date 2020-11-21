#include<iostream> 
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int n; 
    struct Node *next;
};

struct Queue_Empty : public exception {
    const char * what () const throw() {
        return "Queue Empty";
    }
};

typedef struct Node* node;

class Queue {
    private:
        node head , tail ; 
        int queue_size;
    public :
        Queue(){
           queue_size = 0;
           head = nullptr ; 
           tail = nullptr ;  
        }
        void enqueue(int value);
        int dequeue();
        int size();
        bool isEmpty();
        void print();
        int peek();
};

int Queue::size(){
    return this->queue_size;
}

bool Queue::isEmpty(){
    return this->queue_size == 0;
}

void Queue::print(){
    node temp = this->head ; 
    while( temp != this->tail ){
        cout<<temp->n<<" ";
        temp = temp->next ;
    }
    cout<<endl;
}

int Queue::peek(){
    if(queue_size !=0)
        return this->head->n;
    else{
      try
      {
          throw Queue_Empty();
      }
      catch(const Queue_Empty& e)
      {
          cerr << e.what() << '\n';
      }
      
    }
}

void Queue::enqueue(int value){
    if(queue_size > 0)
    {   node temp = (node)malloc(sizeof(struct Node));
        temp->n = value;
        tail->next = temp;
        temp->next = NULL;
        tail = tail->next;
        queue_size++;
    }else{
        head = (node)malloc(sizeof(struct Node));
        head->n = value ;
        head->next = NULL;
        queue_size++;
    }
}

int Queue::dequeue(){
    if(queue_size > 0){   
        int temp = head->n;
        node temp_node = head; 
        head = head->next;
        delete temp_node;
        queue_size--;
        return temp;
    }
    else if(queue_size == 0){
       try
      {
          throw Queue_Empty();
      }
      catch(const Queue_Empty& e)
      {
          cerr << e.what() << '\n';
      }
    }
}

int main(){
    Queue Queue_temp;
    Queue_temp.enqueue(10);
    cout<<Queue_temp.peek()<<" ";
    cout<<Queue_temp.dequeue();
    Queue_temp.dequeue();
    return 0;
}