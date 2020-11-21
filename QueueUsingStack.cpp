#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class StkQueue{
    private : 
        stack<int> stk1;
    public :
        void add(int value);
        int remove();
        int removeAtBottom();
};

struct Queue_empty :public exception {

    const char * what() const throw(){
        return "Queue Empty";
    }

};

void StkQueue::add(int value){
    this->stk1.push(value);
}
int StkQueue::remove(){
    if(stk1.empty()){
        throw Queue_empty();
    }
    int temp = removeAtBottom();
    return temp;
}
int StkQueue::removeAtBottom(){
   
    if(stk1.size()==1){
        int temp = stk1.top();
        stk1.pop();
        return temp;
    }
    else {
        int temp = stk1.top();
        stk1.pop();
        int value = removeAtBottom();
        stk1.push(temp);
        return value;
    }
}

int main(){

    StkQueue temp;
    temp.add(10);
    temp.add(20);
    temp.add(30);
    temp.add(40);
    temp.add(50);
    cout << temp.remove()<<" ";
    cout << temp.remove()<<" ";
    temp.add(60);
    temp.add(70);
    temp.add(80);
    temp.add(90);
    cout << temp.remove()<<" ";
    cout << temp.remove()<<" ";
    cout << temp.remove()<<" ";
    cout << temp.remove()<<" ";
    cout << temp.remove()<<" ";
    cout << temp.remove()<<" ";
    

    return 0;
}