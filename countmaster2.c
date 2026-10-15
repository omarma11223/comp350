#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


int main (int argc, char* argv[]){


    int total = 0;
    int rep =  atoi(argv[3]);
    int childexit;
    pid_t Fork;
    int status;
    pid_t processpid[rep+1];
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int range  = end - start +1 ;
    int size =  range/ rep ; // in this case 5 if we are using 4
    int remainder =  range % rep; // in this  case equals 1 which we have to add one of the children  so we can calcualte the entire range.
    char startarg[20];
    char endarg[20];
    char* args[4] =  {"./countprimes", startarg , endarg, NULL};  //figured out the hard way that execvp only takes  strings



    for (int  i = 0 ; i < rep ; i++){

       sprintf(startarg, "%d" , start);

       end = start + size ;


       if ( i == 0 ){
        end = end + remainder;
       }

       sprintf(endarg, "%d", end);

        start = end;

       Fork =  fork();
       status = 0;
       processpid[i] = Fork;


        if (Fork == 0 ){
             execvp("./countprimes", args);
       }

    }



    for (int  j = 0; j < rep ; j++){
        waitpid(processpid[j],&status, 0);
        childexit = WEXITSTATUS(status);
        total = total + childexit;
    }
    printf("printing total for all pids  %d\n" , total);

}
