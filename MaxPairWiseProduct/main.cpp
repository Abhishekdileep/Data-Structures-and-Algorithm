#include <iostream>
#include<vector>
using std::cout;
using std::cin;
using std::vector;
int pairProduct(vector<int> numbers){
int n = numbers.size();
int i , j,max1 ,max2;
max1 = -1;
max2=-1;
cout<<n;
for(i=0;i<n;i++){
    if ((max1 == -1) || (numbers[i]>numbers[max1])){
        cout<<"Max is  : "<<max1<<"i is : "<<i<<"\n";
        max1=i;
    }
}
for(j=0;j<n;j++){
    if((max2!=max1)&&( numbers[j]>numbers[max2]|| (max2==-1)))
{
     cout<<"Max is  : "<<max2<<"i is : "<<j<<"\n";
    max2=j;}
}
cout<<max2<<max1<<"\n";
return ((long long )(numbers[max2]*numbers[max1]));
}
int main()
{
    int n;
    long long val;
    cin>>n;
    vector<int> numbers(n);
    while(n>0){
        cin >> val;
       numbers.push_back(val);
       n--;
    }
    val = pairProduct(numbers);
cout<<val;
    return 0;
}
