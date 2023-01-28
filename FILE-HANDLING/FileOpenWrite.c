#include <stdio.h>
#include <string.h>

void main() {
  FILE *filePointer; // File Pointer

  char text[100] = "Hello, We are learning file Handling"; // input text

  //Opening Exixting File in write mode

  filePointer = fopen("demo.c", "w");

  // If this filePointer is Null

  if (filePointer == NULL) {
    printf("demo.c failed to open.");
  } else {

    printf("The file is now opened.\n");

    //Write the text in the file

    if (strlen(text) > 0) {
      // Writing in file
      fputs(text, filePointer);
      fputs("\n", filePointer);
    }

    // Closing the file
    fclose(filePointer);
    printf("The file is now closed.");

  }

}