#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
  

struct mesg_buffer {
    long mesg_type;
    char textMessage2[100];
} message;
  
int main()
{
    int check = 4;
    char str2[80];
    key_t key;
    int msgid;
  
    
    key = ftok("mymessagequeuefile", 65);
  
    
    msgid = msgget(key, 0666 | IPC_CREAT);
  
    
    char temp[11];
        for(int q=1;q<51;q++)
        {
        
        temp[(q-1)%10] = str2[q-1];
        if(q%10 == 0 && q>0)
          {
            
            msgrcv(msgid, &message, sizeof(message), 1, 0);
  
     
            printf("Data Received: %s \n",message.textMessage2);
          }
          
          
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
       
        check += 5;
        
  
   
    msgctl(msgid, IPC_RMID, NULL);
  
    return 0;
}
