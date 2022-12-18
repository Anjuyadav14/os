#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Configured Memory: ");
  fflush(stdout);
  system("awk 'NR == 1 {$1=\"\\b\"; print $0;}' /proc/meminfo");

  printf("Free Memory: ");
  fflush(stdout);
  system("awk 'NR == 2 {$1=\"\\b\"; print $0;}' /proc/meminfo");

  printf("Used Memory: ");
  fflush(stdout);
  system("awk '/MemTotal/ {total=$2; unit=$3;} /MemFree/ {free=$2;} END {printf \"%i %s\\n\", (total-free), unit;}' /proc/meminfo");

  return 0;
}
