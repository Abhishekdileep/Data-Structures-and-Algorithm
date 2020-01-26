#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int num1, num2, temp;
    printf("enter the number 1 and number 2 ");
    scanf("%d%d", &num1, &num2);
    while (num2 < num1)
    {
        if (num1 % num2 == 0)
            cout << num2 << " : is the GCD";
        temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }

    printf("Hello world");
    return 0;
}