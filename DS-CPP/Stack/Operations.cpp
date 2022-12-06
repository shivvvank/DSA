#include<bits/stdc++.h>
using namespace std;
    int calPoints(string operations[]) {
        int n = 5;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            string s = operations[i];
            if(s=="C")
                st.pop();
            else if(s=="D")
            {
                int num=st.top();
                st.push(num*2);
            }
            else if(s=="+")
            {
                int num1,num2;
                num1=st.top();
                st.pop();
                num2=st.top();
                st.push(num1);
                st.push(num1+num2);
            }
            else
            {
                st.push(stoi(s));
            }
        }
        int ans=0;
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
int main()
{
    string v[]={"5","2","C","D","+"};
    cout<<calPoints(v)<<endl;
    return 0;
}