#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main () {
        FILE* yuki = fopen("/home/test/FP/crontab.data", "r");
        char str1[50], str2[50], str3[50], str4[50], str5[50], str6[50];
        char str[50];
        fscanf(yuki, "%s %s %s %s %s %s", str1, str2, str3, str4, str5, str6);
        //printf("%s %s %s %s %s", str1, str2, str3, str4, str5);
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        //printf("%d %d %d %d %d", tm.tm_min, tm.tm_hour, tm.tm_mday, tm.tm_mon+1, tm.tm_wday);
        int a=tm.tm_min, b=tm.tm_hour, c=tm.tm_mday, d=tm.tm_mon+1, e=tm.tm_wday;
        char con1[3], con2[3], con3[3], con4[3], con5[3];
        sprintf(con1, "%d", a);
        sprintf(con2, "%d", b);
        sprintf(con3, "%d", c);
        sprintf(con4, "%d", d);
        sprintf(con5, "%d", e);

        //printf("%s %s %s %s %s",con1,con2,con3,con4,con5);
        if ((!strcmp(str1,con1)||!strcmp(str1,"*")) && (!strcmp(str2,con2)||!strcmp(str2,"*")) && (!strcmp(str3,con3)||!strcmp(str3,"*")) && (!strcmp(str4,con4)||!strcmp(str4,"*")) && (!strcmp(str5,con5)$
        {
                execl("/bin/bash","bash",str6,NULL);
        }

        return 0;
}
