#include<iostream>
using namespace std;
int PowerOfM(int m,int n)
{
    if(n==0)
        return 1;
    else
        return m*PowerOfM(m,n-1);
}
int main()
{
    cout<<PowerOfM(2,30)<<endl;
    return 0;
}