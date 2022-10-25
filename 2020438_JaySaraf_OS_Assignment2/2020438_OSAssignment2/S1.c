#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
//s1
void handler(int sig, siginfo_t *info, void *c)
{
    printf("S1 %d\n", (int)info->si_value.sival_int);

}

void fetch_signal()
{
    struct sigaction action;
    action.sa_handler = &handler;
    action.sa_flags = SA_RESTART; 

    sigaction(SIGTERM, &action, NULL);
    for(;;){
	 usleep(5);
	 }
}

int main(int arr1, char* arr2[])
{
    int S1 = fork();
    if(S1 == 0)
    {
        fetch_signal();
    }

    else
    {
       int pid_SR = fork();
       if(pid_SR == 0)
       {
            char pid_str[32];
           sprintf(pid_str, "%d", S1);
           char *arr3[] = {"./E1", pid_str, NULL};
           execv(arr3[0], arr3);
       } 
       
       else
       {
           char pid_str[32];
           sprintf(pid_str, "%d", S1);
           char *arr3[] = {"./E2", pid_str, NULL};
           execv(arr3[0], arr3);
       }
    }
}
