#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,wrt;
int rc=0;

void *reader(void* arg)
{
	sem_wait(&mutex);
	rc++;

	if(rc==1)
	{
		sem_wait(&wrt);
		sem_post(&mutex);

		printf("Reader reading the contents\n");
		printf("Reading completed\n");

		sem_wait(&mutex);
		rc--;
	}

	if(rc==0)
	{
		sem_post(&wrt);                     //Now access is given to writer
		//sem_post(&mutex);
	}
}


void *writer(void* arg)
{
	sem_wait(&wrt);

	printf("Writer writing the contents\n");
	printf("Writing complete\n");

	sem_post(&wrt);
}

int main()
{
      int num_reader,num_writer;
      int i;
      
      printf("WELCOME\n");
      printf("Enter no. of readers:\n");
      scanf("%d",&num_reader);
      printf("Enter no. of writers:\n");
      scanf("%d",&num_writer);

  	  pthread_t rtid[5],wtid[5];
  	  sem_init(&mutex,0,1);
      sem_init(&wrt,0,1);

      for(i=0;i<=num_reader;i++)
      {
    	pthread_create(&rtid[i],NULL,reader,(void *)i);
  	  }

  	  for(i=0;i<num_writer;i++)
  	  {
  	  	pthread_create(&wtid[i],NULL,writer,(void *)i);
  	  }

  	  for(i=0;i<=num_reader;i++)
     {
   	   pthread_join(rtid[i],NULL);
  	 }

  	  for(i=0;i<=num_writer;i++)
     {
   	   pthread_join(wtid[i],NULL);
  	 }

  return 0;
}

