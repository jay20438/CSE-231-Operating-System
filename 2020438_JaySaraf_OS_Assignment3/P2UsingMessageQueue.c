#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <mqueue.h>
#include <sys/types.h>
#include <stddef.h>

struct wrapper {
    long value;
    char str[10];
};

int main()
{
    int position;
    int key1 = 1111,key2 = 2222;
    int end,exit;
    int messageId1 = msgget(key1, 0666 | IPC_CREAT);

    
    int messageId2 = msgget(key2, 0666 | IPC_CREAT);

    struct wrapper message;

    int i;
    while(i<50)
    {
        for(int j = 0; j < 5; j++) 
        {
            int transfer = msgrcv(messageId1, (void*)&message, 10, 0, 0);
            puts(message.str);
        }
        position=i+4;
        struct wrapper sender;
        sprintf(sender.str, "%d", position);
        sender.value=1;
        msgsnd(messageId2, &sender, 10, 0);   
        
        i += 5;
       
    }
    
    end = msgctl(messageId1,IPC_RMID, NULL);
    exit = msgctl(messageId2,IPC_RMID, NULL);
}
