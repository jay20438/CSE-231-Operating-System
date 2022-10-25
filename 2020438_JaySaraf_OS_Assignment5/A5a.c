#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define TOTAL_PHILOSOPHERS 5
#define EATING 0
#define HUNGRY 1
#define THINKING 2
#define LEFT (philosopherId + 4) % TOTAL_PHILOSOPHERS
#define RIGHT (philosopherId + 1) % TOTAL_PHILOSOPHERS

int state[TOTAL_PHILOSOPHERS];
int philosophers[TOTAL_PHILOSOPHERS] = { 0, 1, 2, 3, 4 };

sem_t mutex;
sem_t S[TOTAL_PHILOSOPHERS];

void test(int philosopherId)
{
	if (state[philosopherId] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) 
	{
	   state[philosopherId] = EATING;

	   sleep(2);

	   printf("Philosopher %d picks fork %d and %d\n",philosopherId + 1, LEFT + 1, philosopherId + 1);

	   printf("Philosopher %d is Eating\n", philosopherId + 1);

		
	   //When picking fork sem_post(&S[philosopherId]) is of no use.
	   //It is used for waking up other hungry philosophers after fork is put down by the philosopher using it.
	   sem_post(&S[philosopherId]);
	}
}

// Function for picking up the fork.
void pick_up_fork(int philosopherId)
{

	sem_wait(&mutex);

	state[philosopherId] = HUNGRY;

	printf("Philosopher %d is Hungry\n", philosopherId+ 1);

	// eat if neighbours are not eating
	test(philosopherId);

	sem_post(&mutex);

	// if unable to eat wait to be signalled
	sem_wait(&S[philosopherId]);

	sleep(1);
}

// Function for putting down the fork.
void put_down_fork(int philosopherId)
{

	sem_wait(&mutex);

	// state that thinking
	state[philosopherId] = THINKING;

	printf("Philosopher %d putting fork %d and %d down on the table.\n",philosopherId + 1, LEFT + 1, philosopherId+ 1);
	printf("Philosopher %d is thinking\n", philosopherId + 1);

	test(LEFT);
	test(RIGHT);

	sem_post(&mutex);
}

void* philosopher(void* position)
{

	for(;;) {

		int* i = position;

		sleep(1);

		pick_up_fork(*i);

		sleep(0);

		put_down_fork(*i);
	}
}

int main()
{

	int i;
	pthread_t thread_id[TOTAL_PHILOSOPHERS];

	// semaphores being initialized.
	sem_init(&mutex, 0, 1);

	for (i = 0; i < TOTAL_PHILOSOPHERS; i++)
	{

		sem_init(&S[i], 0, 0);
	}

	for (i = 0; i < TOTAL_PHILOSOPHERS; i++) 
	{
		// Philosopher processes being created.
		pthread_create(&thread_id[i], NULL,philosopher, &philosophers[i]);

		printf("Philosopher %d is thinking\n", i + 1);
	}

	for (i = 0; i < TOTAL_PHILOSOPHERS; i++)
	{

		pthread_join(thread_id[i], NULL);
	}
}


