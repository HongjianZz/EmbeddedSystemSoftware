#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"
#include "stats.h"
#include "data.h"
#include "course1.h"

int main(){
    #ifdef COURSE1
        printf("Initializing course 1");
        course1();
        return 0;
    #endif
    return 0;
}


