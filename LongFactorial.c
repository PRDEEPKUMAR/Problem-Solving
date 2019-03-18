#include<stdio.h>
void shift(int A[],int n,int val)
{

    int i;
    for(i=n;i>=0;i--)
    {
        A[i+1]=A[i];
    }
    A[0]=val;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int i,j,p,k=0,n,A[2000];
    A[0]=1;
    long int s=0,c=0;
    scanf("%d",&p);
    for(i=1;i<=p;i++)
        {
            s=0;c=0;
            for(j=k;j>=0;j--)
            {
                A[j]=A[j]*i+c;
                s=A[j]%10;
                c=A[j]/10;
                A[j]=s;
                // printf("%d=c %d=i %d=s\n",c,i,s);
            }
            if(j==-1&&c!=0)
            {
                n=c;
                while(n>0)
                {
                shift(A,k,n%10);
                n=n/10;
                k++;
                }

            }
        }
        for(i=0;i<=k;i++)
        printf("%d",A[i]);
        printf("\n");
       //printf("\ncarry%d",c);

    }
  return 0;
}
