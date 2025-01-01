#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int n = num;
    int rev = 0;
    while (n != 0)
    {
        int r = n % 10;
        rev = (rev * 10) + r;
        n = n / 10;
    }

    if (rev == num)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not a Palindrome";
    }
    return 0;
}