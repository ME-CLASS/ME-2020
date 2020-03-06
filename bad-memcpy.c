#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    void *ptr = NULL;
    void *dest, *src = "abcdef0123456789";
    void *arbit_addr = (void *)0xffffffffff601000;
    int n = strlen(src);

    ptr = malloc(256 * 1024);
    if (!ptr) {
        printf("malloc(256*1024) failed\n");
        exit(-1);
    }

    if (argc == 1)
        dest = ptr; /* correct */
    else
        dest = arbit_addr; /* bug! */
    memcpy(dest, src, n);

    free(ptr);
    exit(0);
}
