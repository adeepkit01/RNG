#include <stdio.h>
#include <time.h>

/*Program to generate randomness based on system time*/

int main ()
{
  time_t seconds = time (NULL);
  clock_t tic = clock();
  int num = (int)seconds/(int)tic, i;
  FILE *fptr;
  fptr=fopen("hashed.txt","a");
  fprintf(fptr,"%d\n",num);
  fclose(fptr);
}
