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
#include<sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <errno.h>
#include<semaphore.h>

int main()
{
  sem_t *SemaPaper=sem_open("/Paper",0);
  sem_t *SemaTobacco=sem_open("/Tobacco",0);
  sem_t *SendMore=sem_open("/SendMore",0);

  while (1)
    {
      sem_wait (SemaTobacco);
      if (sem_trywait(SemaPaper) == 0)
        {
          printf(" Smoker A with match smokes a cigarette\n");
          sleep(3);
          sem_post (SendMore);
        }

      else sem_post (SemaTobacco);
    }
}

