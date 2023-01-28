# include <stdio.h>
# include <string.h>

void main () {
  FILE *filePointer; //file Pointer

  char txt[100];

   //Opening Exixting File in write mode
  filePointer = fopen("demo.c", "r");

  // If this filePointer is Null
  if (filePointer == NULL) {
    printf("demo.c failed to open.");
  } else {
    printf("File Opened!\n");

    while(fgets(txt, 100, filePointer) != NULL) {
      printf("%s", txt);
    }
    fclose(filePointer); // Closing the file
    printf("File Closed!");
  }

}