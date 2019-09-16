#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

void bubbleSort(int a[],int n);

int main()
{
      int n,i,pid;
      int a[10];
      char *s[20],str[20];
      
      printf("Enter the size of array\n");
      scanf("%d",&n);
      
      for(i=0;i<n;i++)
      {
            printf("Enter the %d element\n",i+1);
            scanf("%d",&a[i]);
      }   
      
            printf("Parent process starting with ID: %d\n",getpid());
            bubbleSort(a,n);
            printf("\n");
           
          //  printf("Parent process has completed sorting\n");
            
            printf("Fork begining\n");
            pid=fork();

           
            
            if(pid==0)
            {
                  printf("In child process with ID:%d\n",getpid());
               
                  printf("Sorted elements: ");
                  
                  for(i=0;i<n;i++)
                  {
                        printf(" %d\t",a[i]);
                        sprintf(str,"%d",a[i]);
                        s[i]=malloc(sizeof(str));
                        strcpy(s[i],str);
                  }
                  
                  s[i]=NULL;
                  printf("Executing execve command\n");
                  execve("./2b2",s,NULL);
                  printf("Execve execution is complete\n");
                  printf("Child process complete\n");
            }
            
            else
            {
            
                  printf("The program is in parent process......Waiting....\n");
                  wait(NULL);
                  printf("Completing and exiting parent process\n");
                  
            }
      
       return 0;
}

void bubbleSort(int a[],int n)
{
      int i,j,temp;
      
      for(i=n-2;i>=0;i--)
      {
           for(j=0;j<=i;j++)
           {
                 if(a[j]>a[j+1]){
           temp=a[j];
           a [j]=a[j+1];
           a[j+1]=temp;
        }
      }
   }  
}
      
      
