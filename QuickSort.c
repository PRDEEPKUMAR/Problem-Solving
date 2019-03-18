#include<stdlib.h>
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
void QuickSort(int A[],int low ,int high)
{
    int q;
    if(low<high)
    {
        q=partition(A,low,high);
        QuickSort(A,low,q-1);
        QuickSort(A,q+1,high);
    }

}
int main()
{
    int i,*A,n=10000;
     A=(int *)malloc(sizeof(int)*n);
     scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
     int tt=clock();
    QuickSort(A,0,n/2-1);

    for(i=0;i<n;i++)
        printf("%d ",A[i]);

    return 0;

}
