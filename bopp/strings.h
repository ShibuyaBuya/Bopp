#ifndef _STRINGS_H
#define _STRINGS_H
#define SIZE_MB 1024 * 1024
#define MEMORY_TO_ALLOCATE 5 * SIZE_MB
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static char *path_root = "root";
int installed = 1;
char *installed_str;
#define PATH_ROOT path_root
static inline void set_root(const char *__path){
    path_root = (char *)__path;
}
#define setroot(__path) set_root(__path)
#define STAY 20
static int y_d = 2;
static int usedY = 1;
static void yclear(){
    y_d = 2;
}
static inline int Y(){
    if (usedY == 1){
        usedY = 0;
        return y_d;
    }
    y_d += 1;
    return y_d;
}
static int x_d = 2;
static int usedX = 1;
static void xclear(){
    x_d = 2;
}
static inline int X(){
    if (usedX== 1){
        usedX = 0;
        return x_d;
    }
    x_d += 1;
    return x_d;
}
#define Y Y()
#define X X()
#define yclear() yclear()
#define xclear() xclear()
#define x_strings 2
#define y_strings 2 
#define STR_BOPP_C_1 "Bopp. Tekroid, inc."
#define STR_BOPP_C_2 "Starting..."
#endif
