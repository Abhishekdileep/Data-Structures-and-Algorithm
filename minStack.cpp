#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<int> val , minstk ; 
    vector<int> array = {7 , 4 , 5 , 23 ,1 ,  9 , 5};
    int temp = 9999;
    minstk.push(temp);
    for ( auto ch : array){
        val.push(ch);
        temp=minstk.top();
        if(temp > ch){
            minstk.push(ch);
        }
        else{
            minstk.push(minstk.top());
        }
    }
    while(!val.empty()){
        cout<<"val --> "<<val.top()<<" min --> "<<minstk.top()<<endl;
        val.pop();
        minstk.pop();
    }
    return 0;
} 