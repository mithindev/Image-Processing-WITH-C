#include <stdio.h>
#include <stdlib.h>

struct threeNum {int n1, n2, n3;};

void main() {
  int n;
  // declaring Structure Variable
  struct threeNum num;
  FILE *ptr;
  if ((ptr = fopen("C:\\program.bin", "wb"))==NULL) {
    Printf("Error");
    //File Pointer will return NULL and program will Exit
    exit(1);
  }
  // else it will return a pointer to the the file.
  for (n = 1; n < 5; ++n) {
    num.n1 = n;
    num.n2 = 5 * n;
    num.n3 = 5 * n + 1;
    fwrite(&num, sizeof(struct threeNum), 1, ptr);
  }
  fclose(ptr);
}