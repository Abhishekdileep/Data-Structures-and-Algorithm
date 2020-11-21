#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = { 10 , 20 , 30 , 70 , 5 , 7 , -1 , 2000 };
    int  k = 2 , sum = 0  , removeNumber  , i  ; 
    for( i=0 ; i < k  ;i++ )
        sum+=arr[i];
    for(   ; i < arr.size() ; i++ ){
        removeNumber = arr[i-k];
        if( ( sum - removeNumber + arr[i] ) > sum  ){
            sum = sum - removeNumber + arr[i];
            cout<<"Sum is : "<<sum<<" i is : "<<i<<endl;
        }
    }
    cout<<sum;
    return 0;
}