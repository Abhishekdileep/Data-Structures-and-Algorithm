#include <stdio.h>
#include <iostream>
using namespace std;
int MinRefills(int x[], int n, int l)
{
    int currentRefills, lastRefill, numfills;
    numfills = 0;
    while (currentRefills < n)
    {
        lastRefill = currentRefills;
        while ((currentRefills <= n) && (x[currentRefills + 1] - x[lastRefill] <= l))
        {
            currentRefills = currentRefills + 1;
        }
        if (currentRefills == lastRefill)
        {
            return 0;
        }
        else if (currentRefills <= n)
        {
            numfills++;
        }
    }
    return numfills;
}
int main()
{
    int n, arr[20], max, dist;
    cout << "Enter the number of refills positions :";
    cin >> n;
    cout << "Enter the max distance the user can go before refill  :";
    cin >> max;
    cout << "Enter the Total distance to be traveled : ";
    cin >> dist;
    arr[0] = 0;
    cout << "Enter thee  distances of the pump";
    for (int i = 1; i <= n; i++)
    {
        cout << "[" << i << "]";
        cin >> arr[i];
    }
    cout << endl;
    arr[n + 1] = dist;
    for (int i = 0; i <= n + 1; i++)
    {
        cout << "[" << i << "] : " << arr[i] << endl;
    }
    int numFills = MinRefills(arr, n + 2, max);
    if (numFills != 0)
    {
        cout << "The Least Number of Fills is : " << numFills;
    }
    else
    {
        std::cout << "The Journey isnt possible " << std::endl;
    }

    return 0;
}