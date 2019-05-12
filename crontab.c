#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

pthread_t tid[10];  
char str1[50], str2[50], str3[50], str4[50], str5[50], str6[50];
char str[50];
char con1[3], con2[3], con3[3], con4[3], con5[3];

void* cmd()
{
  pid_t c1= fork();
  if(c1==0)
  {
      execl("/bin/bash","bash",str6,NULL);
  }
}

int main(void *arg) {
    pid_t pid, sid;

    pid = fork();

    if (pid < 0) {
    exit(EXIT_FAILURE);
    }

    if (pid > 0) {
    exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();

    if (sid < 0) {
    exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1) {
        FILE* yuki = fopen("/home/test/FP/crontab.data", "r");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        int a=tm.tm_min, b=tm.tm_hour, c=tm.tm_mday, d=tm.tm_mon+1, e=tm.tm_wday;


        fscanf(yuki, "%s %s %s %s %s %s", str1, str2, str3, str4, str5, str6);

        sprintf(con1, "%d", a);
        sprintf(con2, "%d", b);
        sprintf(con3, "%d", c);
        sprintf(con4, "%d", d);
        sprintf(con5, "%d", e);

        if ((!strcmp(str1,con1)||!strcmp(str1,"*")) && (!strcmp(str2,con2)||!strcmp(str2,"*")) && (!strcmp(str3,con3)||!strcmp(str3,"*")) && (!strcmp(str4,con4)||!strcmp(str4,"*")) && (!strcmp(str5,con5)||!strcmp(str5,"*")))
        {
                pthread_create(&tid[0],NULL,cmd,NULL);
        }
    }

  
    exit(EXIT_SUCCESS);
}
