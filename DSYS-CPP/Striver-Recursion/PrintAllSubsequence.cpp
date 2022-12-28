#include<bits/stdc++.h>
using namespace std;
void printAllSubsequence(string s,int i,string subs)
{
    if(i==s.length())
    {
        cout<<subs<<endl;
        return;
    }
    string temp = subs;
    temp+=s.at(i);
    printAllSubsequence(s,i+1,temp);
    printAllSubsequence(s,i+1,subs);
}
int main()
{
    printAllSubsequence("Shiv",0,"");
    return 0;
}