#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define TOTAL_PHILOSOPHERS 5
#define EATING 0
#define HUNGRY 1
#define THINKING 2
#define LEFT (philosopherId + 4) % TOTAL_PHILOSOPHERS
#define RIGHT (philosopherId + 1) % TOTAL_PHILOSOPHERS

int bowls[4] = {1,1,1,1};
int state[TOTAL_PHILOSOPHERS];
int philosophers[TOTAL_PHILOSOPHERS] = { 0, 1, 2, 3, 4 };
int j,bowlNum;
sem_t bowl;
sem_t S[TOTAL_PHILOSOPHERS];

void test(int philosopherId)
{
	if (state[philosopherId] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) 
	{
	   state[philosopherId] = EATING;

	   sleep(2);
	   
	  
	   
	   for(j = 0;j<4;j++)
	   {
	     if(bowls[j] == 1)
	       {
	         bowlNum = j+1;
	         bowls[j] = 0;
	         philosophers[philosopherId] = j+1;
	       }     
	   }
	   if(philosopherId != 0)
	   {
	   printf("Philosopher %d picks fork %d ,fork %d and bowl %d\n",philosopherId + 1, LEFT + 1, philosopherId + 1,philosophers[philosopherId]);

	   printf("Philosopher %d is Eating\n", philosopherId + 1);

	   }
	   //When picking fork sem_post(&S[philosopherId]) is of no use.
	   //It is used for waking up other hungry philosophers after fork is put down by the philosopher using it.
	   sem_post(&S[philosopherId]);
	   sem_post(&bowl);
	}
}

// Function for picking up the fork.
void pick_up_fork(int philosopherId)
{

	state[philosopherId] = HUNGRY;

	printf("Philosopher %d is Hungry\n", philosopherId+ 1);

	// eat if neighbours are not eating
	test(philosopherId);

	// if unable to eat wait to be signalled
	sem_wait(&S[philosopherId]);
	sem_wait(&bowl);
	sleep(1);
}

// Function for putting down the fork.
void put_down_fork(int philosopherId)
{
	// state that thinking
	state[philosopherId] = THINKING;

	if(philosopherId != 0)
	{
	printf("Philosopher %d putting fork %d ,fork %d and bowl %d down on the table.\n",philosopherId + 1, LEFT + 1, philosopherId+ 1,philosophers[philosopherId]);
	}
	printf("Philosopher %d is thinking\n", philosopherId + 1);

	test(LEFT);
	test(RIGHT);
}

void* philosopher(void* position)
{

	for(;;) {

		int i = (int)position;

		sleep(1);

		pick_up_fork(i);

		sleep(0);

		put_down_fork(i);
	}
}

int main()
{

	int i;
	pthread_t thread_id[TOTAL_PHILOSOPHERS];

	// semaphores being initialized.

	sem_init(&bowl, 0, 4);

	for (i = 0; i < TOTAL_PHILOSOPHERS; i++)
	{

		sem_init(&S[i], 0, 0);
	}

	for (i = 0; i < TOTAL_PHILOSOPHERS; i++) 
	{
		// Philosopher processes being created.
		pthread_create(&thread_id[i], NULL,philosopher, (void*)i);

		printf("Philosopher %d is thinking\n", i + 1);
	}

	for (i = 0; i < TOTAL_PHILOSOPHERS; i++)
	{

		pthread_join(thread_id[i], NULL);
	}
}



