#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
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
void DeleteHeap(int A[],int n,int item)
{
    int temp=A[0];
    A[0]=A[n-1];
    n--;
    heapify(A,0,n);

}
void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);

}
void generateArray(int A[],int n)
{
    int i;
    //srand();
    for(i=0;i<n;i++)
    {
        A[i]=rand()%1000;
    }
}
int deleteHeap(int A[],int &n)
{
    if(n==0)
    {
        cout<<"Heap Empty";
        return -1;
    }
   int  temp=A[0];
   A[0]=A[n-1];
   n--;
   heapify(A,0,n);
   return temp;
}
void insertHeap(int A[],int &n,int item)
{
    n++;
    int i=n;
    while(item>A[i]&&i>0)
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=item;

}
int  delete_Heap_any_position(int A[],int &n, int p)
{
    int temp=A[p];
    A[p]=A[n];
    n--;
    heapify(A,p,n);
    return temp;
}
void insert_Heap_any_position(int A[], int n,int i,int key)
{
    if(A[i]==key)
        return ;
    else if(key>A[i/2]&&i>0)
    {
        A[i]=key;
        while(key>A[i/2]&&i>0)
        {
            A[i]=A[i/2];
            i=i/2;
        }
        A[i]=key;
        cout<<"Value of  i"<<i<<endl;
    }
    else
    {
        A[i]=key;
        heapify(A,i,n);
    }
}
int kLargest(int A[],int &n,int k)
{
    int i=0,klar;
    for(int i=0;i<k;i++)
        klar=deleteHeap(A,n);
    return klar;
}
int main()
{
     int op,n,k,l,m;
    int item;
    int t1,t2;
    int pos;
    char y='Y';
    int *A=(int*)malloc(sizeof(int)*100000000);
    do
    {
     cout<<"Press 1 to Quit"<<endl;
     cout<<"Press 2 to Generate Array"<<endl;
     cout<<"Press 3 to Display the array"<<endl;
     cout<<"Press 4 to Build Heap"<<endl;
     cout<<"Press 5 to Sort using Heap Sort"<<endl;
     cout<<"Press 6 to delete from the Priority Queue"<<endl;
     cout<<"Press 7 to Insert into The Heap"<<endl;
     cout<<"Press 8 to Delete from ith Position form Heap "<<endl;
     cout<<"Press 9 to Insert from ith Position form the Heap "<<endl;
     cout<<"Press 10 to Find the kth Largest from Heap "<<endl;

     cout<<"Enter the OPTIONS :"<<endl;
     cin>>op;
     switch(op)
     {
         case 1: cout<<"Exititng ----"<<endl;
                return 0;
         case 2: cout<<"Enter the Size of the array :"<<endl;
                 cin>>n;
                 generateArray(A,n);
                break;
         case 3:  display(A,n);break;
         case 4: Build_Max_Heap(A,n);break;
         case 5:   t1=clock();
                   heap_sort(A,n);
                   t2=clock();
                   cout<<"\nTime: "<<t2-t1<<endl;
                   break;
         case 6: cout<<"Deleted Item :"<<deleteHeap(A,n)<<endl;
                 break;
         case 7: cout<<"Enter the Item For Insertion into the Heap"<<endl;
                 cin>>item;
                 insertHeap(A,n,item);
                 break;
         case 8: cout<<"Enter the Position :"<<endl;
                cin>>pos;
                cout<<"Delete elemet at  ith Position :-"<<delete_Heap_any_position(A,n,pos)<<endl;
                break;
         case 9: cout<<"Enter the item and position to insert :"<<endl;
               cin>>item>>pos;
               insert_Heap_any_position(A,n,pos,item);
               break;
         case 10: cout<<"Enter the value of k to find kth Largest "<<endl;
               cin>>k;
               cout<<"Kth Largest Element in Array : "<<kLargest(A,n,k)<<endl;
               break;


         default: cout<<"INVALID OPTIONS ENTERED";

     }
     cout<<"PRESS y to Continue";
    cin>>y;
    }
    while(y=='y'||y=='Y');
}
