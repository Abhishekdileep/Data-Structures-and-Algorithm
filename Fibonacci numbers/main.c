#include <stdio.h>
int main()
{
    int arr[2] = {0, 1};
    int n, temp;
    printf("Enter the number of fibonnaci numbers\n");
    scanf("%d", &n);
    int i = 1;
    printf("[0]:%d\n[1]:%d\n", arr[0], arr[1]);

    for (int j = 2; j < n; j++)
    {
        temp = arr[i - 1] + arr[i];
        arr[i - 1] = arr[i];
        arr[i] = temp;
        printf("[%d]:%d\n", j, temp);
    }
    return 0;
}
