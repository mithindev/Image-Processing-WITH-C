#include <stdio.h>

void main() {
  float j = 0;
  for (int i = 0; i< 11;i++) {
    double time = j + 180.0/11;
    printf("%d hour: %lf min\n",i,time);
    j += 5;
  }
}