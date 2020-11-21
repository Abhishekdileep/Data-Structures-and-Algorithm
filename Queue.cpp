#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Queue{
    private : 
        int capacity = 100;
        int queue_size = 0;
        int * data;
        int front;
        int back;
    public :
    Queue(){
        capacity=100;
        queue_size=0;
        data = new int[100];
        back=0;
        front=-1;
    }
    virtual bool isEmpty();
    virtual int size();
    virtual bool add(int val);
    virtual int remove();
};

bool Queue::isEmpty(){
    return this->queue_size == 0;
}
int Queue::size(){
    return this->queue_size ;
}
bool Queue::add(int value){
    Queue();
    if(this->capacity >= queue_size ){
        data[back]=value;
        queue_size++;
        back=(++back)%(capacity-1);
    }
    else{
        cout<<"No Space , You No Park here , go go ";
    }
}
int Queue::remove(){
        int temp ;
    if(queue_size > 0){
        front = (++front)%(capacity-1);
        temp = data[front];
        queue_size--;
    }
    return temp;
}

int main(){

    Queue q;
    q.add(10);
    q.add(20);
    q.add(30);

    cout<<q.remove();

    return 0;
}