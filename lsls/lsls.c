#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Parse command line
    char *path = "./";
    int ARG_POS_PATH = 1;
    if(argc > ARG_POS_PATH)
    {
        path = argv[ARG_POS_PATH];
        // Ensure that path ends in / character
        int path_len = strlen(path);
        if(path[path_len-1] != '/')
        {
            char *full_path = malloc(path_len+1);
            strcpy(full_path, path);
            full_path[path_len] = '/';
            full_path[path_len+1] = '\0';
            path = full_path;
        }
    }
    // Open directory
    DIR * directory_file = opendir(path);
    // Handle errors opening directory
    if(directory_file == NULL)
    {
        fprintf(stdout, "Error opening directory: %s\n", path);
        exit(1);
    }
    // Repeatly read and print entries
    struct dirent * file_current;
    unsigned char file_type;
    while(1)
    {
        // Read each directory one at a time
        file_current = readdir(directory_file);
        // Exit when there are no more directories to read
        if(file_current == NULL)
        {
            break;
        }
        // Get file info
        file_type = file_current->d_type;
        // Print directories
        if(file_type == DT_DIR)
        {
            printf("     <DIR> %s\n", file_current->d_name);
        }
        // Print other file types
        else
        {
            // Get full file path (directory and file name)
            char file_path[sizeof(path)+sizeof(file_current->d_name)];
            strcpy(file_path, path);
            strcat(file_path, file_current->d_name);
            // Get stats for file
            struct stat file_stats;
            int result = stat(file_path, &file_stats);
            // Determine file size display
            long long int file_size = -1;
            if(result != -1)
            {
                file_size = file_stats.st_size;
            }
            printf("%10lld %s\n", file_size, file_current->d_name);
        }
    }
    // Close directory
    closedir(directory_file);
    return 0;
}