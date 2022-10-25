#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int generateLength(int n)
{
   return rand()%n;
}
   
char *randomString(int len)
{
      char *rstr = malloc((len + 1) * sizeof(char));
      int k;
      for(k = 0;k<len;k++)
      {
        rstr[k] = characters[generateLength(strlen(characters))];
      }
        rstr[len] = '\0';
        return rstr;
}



int main()
{

    char indexCollector[10];
    char arr[50][11];
      int k;
      srand(time(NULL));
      char *p;
      for(k=0;k<50;k++)
      {
              
        p = randomString(10);
        for (int j = 0; j < 10; j++) 
        {
        arr[k][j] = *p++;
        }
        arr[k][10] = '\0';
        

      }
      
      /*int u;
      for(u=0;u<50;u++)
      {
         printf("%s \n",arr[u]);
      }*/
    int fd;
    
   
    // FIFO file path
    char * myfifo = "/home/jay/Desktop/myfifo";

    
    mkfifo(myfifo, 0666);

    int arr1[50];
    char destination2[50];
    int i = 0;
    int limit = 5;
    while (i<50)
    {
        //Fifo is opened for writing only.
        fd = open(myfifo, O_WRONLY);

        
        
        //printf("%d  %d",limit,i);
        int p = i;
        while(p<limit)
        {
           
           write(fd,arr[p],10);
           
           //printf("%s \n",arr[p]);
           p++;
        }
        i+=5;
        limit+=5;
        close(fd);
        

        
        fd = open(myfifo, O_RDONLY);
        //printf("%d",fd);
        int new_j;
        //Reading the file
        read(fd,indexCollector, sizeof(indexCollector));
        
        
        
           
           printf("User2:%s \n",indexCollector);      
           
           int y;
        
        close(fd);
        
        
    }
    return 0;
}
