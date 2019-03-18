#include<stdlib.h>
#include<stdio.h>
void heapify(int A[],int i ,int n)
{
    int t;
    int l=2*i+1;
    int r=2*i+2;
    int lar=i;
    if(A[lar]<A[l]&&l<n)
    {
        lar=l;
    }
        if(A[lar]<A[r]&&r<n)
    {
        lar=r;
    }
    if(lar!=i)
    {
        t=A[lar];
        A[lar]=A[i];
        A[i]=t;
        heapify(A,lar,n);
    }


}
inline void Build_Max_Heap(int A[],int n)
{
     int i=0;
    for(i=n/2+1;i>=0;i--)
        heapify(A,i,n);

}

void heap_sort(int A[],int n)
{
    int size=n-1;
    int i;
    int temp;

    Build_Max_Heap(A,n);

    for(i=0;i<n;i++)
    {
      temp=A[0];
       A[0]=A[size];
       A[size]=temp;
       Build_Max_Heap(A,size);
       size--;
    }
}
void selection(int A[], int n)
{
   int i,j,pos,temp,max;
   for(i=0;i<n-1;i++)
   {
    pos=i;
    max=A[i];
       for(j=i+1;j<n;j++)
       {
           if(max>A[j])
           {
               max=A[j];
            pos=j;
           }
       }
       temp=A[pos];
       A[pos]=A[i];
       A[i]=temp;

   }
}
int main()
{
    int A[]={7,6,8,1,9,0,5,4,2,3};
    int i,j,temp;
    /*for(i=0;i<10;i++)
    {
        for(j=0;j<10-i;j++)
        {
            if(A[j]>A[j+1])
            {
              temp=A[j];
              A[j]=A[j+1];
              A[j+1]=temp;
            }
        }
    }*/
    selection(A,10);
    for(i=0;i<10;i++)
    {
        printf("%d ",A[i]);
    }

}

