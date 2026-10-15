
#include <stdio.h>
#include <stdlib.h>


void sum (int n, int* answer) {

      int total = 0;
   for (int i = 0 ; i <= n ; i++){

     total= total + i;
   }
     *answer = total;

}


int main (int argc, char* argv[])  {

        int n = atoi(argv[1]);
        int ans;
        sum(n, &ans);
//      printf("enter a positive number: ");
//      scanf(" %d", &n);
        printf("the sum is %d\n", ans);
        return 0;
}
