#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void bubbleSort(int A[], int n);
void Bucket_Sort(int array[], int n);

int main()
{
      int a[10],b[10];
      int n1,n2,i,x,j;
      int k=0;
      
      printf("WELCOME\n");
      
      x=fork();
      
      if(x==0)
      {
                  printf("Enter total number of elements to be sorted in the child process:\n");
                   scanf("%d",&n1);
      
                    for(i=0;i<n1;i++)
                   {
                                printf("Enter the element a[%d]:\n",i);
                                scanf("%d",&a[i]);
                   }    
                        
                  printf("The Child Process ID is: %d\n",getpid());
                  bubbleSort(a,n1);
                  printf("Child is in Zombie state now!!\n");
                  return 0;
      }
      
      else
      {
                    wait(NULL);
                  
                   printf("Enter total number of elements to be sorted for parent:\n");
                   scanf("%d",&n2);
      
                    for(i=0;i<n2;i++)
                   {
                                printf("Enter the element b[%d]:\n",i);
                                scanf("%d",&b[i]);
                   } 

                  printf("The Parent Process ID is:%d\n",getpid());
                  Bucket_Sort(b,n2);
                  
                  
                        sleep(4);
                         
                         while(1)
                         {
                         
                         }
                         
       }
                  
       
}

void bubbleSort(int array[] , int n)

{

int c, d, swap;
 
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
 
  printf("Sorted list in ascending order:\n");
 
  for (c = 0; c < n; c++)
     printf("%d\n", array[c]);
}

void Bucket_Sort(int array[], int n)

{  

    int i, j,k;  

    int count[n]; 

    for (i = 0; i < n; i++)

        count[i] = 0;

 

    for (i = 0; i < n; i++)

        (count[array[i]])++;

 

    for (i = 0, j = 0; i < n; i++)  

        for(; count[i] > 0; (count[i])--)

            array[j++] = i;

      printf("The sorted array is(parent):\n");
                  
                      for (k = 0; k < n; k++)

                          printf("%d ", array[k]);   

                         printf("\n");     
                         
}   
