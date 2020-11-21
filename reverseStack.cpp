#include<bits/stdc++.h>

using namespace std;
template <typename T>
void insertAtBottom(stack<char> &stk , char ch){
    if(stk.empty()){
        stk.push(ch);
    }
    else{
       char temp =  stk.top();
       stk.pop();
       insertAtBottom(stk , ch);
       stk.push(temp);
    }
}

void reverseStack(stack<char> &stk){
    if( stk.empty() ){
        return ;
    }
    else{
    char ch = stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk , ch);
    }
}


int main(){
    stack<char> stk ;
    stk.push('e');
    stk.push('d');
    stk.push('c');
    stk.push('b');
    stk.push('a');
    reverseStack(stk);
    while(!stk.empty()){
        cout<<stk.top()<<endl;
        stk.pop();
    }
    cout<< "some Output Atleast ";
    return 0;
}