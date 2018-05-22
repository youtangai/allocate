#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM (1024)
#define UPPER (1024*1024*1024)

void fill(unsigned int n, int *p) {
    for (unsigned int i = n - NUM; i < n; i++) {
        p[i] = 4294967295;//all bit true
    }
}

int main(void) {

    unsigned int n = NUM;
    int *p, *q;

    if ((p = (int *)malloc(n*sizeof(int))) == NULL){
        printf("cant malloc\n");
        exit(EXIT_FAILURE);
    }

    fill(n, p);
    
    for (n = n+NUM; n <= UPPER; n += NUM) {
        if ((q = (int *)realloc(p, n*sizeof(int))) == NULL) {
            printf("cant realloc\n");
            free(p);
            exit(EXIT_FAILURE);
        }
        p = q;
	fill(n, p);
    }

    free(p);
    return 0;
}
