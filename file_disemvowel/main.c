#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 1024

//Takes a character and returns a boolean value pretaining to whether or not it's a vowel
bool isVowel(char a){
  char *vowels = "aeiouAEIOU";
  for(int i = 0; i< strlen(vowels);i++){
    if(a == vowels[i]){
      return true;
    }
  }
  return false;
}

//Loops through all characters in in_buf and copies them over, counting every time 
//a non-vowel is copied
int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
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

//Character by character checks every character in a file for whether or not it's a vowel
//Only copies non-vowels to output
void disemvowel(FILE* inputFile, FILE* outputFile) {
    char c;
    c = fgetc(inputFile);
    while( c != EOF){
        if(!isVowel(c)){
            fputc(c, outputFile);
            c =fgetc(inputFile);
        }
        else{
            c =fgetc(inputFile);
        }
    }
}

int main(int argc, char *argv[]) {
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
    
    disemvowel(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
