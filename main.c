#include "compiler.h"
#include "pre_reader.h"


int main(int argc, char *argv[]) {
    char filename[FILENAME_SIZE] = "";
    char new_filename[FILENAME_SIZE] = "";
    if(argc<2){
        printf("Please enter the file name(q - quit):\n");
        if(strcmp(filename,"q")==0)
            return 0;
        scanf("%s",filename);
        pre_reader(filename);
        strncpy(new_filename,filename, strlen(filename));
        strcat(new_filename,"_pre_comp");
        compiler(new_filename);
    }
    pre_reader(argv[1]);
    strncpy(new_filename,argv[1], strlen(argv[1]));
    strcat(new_filename,"_pre_comp");
    compiler(new_filename);
    return 0;
}
