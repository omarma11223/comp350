// Omar Mahmoud
// kernel hello
/* Omar Mahmoud */

void printchar(char letter);
void printString(char* word);
void read_string(char* array);
void readsector(char* array , int sector);
void handleInterrupt21(int ax , int bx , int cx , int dx);
void readFile(char* filename, char* buff, int* secsread);

main()
{
    char line[80];
    char buffer[13312];
    int sectorsRead;
    makeInterrupt21();
     interrupt(0x21,4,"shell",0,0);
    while(1){}
}




void printchar(char letter){
interrupt(0x10, 0xe * 256+ letter , 0,0,0);
}

void printString(char* word){
int i=0;
int ax;
while(word[i] != '\0')
   {

ax =  0xe * 256 + word[i];
interrupt(0x10, ax, 0, 0,0);
i++;
    }
}




void read_string(char* array){
int value = 0;
int i=0;
while ((value = interrupt(0x16 ,0,0,0,0)) != 0xd)
  {
    if (value == 0x8){

        i = i-1;
        printchar(value);                       // figured it out the hardway. everytime we use interrupt 10 the cursor is moved one position to the right
        printchar(' ');                         // so  that when we write then next character it doesn't overwrite the first. which has caused  me to write the backspace twice. the first
        printchar(value);                       // to  move the cursor back but the second one  to counteract interrupt 10 so that when we  press back space again we can remove the next letter.
        }else {

array[i] = value;
printchar(value);
i++;
    }
  }
array[i] = 0xa;
array[i+1] =0x0;
printchar('\n');    // added new line and then carriage return which is basically starting at the beginning of line. so we mimick endl.
printchar('\r');

}



void readsector(char* array, int sector){
    int ah=2;
    int al=1;
    int bx = array;
    int ch =0;
    int cl = sector + 1;
    int dh =0;
    int dl = 0x80;
    int ax =ah*256+al;
    int cx =ch*256+cl;
    int dx =dh*256+dl;

    interrupt(0x13,ax , bx, cx , dx);

}

void executeProgram(char* name){
char buffe[13312];
int i = 0;
int sectors;
readFile(name, buffe, &sectors);
for (i = 0; i < sectors *512 ;i++){
    putInMemory(0x2000, i ,buffe[i]);
     }
    launchProgram(0x2000);
}
void readFile(char* filename, char* buff, int* secsread)
{
int i = 0;
int count = 0;
char dir[512];
int entry = 0;
int j = 0;
int k = 0;
int place =0;
int offset = 0;
int found = 0;
*secsread = 0;
readsector(dir,2);
printString("readfile reached");
while(filename[i] != '\0'){
    buff[i] = filename[i];
    i++;
    }
for (entry = 0; entry < 16; entry++){
    for(j = 0  ;  j < 6 ; j++){
      if (filename[j] == dir[entry*32+j]){
        count = count + 1;
      }
    }

     if (count == 6){
        found  =1;
        place = entry;
       for (k = 6; k < 32 ; k++){
            if(dir[place*32+k] == 0){
                    break;
            }
            readsector(buff + offset ,dir[place*32+k]);
            offset = offset + 512;
            (*secsread)++;

      }
        break;
    }

        count = 0 ;
  }
     if(found == 0 ){
        printString("no file found\r\n ");
        }

}




void terminateProgram(){
    char shellname[6];
         shellname[0]='s';
         shellname[1]='h';
         shellname[2]='e';
         shellname[3]='l';
         shellname[4]='l';
         shellname[5]='\0';

        executeProgram(shellname);
}




void handleInterrupt21(int ax, int bx, int cx, int dx){
    if(ax == 0){
       printString(bx);
    }else if (ax == 1){
            read_string(bx);
    }else if(ax == 2){
            readsector(bx, cx);
    }else if (ax == 3){
            readFile(bx, cx , dx);
    }else if (ax == 4){
            executeProgram(bx);
    }else if(ax == 5){
        terminateProgram();
    }else{
        printString("Error , wrong input choose a number between 0 and 5 ");
  }
}
