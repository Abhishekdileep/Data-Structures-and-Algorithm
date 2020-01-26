#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.

\
int main()
{

    int arr[7][7];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    int i , j , sum , prev , k;
    sum=0,prev=0;
    for (i=0;i<4;i++){
        for(j=1;j<5;j++){
            k = j-1;
            while(k<=j+1){
                sum = arr[i][k]+arr[i+2][k];
                k++;
            }
            sum = arr[i+1][k];
            if(prev<sum){
                prev=sum;
            }
        }
    }

    cout << prev << "\n";


getchar();
    return 0;
}
