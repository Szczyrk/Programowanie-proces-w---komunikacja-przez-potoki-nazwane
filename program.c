// Programowanie-proces-w---komunikacja-przez-potoki-nazwane
// Przed uruchomieniem programu, należy utwożyć potok za pomocą: "mknod FIFO p", a następnie ustawić prawa do pliku FIFO: "chmod FIFO 777"

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
char ptr;
FILE* fd;


fifo = open("FIFO",O_WRONLY);


 for(int i =0; i<argc;i++)
   {

     fd = fopen(argv[i],"r");
       if(fd != NULL)
         {
        write(fifo, "Plik: ",8);
        write(fifo, argv[i],(sizeof(argv[i])+1)*sizeof(char)); //nazwa programu
        write(fifo, "\n",3);

           while (!feof(fd))
                {
               fscanf(fd,"%c",&ptr);
               write(fifo,&ptr,sizeof(char));
             }
           fclose(fd);
         }
       else
         printf("Nie ma pliku %s!!!\n",argv[i]);
   }
close(fifo);
 return 0;
}
