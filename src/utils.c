#include "utils.h"

// Create N files and distribute the data from the input file evenly among them
// See section 3.1 of the project writeup for important implementation details
void partition_file_data(char *input_file, int n, char *blocks_folder) {
    int FileSize;
    char buf[1024];
    for(int i; i < n; i++){
        if(i == n-1){
            FileSize = floor(size(input_file)/n) + size(input_file)%n;
        }
        else{
            FileSize = floor(size(input_file)/n);
        }
        fopen("%d.txt", 'a+', i);
        fwrite(buf, 1, FileSize);
        fseek(input_file, 0, FileSie); //Moves file pointer
    }int FileSize;
    char buf[1024];
    for(int i; i < n; i++){
        if(i == n-1){
            FileSize = floor(size(input_file)/n) + size(input_file)%n;
        }
        else{
            FileSize = floor(size(input_file)/n);
        }
        fopen("%d.txt", 'a+', i);
        fwrite(buf, 1, FileSize);
        fseek(input_file, 0, FileSie); //Moves file pointer
    }
}


// ##### DO NOT MODIFY THIS FUNCTION #####
void setup_output_directory(char *block_folder, char *hash_folder) {
    // Remove output directory
    pid_t pid = fork();
    if (pid == 0) {
        char *argv[] = {"rm", "-rf", "./output/", NULL};
        if (execvp(*argv, argv) < 0) {
            printf("ERROR: exec failed\n");
            exit(1);
        }
        exit(0);
    } else {
        wait(NULL);
    }

    sleep(1);

    // Creating output directory
    if (mkdir("output", 0777) < 0) {
        printf("ERROR: mkdir output failed\n");
        exit(1);
    }

    sleep(1);

    // Creating blocks directory
    if (mkdir(block_folder, 0777) < 0) {
        printf("ERROR: mkdir output/blocks failed\n");
        exit(1);
    }

    // Creating hashes directory
    if (mkdir(hash_folder, 0777) < 0) {
        printf("ERROR: mkdir output/hashes failed\n");
        exit(1);
    }
}