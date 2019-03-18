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
void Build_Max_Heap(int A[],int n)
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
/*int main()
{
    int i=0;
    int A[10]={10,50,170,15,90};
    heap_sort(A,5);

       for(i=0;i<5;i++)
    printf(" %d ",A[i]);
    return 0;
}*/
