#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ptr = { 10 , 20 , 15 , 12, 40 , 25 , 18 };
    make_heap(ptr.begin() , ptr.end() );
    for(auto itr : ptr){
        cout<<itr<<" ";
    }
    cout<<endl;
    sort_heap(ptr.begin() , ptr.end() );
    for(auto itr : ptr){
        cout<<itr<<" ";
    }
    cout<<endl;
    make_heap(ptr.begin() , ptr.end() );
    ptr.push_back(320);
    auto itrr = is_heap_until(ptr.begin() , ptr.end() );
    cout<<*itrr;
    ptr.pop_back();
    pop_heap(ptr.begin() , ptr.end());
    cout<<endl;
    itrr = is_heap_until(ptr.begin() , ptr.end() );
    cout<<*itrr;
    push_heap(ptr.begin() , ptr.end() );
    ptr.push_back(321);
    push_heap(ptr.begin() , ptr.end() );
    cout<<endl;
    for(auto itr : ptr){
        cout<<itr<<" ";
    }
    return 0;
}