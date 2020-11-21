#include<bits/stdc++.h>

using namespace std;
int gcd( int a ,  int b ){
    if(b==0){
        return a;
    }
    return gcd( b , a%b) ; 
}
int main(){
    vector<int> arr = { 10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90  };
    int size = arr.size();
    int rotate = 3 , j ; 
    int sets = gcd( size , rotate );
    for(int i=0 ; i < sets ; i++){
        int tmp = arr[i];
        for( j=i ; j < size-sets ; j=j+sets ){
            arr[j] = arr[j+sets];
        }
        arr[j]=tmp;
    }
    for(auto itr : arr){
        cout<<itr<<" ";
    }
    return 0;
}