#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int num_dirs, num_regular;

//ftw calling callback on each file it reads, we then use the typeflag to
//increment the correct counter for the file/directory we found
//typeflag == 0 for regular files, and typeflag > 0 for directories
static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    if(typeflag == 0){
        num_regular++;
    }
    if(typeflag == 1 || typeflag == 2){
        num_dirs++;
    }
    return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {

    num_dirs = 0;
    num_regular = 0;

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    printf("There were %d directories.\n", num_dirs);
    printf("There were %d regular files.\n", num_regular);

    return 0;
}