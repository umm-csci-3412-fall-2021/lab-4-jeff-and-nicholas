#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int num_dirs, num_regular;

bool is_dir(const char* path) {
  struct stat   buf;
  if (stat(path, &buf)==0){
    return S_ISDIR(buf.st_mode);
  }
  else{
    return false;
  }
}

void process_path(const char*);

void process_directory(const char* path) {
  DIR *dir;
  //Open directory using opendir and move into it with chdir
  dir = opendir(path);
  chdir(path);
  struct dirent *entry;
  //Using readdir to loop through each file in active directory until it runs out
  //at which point it returns NULL
  while((entry = readdir(dir)) != NULL){
    //if statement to filter out files "." and ".."
    if(strcmp(".",entry->d_name) != 0 && strcmp("..",entry->d_name) != 0){
      //"Recursive call to process path to increment the correct counter."
      process_path(entry->d_name);
    }
  }
  //Close directory and move out using closedir and chdir("..")
  closedir(dir);
  chdir("..");
}

void process_file(const char* path) {
  num_regular++;
}

void process_path(const char* path) {
  if (is_dir(path)) {
    num_dirs++;
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
