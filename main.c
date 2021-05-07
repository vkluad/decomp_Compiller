#include "compiler.h"
#include "pre_reader.h"


int main(int argc, char *argv[]) {
    char filename[FILENAME_SIZE] = "";
    char new_filename[FILENAME_SIZE] = "";

    if(argc<2) {
        printf("Please enter the file name(q - quit):\n");
        scanf("%s", filename);
        if (strcmp(filename, "q") == 0)
            return 0;
    }else{
        strcpy(filename,argv[1]);
    }
    if(pre_reader(filename)==0) {
        strncpy(new_filename, filename, strlen(filename));
        strcat(new_filename, "_pre_comp");
        compiler(new_filename);
        load_to_decomp(filename);
    }else{
        return 1;
    }
    return 0;
}
