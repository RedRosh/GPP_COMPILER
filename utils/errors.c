#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

void logError(char* errorMessage){
    red();
    printf("[ Error ] : %s \n",errorMessage);
    reset();
}