//Programowanie-proces-w---komunikacja-przez-potoki-nazwane
//Program czytający z potoku FIFO

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
int fifo;
fifo = open("FIFO",O_RDONLY);
if(fifo == NULL)
{
printf("Brak pliku fifo !!!\n");
exit(0);
}
  char input[32*1024];
  close(0);
          dup(fifo);
          execlp("tail","tail" ,"+1cf",(char*)NULL);



return 0;
}
