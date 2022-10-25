#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
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
struct wrapper {
    long value;
    char str[10];
};

int main() {
    int i, j;

    char arr[100][11];
      int k;
      srand(time(NULL));
      char *p;
      for(k=0;k<50;k++)
      {
              
        p = randomString(5);
        for (int j = 0; j < 10; j++) 
        {
        arr[k][j] = *p++;
        }
        arr[k][10] = '\0';
        

      }
      

    int key1 = 1111,key2 = 2222;
    int messageId1 = msgget(key1, 0666 | IPC_CREAT);

    int messageId2 = msgget(key2, 0666 | IPC_CREAT);

    struct wrapper wrap;

    int limit = 5;
    i = 0;
    while (i<50)
    {   
        for(int j = 0; j < 5; j++) 
        {
            char temp[10];
            sprintf(temp, "%d", i+j+1);
            strcat(temp, arr[i+j]); 
            strcpy(wrap.str, temp);
            wrap.value = 1;
            
            int transfer = msgsnd(messageId1, &wrap, 10, 0);
        }
        struct wrapper receive;
        
        msgrcv(messageId2, &receive, 10, 0, 0);
        puts(receive.str);
        i+=5;
        limit+=5;
    }
}
