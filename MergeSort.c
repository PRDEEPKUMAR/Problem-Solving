/* Recurcive merge Sort */
#include<stdio.h>
#include<time.h>
void merge(int A[],int beg,int mid,int end)
{
 int *T=(int *)malloc(sizeof(int)*10000),k=0;
 int index=beg;
 int i=beg;
 int j=mid+1;
 while((i<=mid)&&(j<=end))
 {
     if(A[i]<A[j])
     {
         T[index]=A[i];
         i++;
     }
     else
     {
         T[index]=A[j];
         j++;
     }
     index++;
 }
 if(i>mid)
 {
      while(j<=end)
     {
         T[index]=A[j];
         j++;
         index++;
     }

 }
 else
 {
      while(i<=mid)
     {
         T[index]=A[i];
         i++;
         index++;
     }
 }
 for(k=beg;k<index;k++)
 {
     A[k]=T[k];
 }
}
void merge_sort(int A[],int beg,int end)
{
    int mid,i;
    if(beg<end)
    {
        mid=(beg+end)/2;
            for( i=beg;i<=end;i++)
            printf("%d ",A[i]);
            printf("\n");
        merge_sort(A,beg,end-1);
        //merge_sort(A,mid+1,end);
        merge(A,beg,end-1,end);
         for( i=beg;i<=end;i++)
            printf("%d ",A[i]);
            printf("\n");
    }

}

int main()
{
    int i,t1,t2,n;
  int A[10000];
    scanf("%d",&n);

    for(i=0;i<n;i++)
        A[i]=rand()%100;
        t1=clock();

    merge_sort(A,0,n-1);
     t2=clock();
     // for(i=0;i<n;i++)
       // printf("%d ",A[i]);
     printf("\nTime :- %d",t2-t1);
    printf("\n");
    // for(i=0;i<10;i++)
      //  printf("%d ",A[i]);
    return 0;
}
