#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int maxi = 0;

    while(n!=0){
        maxi = max(maxi,n%10);
        n = n/10;
    }

    cout<<maxi;
    return 0;
}