#include <bits/stdc++.h>
using namespace std;
void sortSquares(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];
 
    sort(arr, arr + n);
}
 
int main()
{
    int arr[] = { -6, -3, -1, 2, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    sortSquares(arr, n);
 
    cout << "\nAfter Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}