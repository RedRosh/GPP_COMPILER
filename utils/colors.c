#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

void red()
{
  printf("\033[1;31m");
}

void green()
{
  printf("\033[0;32m");
}
void blue()
{
  printf("\033[0;34m");
}

void yellow()
{
  printf("\033[0;33m");
}

void reset()
{
  printf("\033[0m");
}
void cyan()
{
  printf("\033[0;36m");
}