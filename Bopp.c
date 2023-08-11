#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Bopp.h"
static int Program(){
  // check if Program files exists
  if (access("Program", F_OK) != 0){
    return PROGRAM_NOT_EXISTS;
  }
  if (access("Dev", F_OK) != 0){
    return 181;
  }
}
int main(){
  printf("Hello, world!\n");
  return Program();
}
