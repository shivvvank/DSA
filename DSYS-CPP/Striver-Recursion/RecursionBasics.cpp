#include<bits/stdc++.h>
using namespace std;
void printNameNTimes(string name , int n)
{
    if(n==0)
    {
        cout<<endl;
        return ;
    }
    cout<<name<<" ";
    printNameNTimes(name,n-1);
}
void print1ToN(int i,int n)
{
    if(i>n)
    {
        cout<<endl;
        return;
    }
    cout<<i<<" ";
    print1ToN(i+1,n);
}
void printNTo1(int n)
{
    if(n==0)
    {
        cout<<endl;
        return ;
    }
    cout<<n<<" ";
    printNTo1(n-1);
}
void print1ToNBacktrack(int i,int n)
{
    if(i<1)
    {
        return ;
    }
    print1ToNBacktrack(i-1,n);
    cout<<i<<" ";
}
void printNto1Backtrack(int i,int n)
{
    if(i>n)
        return;
    printNto1Backtrack(i+1,n);
    cout<<i<<" ";
}
void swap(int &a,int &b)
{
    a = a+b;
    b = a-b;
    a= a-b;
}
void reverseArray(vector<int> &ar,int i)
{
    int n = ar.size();
    if(i>=n-i-1)
        return;
    swap(ar[i],ar[n-i-1]);
    reverseArray(ar,i+1);
}
bool isPalindrome(string s,int i,int n)
{
    if(i>=n-i-1)
        return true;
    if(s.at(i)!=s.at(n-i-1))
        return false;
    return isPalindrome(s,i+1,n);
}
int main()
{
    cout<<isPalindrome("shivihs",0,7)<<endl;
    return 0;
}


