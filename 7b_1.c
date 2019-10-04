#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
      int fp1 , fp2;
      
      char file_name1[] = "abc.txt";
      char file_name2[] = "xyz.txt";
      char text[100];
      
      mkfifo(file_name1 , 0666);
      mkfifo(file_name2 , 0666);
      
      fp1 = open(file_name1 , 0666);
      
      printf("Enter the text to be written:\n");
      scanf("%[^\n]s" , text);
      
      write( fp1 , text , sizeof(text));
      
      fp2 = open(file_name2 , "r");
      
      close(fp2);
      close(fp1);
}
