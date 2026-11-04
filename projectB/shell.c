
int same(char* command, char*line, int n);

main(){

char buffer[13312];
char line[80];
char strip[80];
int sectorsRead = 0;
int j = 0;
char* command1 = "exec";
char* command2 = "type";
char* filename = strip+4;
int i =  0;
    while(1){
    syscall(0,"SHELL>");
    syscall(1, line);
    for ( i = 0; line[i] != '\0'; i++){
        if(line[i] != ' ' && line[i] != '\r' && line[i] != '\n'){
            strip[j] = line[i];
            j++;
        }
    }
    strip[j] = '\0';
    j = 0;
    if(same(command1,strip,4) == 1 ){
        syscall(4,filename);

    }else if(same(command2,strip, 4) == 1){
        syscall(3,filename, buffer, &sectorsRead);
        syscall(0, buffer);
    }else{
        syscall(0,"BAD COMMAND\r\n");
        }
                syscall(5);

    }

}

int  same(char* command,char* line, int n){

      int i ;
      for (i= 0 ; i < n; i++){
            if(command[i] != line[i]){
                return 0;
            }
        }

        return 1;
}
