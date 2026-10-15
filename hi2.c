#include <stdio.h>


int main()
{
    printf("this is true and this is false %d\n", 7==7,7<7);
    int i;
    for(i = 0; i <10 ;i++){
    printf("loop i is %d\n", i);
    }

    int j=5;
    while(j<10)
    {
        j=j+1;
        if(j==7)
            printf("7");        //if there is one line brackets are optional same for loops as well..

    printf("Hello, World!\n");
    return 0;
}
