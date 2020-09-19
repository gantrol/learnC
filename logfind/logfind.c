/**
 * # LOGFIND
 * 
 * find in the log files at ~/.logfind
 * - logfind <keyword>
 * - logfind <keywords...>
 * line
 * fast


 * - logfind <keywords...> or <keywords...>
 * glob
 * ~/.logfind
 */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <glob.h>
#include "dbg.h"

#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"

#define BUFFER_SIZE 128

int match_file(char *file_name, int argc, char *argv[]) {
    printf("%s%s:\n%s", GREEN, file_name, NORMAL_COLOR);

    FILE *file;
    char buffer[BUFFER_SIZE];
    file = fopen(file_name, "r");
    check(file, "Error appeared when opening %s file", file_name);

    int index = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        index += 1;
        for (int i = 1; i < argc; i++) {
            if (strstr(buffer, argv[i]) != NULL)  {
                printf("%d:%s\n", index, buffer);
            }
        }
    }
    fclose(file);
    return 0;
error:
    if (file) {fclose(file);}
    return -1;
}

int walk_dir(char *dir_name, int argc, char *argv[]) {
    struct dirent *dir;
    char tmp[80];
    DIR *d = opendir(dir_name);
    check(d != NULL, "Could not open current directory");
    while(((dir = readdir(d)) != NULL)) {
        if (dir->d_type == DT_REG) {
            strcpy(tmp, dir_name);
            strcat(tmp, "/");
            strcat(tmp, dir->d_name);
            match_file(tmp, argc, argv);
        
        } else if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
            printf("%s%s \n", BLUE, dir->d_name);
        }
    }
    printf("%s\n", NORMAL_COLOR);
    closedir(d);
    return 0;
error:
    return -1;
}

int main(int argc, char *argv[])
{
    check(argc > 1, "USAGE: find <blob...> [-o <blob>]")
    // walk_dir(".");
    walk_dir("/home/linxz/.logfind", argc, argv);
    // walk_dir("~/.logfind");  TODO:homedir = getenv("HOME"  include <sys/types.h>

    
    return 0;
error:
    return -1;
}