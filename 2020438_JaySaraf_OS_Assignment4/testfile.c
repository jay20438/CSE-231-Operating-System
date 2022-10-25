//test file
void producer()
{
	int randomData = open("/dev/urandom", O_RDONLY);
if (randomData < 0)
{
    printf("Error has occured!");
}
else
{
	char randomArrayData[8];
	ssize_t output = read(randomData,randomArrayData,sizeof randomArrayData);
	
	SYSCALL_DEFINE1(writer,long,output);
}
   
}

void consumer()
{
    	int randomData = open("/dev/urandom", O_RDONLY);
if (randomData < 0)
{
    printf("Error has occured!");
}
else
{
	char randomArrayData[8];
	ssize_t output = read(randomData,randomArrayData,sizeof randomArrayData);
	
	SYSCALL_DEFINE1(reader,long,output);
}
   
}
  
// Driver Code
int main()
{
    int n, i;
    printf("\n1. Enter 1 for Producer\n2. Enter 2 for Consumer");
  

    for (i = 1; i > 0; i++) {
  
        printf("\nEnter operation to be performed:");
        scanf("%d", &n);
  
        if(n == 1)
        {
		   
            if ((mutex == 1) && (empty != 0)) {
                producer();
            }
  
            else {
                printf("Buffer is full now!");
            }
		}
  
        if(n == 2){
		
            if ((mutex == 1)&& (full != 0)) 
			{
                consumer();
            }

            else {
                printf("Empty buffer");
            }
            break;
        }

        else{
		
            exit(0);
            break;
        }
        }
    }
}
