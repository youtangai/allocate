#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MAX (1024*1024*1024)

int main(void) {
  clock_t start = clock();
  unsigned long *p;
  int i;
    
  if ((p = (unsigned long *)malloc(MAX*sizeof(unsigned long))) == NULL){
    printf("cant malloc\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < MAX; i++) {
    p[i] = 4294967295;
  }
  
  clock_t end = clock();
  printf("spent\ttime\t%ld\tms\n", end-start);
  return 0;
}
