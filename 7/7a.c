#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
    int fd1[2];   
    int fd2[2]; 
    
    char file_name[] = "abc.txt" ;
    char text[100];
    pid_t p;
    
    if(pipe(fd1) == -1)
    {
      fprintf(stderr , "pipe failed");
      return 1;
    }
    
    if(pipe(fd2) == -1)
    {
      fprintf(stderr , "pipe falied");
      return 1;
    }
    //printf("Enter the file name:\n");
    //scanf("%s" , file_name);
    
    printf("Enter the text to be written:\n");
    scanf("%[^\n]s" , text);
    
    p = fork();
    
    if(p<0)
    {
      fprintf(stderr, "fork failed");  
      return 1;
    }
    
    else if(p>0)
    {
      close(fd1[0]);
    
      write(fd1[1] , file_name , 100);
      close(fd1[1]);
      
      wait(NULL);
      
      close(fd2[1]);
      
      read(fd2[0] , text ,100);
      printf("The file contents are: %s" , text);
      close(fd2[0]);
    }
      
    else
    {
      close(fd1[1]);
      
      read(fd1[0] , file_name , 100);
      close(fd1[0]);
      
      close(fd2[0]);
      
      write(fd2[1] , text , 100);
      close(fd2[1]);
      
      exit(0);
    }
    
}   
    
