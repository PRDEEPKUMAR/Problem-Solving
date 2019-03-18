#include<stdio.h>
#include<time.h>

void generateArray(int A[], int n)
{
   int i;
  srand(time(0));

   for(i=0;i<n;i++)
   {
      A[i]=rand()%1000;
   }


}
  void display(int A[],int n)
{
  int i;

   for(i=0;i<n;i++)
   {
      printf("%d ",A[i]);
   }


}
void sortAcending(int A[],int n)
{
   int i,j,temp,count=0;
   for(j=1;j<n;j++)
   {
       count=0;
     i=j-1;
     temp=A[j];
     while(A[i]>temp&&i>=0)
     {
           A[i+1]=A[i];
           count++;
           i--;
     }
     A[i+1]=temp;
     printf("%d",count);
     printf("\n");

   }


}
  void sortDecending(int A[], int n)
{

   int i,j,temp;
   for(j=1;j<n;j++)
   {
     i=j-1;
     temp=A[j];
     while(A[i]<temp&&i>=0)
     {
           A[i+1]=A[i];
           i--;
     }
     A[i+1]=temp;
   }

}

int  bestCase(int t1,int t2)
{
  return t2-t1;

}
 void worseCaseTimeComplexity(int A[], int n)
{

}
void averageCaseTimeComplexity()
{

}
void allTimeComplexity()
{

}
int main()
{
  int *A=(int*)malloc(sizeof(int)*10000000);
  int i;
  int n;
  int t1,t2;

     printf("-------INSERTION SORT MENU----------");
     printf("\nPRESS 0 to Quit");
     printf("\nPRESS 1 to Generate Array");
     printf("\nPRESS 2 to Display ");
     printf("\nPRESS 3 to sort in acending Order");
     printf("\nPRESS 4 to sort in decending Order");
     printf("\nPRESS 5 to Time  BEST CASE");
     printf("\nPRESS 6 to Time  AVERAGE CASE");
     printf("\nPRESS 7 to Time  WORSE CASE");
     printf("\nPRESS 8 to Generate Table ");
     printf("\nEnter Your Choice ");
     scanf("%d",&i);
     do
     {
        switch(i)
        {
	     case 0:  printf("Exiting the program ");
	              return 0;
             case 1:  printf(" Enter the size of the Array ");
                      scanf("%d",&n);
                      generateArray(A,n);
                      //display(A,n);
  		      break;
             case 2:  display(A,n);

             case 3:  t1=clock();
                      sortAcending(A,n);
                      t2=clock();
                       break;
             case 4:  sortDecending(A,n);
                       break;
              case 5: printf("TIME OF INSERTION SORT :- %d",bestCase(t1,t2));
                       break;


     }
     printf("\n------------Enter Your Choice :-");
     scanf("%d",&i);



  }
  while(i!=0);


     return 0;
}
