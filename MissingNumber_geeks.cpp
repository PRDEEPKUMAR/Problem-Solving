#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  int t,i;
  int tn;
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>c;
    if(c!=0)
    {
    i=((b-a)/c)+1;
    tn=a+(i-1)*c;
    else if(b==tn&&i>1)
       cout<<1<<endl;
       else
        cout<<0<<endl;
    }
    else
    {
        if(b==a)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
  }
  return 0;
}
