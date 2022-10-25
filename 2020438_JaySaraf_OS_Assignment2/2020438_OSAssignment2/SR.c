#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/time.h>

int pid;

int rdrand64_step (uint64_t *rand)
{
	unsigned char val;

	asm volatile ("rdrand %0; setc %1"
		: "=r" (*rand), "=qm" (ok));

	return (int) val;
}
void signal_handler(int sig)
{   
    int rand;
    int val;
    val = rdrand64_step(rand);
    union sigval value;
    sigqueue(pid, SIGTERM, value);
}

void fetch_signal()
{
    struct sigaction action;
    action.sa_handler = &signal_handler;
    action.sa_flags = SA_RESTART; 

    sigaction(SIGALRM, &action, NULL);
    for(;;)
    {
     usleep(500);
    }
}

int main()
{
    struct itimerval timer;	
    
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;	
    timer.it_interval = timer.it_value;
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) 
    {
        perror("Error occured! Unable to call setitimer().");
        exit(1);
    }
    
    fetch_signal();
}
