#include<bits/stdc++.h>

using namespace std;

vector<int> bruteForce(vector<int> & Arr){
    vector<int> res(Arr.size());
    int temp = 0; 
    res[0] = 1;
    for(int i = 0 ; i< Arr.size() ; i++){
        res[i]=1;
        for( int j = i-1 ; ((j>=0) && ( Arr[i] >= Arr[j])) ; j--){
            res[i]++;
        }
    }
    return res;
}

vector<int> refined(vector<int> & Arr){
    vector<int> res(Arr.size());
    stack<int> stk;
    res[0] = 1;
    stk.push(0);
    for(int  i = 1  ; i < Arr.size() ; i++){
        while( !stk.empty() && ( Arr[stk.top()] <= Arr[i] ) ){
            stk.pop();
        }
        res[i]=stk.empty() ?(i+1) : i - stk.top();
        stk.push(i);
    }
    return res;

}
int main() {
    vector<int> Arr = { 100 , 80 , 60 , 70 , 60 , 75 , 85 };
    vector<int> res = refined(Arr); 
    for(auto i = res.begin() ; i!=res.end()  ; i++){
        cout<<*i<< " ";   
    }
    return 0;
}