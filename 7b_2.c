#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int count_char(char str[])
{

    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '\n' && str[i] != ' ')
            count++;
        i++;
    }
    count++;
    return count;
}

int count_line(char str[])
{

    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            count++;
        i++;
    }
    count++;

    return count;
}

int count_word(char str[])
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n')
            count++;
        i++;
    }
    count++;

    return count;
}

int main()
{
      int fp1 ,fp2;
      char text[100];
      int word_count , line_count , char_count;
      char space[] = "\n";
     
      char file_name1[] = "abc.txt";
      char file_name2[] = "xyz.txt";
      
      mkfifo(file_name1 , 0666);
      mkfifo(file_name2 , 0666);
      
      fp1 = open(file_name1 , "r");
      
      read(fp1 , text , 100);
      
      fp2 = open(file_name2 , "w");
      
      word_count = count_word(text);
      line_count = count_line(text);
      char_count = count_char(text);
      
   //   printf("wc:%d\n",word_count);
    //  printf("lc:%d\n",line_count);
  //    printf("cc:%d\n",char_count);
      
      write(fp2 , word_count , sizeof(word_count));
      //write(fp2 , space , strlen(space));
      
      write(fp2 , word_count , sizeof(line_count));
      //write(fp2 , space , strlen(space));
      
      write(fp2 , word_count , sizeof(char_count));
     // write(fp2 , space , strlen(space));
      
      close(fp1);
      close(fp2);
      
      
}
