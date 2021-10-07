#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 1024

bool isVowel(char a){
  char *vowels = "aeiouAEIOU";
  for(int i = 0; i< strlen(vowels);i++){
    if(a == vowels[i]){
      return true;
    }
  }
  return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
    int counter;
    counter = 0;
    for(int i=0; i<num_chars; i++){
        if(!isVowel(in_buf[i])){
            counter++;
            out_buf[counter] = in_buf[i];
        }
    }
    return counter;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
    char* in_buf;
    char* out_buf;
    char c;
    int cCount;
    c = fgetc(inputFile);
    cCount = 1;
    while( c != EOF){
        if(!isVowel(c)){
            fputc(c, outputFile);
            c =fgetc(inputFile);
            cCount++;
        }
        else{
            c =fgetc(inputFile);
            cCount;
        }
    }
}

void copyFile(FILE* inputFile, FILE* outputFile){
    char c;
    c = fgetc(inputFile);
    while (c != EOF)
    {
        fputc(c, outputFile);
        c = fgetc(inputFile);
    }
}

int main(int argc, char *argv[]) {
    // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile, *outputFile;
    inputFile = stdin;
    outputFile = stdout;
    if(argc == 2){
        inputFile = fopen(argv[1], "r");
    }
    if(argc == 3){
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    }
    
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
