#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM (1024)

int main(void) {

    unsigned int n = 1024;
    unsigned int upper = 1024 * 1024 * 1024;
    char *p;
    char *q;

    if ((p = (char *)malloc(n)) == NULL){
        printf("mallocできません\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        usleep(100);
        n += NUM;
        if (n > upper)
            break;
        if ((q = (char *)realloc(p, n)) == NULL) {
            printf("reallocできません\n");
            free(p);
            exit(EXIT_FAILURE);
        }
        p = q;
    }
    free(p);
    printf("finish!!\n");
    return 0;
}