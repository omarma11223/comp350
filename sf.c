#include <stdio.h>

int main() {
    int age;
    char name[50];


    printf("asking for input for name and age");
    scanf("%s %d", name, &age);
    printf("printing  name %s and age %d\n",name,age);
}
