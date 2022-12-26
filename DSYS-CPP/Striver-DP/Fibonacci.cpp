#include<bits/stdc++.h>
using namespace std;
//memory optimisation
int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int last2 = 0,last1=1;
    for(int i=2;i<=n;i++)
    {
        int temp = last1+last2;
        last2 = last1;
        last1 = temp;
    }
    return last1;
}
int main()
{
    cout<<fib(3)<<endl;
    return 0;
}