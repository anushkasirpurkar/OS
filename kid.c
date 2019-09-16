#include <stdio.h>
#include <pthread.h>

int a[10][10],b[10][10],c[10][10];
int r1,c1,r2,c2;

void getmat()
{     
      int i,j;
      
      printf("Enter the rows in first matrix:\n");
      scanf("%d",&r1);
      printf("\nEnter the columns in first matrix:\n");
      scanf("%d",&c1);
      printf("\nEnter the rows in second matrix:\n");
      scanf("%d",&r2);
      printf("\nEnter the columns in second matrix:\n");
      scanf("%d",&c2);
      
      
      for(i=0;i<r1;i++)
      {
            for(j=0;j<c1;j++)
            {
                  printf("Enter the element a[%d][%d] for matrix 1:\n",i,j);
                  scanf("%d",&a[i][j]);
            }
      }
      
      for(i=0;i<r2;i++)
      {
            for(j=0;j<c2;j++)
            {
                  printf("Enter the element b[%d][%d] for matrix 2:\n",i,j);
                  scanf("%d",&b[i][j]);
            }
      }
}

void *kidfunc(void *p)
{
      int i,j,k;
      
     // printf("Multiplication of the Matrices:\n");
 
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
                c[i][j]=0;
                for(k=0; k<r1; k++)
                    c[i][j]+=a[i][k]*b[k][j];
               // printf("%d   ",c[i][j]);
            }
           // printf("\n");
        }
}

int main ( )
{
      int i,j,k;
      
      pthread_t kid[10] ;
      int max_threads=r1*c2;
      void *p;
      int res;
      getmat();
      
      
      for(k=0;k<max_threads;k++)
      pthread_create (&kid[k], NULL, kidfunc, p) ;
      
      printf("The First Matrix Is: \n");
        //print the first matrix
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
                printf(" %d  ",a[i][j]);
            printf("\n");
        }
 
        printf("The Second Matrix Is:\n");
        // print the second matrix
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
                printf(" %d ",b[i][j]);
            printf("\n");
        }
         printf("Multiplication of the matrices is:\n");
        
      for(i=max_threads-1;i>=0;i--)
      {
            pthread_join (kid[k], p) ;
           // if(res=0)
               //   printf("Joining threads\n");
      }
      
      for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
               printf("%d   ",c[i][j]);
            }
            printf("\n");
        }
     
      printf ("Thread joined!\n") ;
      
return 0;
}
