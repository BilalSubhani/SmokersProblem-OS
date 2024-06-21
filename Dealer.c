#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <assert.h>
#include <ctype.h>
#include<wait.h>
#include<string.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <sys/stat.h>
#include <errno.h>
#include<semaphore.h>
#include<time.h>

int main()
{
  sem_t *SemaMatch=sem_open("/Match",O_CREAT,0660,0);
  sem_t *SemaPaper=sem_open("/Paper",O_CREAT,0660,0);
  sem_t *SemaTobacco=sem_open("/Tobacco",O_CREAT,0660,0);
  sem_t *SendMore=sem_open("/SendMore",O_CREAT,0660,1);


  while (1)
  {
    srand(time(0));
    int number = rand() % 3;

    switch (number)
    {

           case 0:  // match and paper
               sem_post(SemaMatch);
               sem_post(SemaPaper);
               printf(" Tobacco\n");                   
               break;

           case 1:  // match and tobacco
               sem_post(SemaMatch);
               sem_post(SemaTobacco);
               printf(" Paper\n");
               break;

           case 2: // tobacco and paper 
               sem_post(SemaPaper);
               sem_post(SemaTobacco);
               printf(" Match\n");
               break;
    }

      sem_wait (SendMore);
  }



}
