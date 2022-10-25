//P1 of message queue
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10

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



struct mesg_buffer {
    long mesg_type;
    char textMessage1[50][11];
} message;
  
  

int main()
{


char indexCollector[10];
    char arr[50][11];
    char str2[80];
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
      
      
    key_t key;
    int msgid;
     
      

    key = ftok("mymessagequeuefile", 65);
  

    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    
    struct mesg_buffer mesg_data;
    for(int i=0;i<50;i++)
    {
      
    
  
    int limit = 5;
    int t=0;     
        
               
        for(int q=0;q<5;q++)
        {
          message.textMessage1[q] = arr[q+t];
          printf("%s",arr[q+t]);
        }
        t+=5;
        
        int p = i;
        while(p<limit)
        {
           msgsnd(msgid, &message, sizeof(message.textMessage1[p]), 0);
           
           printf("Data send: %s \n", message.textMessage1[p]);
           p++;
        }
        i+=5;
        limit+=5;
        
    
    }
    
  
    return 0;
}
