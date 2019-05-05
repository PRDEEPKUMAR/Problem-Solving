#include<stdio.h>
int  partition(int A[],int low,int high)
{

    int i=low+1,t,j=high,pivot=A[low];
    while(1)
    {
        while(A[i]<pivot&&i<high)
            i++;
        while(A[j]>pivot&&j>low)
            j--;
        if(i<j)
        {
            t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
        else
        {
            A[low]=A[j];
            A[j]=pivot;
            return j;

        }
    }

}
int  QuickSelect(int A[],int low,int high,int k)
{
    int q=99;
    if(low<high)
    {


        q=partition(A,low,high);
       // printf("\nhi\n",A[q]);
        if(q<k)
        {
            QuickSelect(A,q+1,high,k);
        }
        else if(q>k)
        {
            QuickSelect(A,low,q-1,k);

        }
        else if(q==k)
        {

           // printf("%d %d",A[q],q);
            return q;
        }
    }
}

int main()
{
    int i,t ,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int A[n];
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    scanf("%d",&k);
    printf("%d\n",A[QuickSelect(A,0,9,k)]);
    }
    return 0;

}
