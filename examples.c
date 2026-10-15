#include <stdio.h>


// do this for every function so you can call it from anywhere.
int  sum(int a, int b); // recursion like and we don't even neeed to put a or b its optional we can make it int sum (int, int)
char makea(): // these tell C that the function exists somewhere even in another file



int main(int argc, char* argv[])
{
     int number;
    int number2=4;
    char achar='x';
    float afloatnumber=3.14;

    int numberarray[5]; //int[] numbers = new int[5];
    number[2]=3;
    int thisisreallyaboolean = 1; //that's  true

    //same:
        //for loops
        //while loops, if statements, else if, && ||

    printf("number2 is %d, achar is %c, floatnum is %f\n", number2,achar,afloatnumber);

                // mostly same: making functions and  calling them and getting return values
int sum (int a , int b)
{
    return a + b;
}
    return 0;
}
