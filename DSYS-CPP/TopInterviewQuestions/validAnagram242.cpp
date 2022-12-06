#include<iostream>
#include<map>
using namespace std;
bool ValidAnagram(string s,string t)
{
    if(s.length()!=t.length())
        return false;
    map<char,int> m1,m2;
    map<char,int>::iterator it;
    for(int i=0;i<s.length();i++)
    {
        m1[s[i]]=0;
        m2[t[i]]=0;
    }
    for(int i=0;i<s.length();i++)
    {
        m1[s[i]]++;
        m2[t[i]]++;
    }
    for(it=m1.begin();it!=m1.end();it++)
    {
        if(m2[it->first]!=it->second)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    bool x = ValidAnagram("anagram","nagaram");
    if(x==true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
