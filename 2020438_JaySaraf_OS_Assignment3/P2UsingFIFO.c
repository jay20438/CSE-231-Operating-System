#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main()
{
    int fd1;

    // FIFO file path
    char * myfifo = "/home/jay/Desktop/myfifo";

    //mkfifo has parameters as name and permission.
    mkfifo(myfifo, 0666);

    char str1[50][11], str2[80];
    char typeCastNum[50];
    int j = 0;
    int check = 4;
    while (j<50)
    {
        // File opened for reading only.
        fd1 = open(myfifo,O_RDONLY);
        
        int k = 0;
       
       read(fd1, str2, 80);
       
        
        char temp[11];
        for(int q=1;q<51;q++)
        {
        
        temp[(q-1)%10] = str2[q-1];
        if(q%10 == 0 && q>0)
          {
            printf("User1: %s\n",temp);
          }
        }
       
        check += 5;
        close(fd1);

       
        fd1 = open(myfifo,O_WRONLY);
        
        j +=5;
        sprintf(typeCastNum,"%d",j-1);
        //Writing to the file
           write(fd1,typeCastNum,strlen(typeCastNum)+1);
         
        close(fd1);
        
        
    }
    return 0;
}
