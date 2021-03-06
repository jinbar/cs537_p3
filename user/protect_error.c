#include "types.h"
#include "stat.h"
#include "user.h"

#define PGSIZE  4096
#define INT_MAX 2147483647
#define USERTOP 0xA0000


void eprinf(void) {
    printf(1, "mprotect: failed to return -1\n");
    printf(1, "TEST FAILED\n");
}

int main(int argc, char *argv[])
{
    if (mprotect((void *)0, -1) == 0) {
        eprinf();
        printf(1, "negative protect"); 
        exit();
    } 

    if (mprotect((void *)0, INT_MAX) == 0) {
        eprinf();
        printf(1, "too big?"); 
        exit();
    }

    if (mprotect((void *)0, (USERTOP / PGSIZE) + 1) == 0) {
        eprinf();
        printf(1, "usertop/pgsize?");
        exit();
    }

    if (mprotect((void *)1, (USERTOP / PGSIZE) + 1) == 0) {
        eprinf();
        printf(1, "offset?");
        exit();
    }
    

    if (munprotect((void *)0, -1) == 0) {
        eprinf();
        printf(1, "neg again ??");
        exit();
    } 

    if (munprotect((void *)0, INT_MAX) == 0) {
        eprinf();
        printf(1, "big again ? ");
        exit();
    }

    if (munprotect((void *)0, (USERTOP / PGSIZE) + 1) == 0) {
        eprinf();
        printf(1, "usertop/pgsize? again");
        exit();
    }
    
    if (munprotect((void *)1, (USERTOP / PGSIZE) + 1) == 0) {
        eprinf();
        printf(1, "usertop/pgsize? offset ? again ? ");
        exit();
    }

    printf(1, "TEST PASSED\n");
    exit();
}
