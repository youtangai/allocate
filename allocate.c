#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM (8192)

void fill(unsigned int n, int *p) {
  for (unsigned int i = n-NUM; i < n; i++) {
    p[i] = 1;
  }
}

int main(void) {

    unsigned int n = NUM;
    unsigned int upper = 1024 * 1024 * 1024;
    int *p;
    int *q;

    if ((p = (int *)malloc(n*sizeof(int))) == NULL){
        printf("mallocできません\n");
        exit(EXIT_FAILURE);
    }

    fill(n, p);
    
    while(1) {
      usleep(1);
        n += NUM;
        if (n > upper)
            break;
        if ((q = (int *)realloc(p, n*sizeof(int))) == NULL) {
            printf("reallocできません\n");
            free(p);
            exit(EXIT_FAILURE);
        }
        p = q;
	fill(n, p);
    }
    free(p);
    printf("finish!!\n");
    return 0;
}
