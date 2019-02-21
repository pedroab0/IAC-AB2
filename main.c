#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char *argv[], char *envp[])
{
  int pid, i, tempoProc; // Process ID, counter and time process
  char ucp[100], ucpMem[100],matarProc[20];

   
    pid = fork(); // creates a process
   

    if(pid < 0) //process error
    {
      perror("Erro: ");
      exit(-1);
    }
    

      sprintf(ucp, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");  //text CPU
      sprintf(ucpMem,"%s%d%s","pmap ", pid, " | grep -i total |" " awk '{print $2}'"); //text memory
      sprintf(matarProc, "%s%d","kill ",pid);  //text to kill the process



    if(pid > 0) //If i'm the father process
    {
      for(i=0;i<11;i++)
      {
        system("clear");
      
        if(strcmp(argv[1], "ucp") == 0) //if the argument after the program name is "ucp".
        {
          printf("PROCESSO DA UCP\n");
          printf("TEMPO: %ds\n",i);
          printf("UCP(%%)\n");
          system(ucp); //calling the cpu usage
        }
        else if(strcmp(argv[1], "ucp-mem") == 0) //if the argument after the program name is "ucp-mem".
        {
          printf("PROCESSO DA MEMORIA E UCP\n");
          printf("TEMPO: %ds\n",i);
          printf("UCP(%%)\n");
          system(ucp); //Request the cpu usage.
          printf("\nMEMORIA\n");
          system(ucpMem); //Request the memory usage.
        }
        
        usleep(1000000); //Suspend execution.
      }

      system(matarProc);
    }
    else //If i'm the son process (pid == 0)
    {
      if (strcmp(argv[1], "ucp") == 0) //If argv[1] is equal 'cpu',  executes the UCP usage code.
  		{
  			for(;;)
  			{
  				
  			}
  		}
  		else if (strcmp(argv[1], "ucp-mem") == 0) //If argv[1] is equal 'cpu-mem', executes the UCP and memory usage code.
  		{
        clock_t tempoI, tempoF, tempoT;
        tempoI = clock(); // start to count
  			for(;;)
  			{
          tempoF = clock(); // end of clock
          tempoT = (double)(tempoF - tempoI) / CLOCKS_PER_SEC;
          //
          if(tempoT<= 10000)
          {
            	malloc(15*sizeof(int));
          }

  			}
  		}

    }
    perror("Erro");

    printf("Tchau !\n");
    exit(0);


}