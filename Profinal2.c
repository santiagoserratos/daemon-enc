#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

int main(int argc, char* argv[])
{
char renglon[50];
char id[7];
char procesos[20];
int cont=0;
FILE *rd;

pid_t process_id = 0;
pid_t sid = 0;
// Crear el proceso hijo
process_id = fork();
// Si el fork falla
if (process_id < 0)
{
printf("fork failed!\n");
// retorna falla y sale
exit(1);
}
// PARENT PROCESS. Need to kill it.
if (process_id > 0)
{
printf("process_id del proceso hijo %d \n", process_id);
// return success in exit status
exit(0);
}
// aplicamos la funcion umask
umask(0);
// nueva sesion
sid = setsid();
if(sid < 0)
{
// fallo
exit(1);
}
chdir("/");
// Cerramos stdin, stdout, stderr
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);


while (1)
{
	sleep(7);
	 rd=popen("ps -u santiago", "r");
        while(!feof(rd))
        {
                cont=0;
                fgets(renglon,50,rd);
                for(int i=26; i<38; i++)
                {
                        procesos[cont]=renglon[i];
                        cont++;
                }
                cont=0;
                for(int i=3; i<7; i++)
                {
                        id[cont]=renglon[i];
                        cont++;
                }
        if(procesos== "resta");
        {
                system("pkill resta");
        }

	if(procesos== "multi");
        {
                system("pkill multi");
        }

	if(procesos== "division");
        {
                system("pkill division");
	}
        pclose(rd);
        }
}
return (0);
}
