
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/time.h>
#include <stdint.h>
void signal_handler(sig)
{
    union sigval value;
    unsigned int low = 0, high = 0;
   __asm__ __volatile__ ("rdtsc" : "=a"(low), "=d"(high));
   return ( (uint64_t)low)|( ((uint64_t)high)<<32 );
}


void fetch_signal()
{
    struct sigaction action;
    action.sa_handler = &signal_handler;
    action.sa_flags = SA_RESTART; 

    sigaction(SIGALRM, &action, NULL);
    while(kill(getppid(), SIGTERM))
    {
      sleep(3);
    };
}

int main(int argc, char* argv[])
{
    printf("\n Inside ST");
    signal(SIGALRM,signal_handler);
    while(1){
		struct itimerval timer;
		timer.it_interval.tv_sec=2;
		timer.it_interval.tv_usec=50000;
		timer.it_value.tv_sec=2;
		timer.it_value.tv_usec=50000;
		signal(SIGALRM,signal_handler);
		setitimer(ITIMER_REAL,&timer,NULL);
	}
    
}
