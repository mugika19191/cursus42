#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;

    // Open the file for writing (or use an existing FD)
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Redirect standard output (STDOUT) to the file using dup2
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    // Now printf will write to the file instead of the terminal
    printf("This will go to the output.txt file!\n");

    // Close the file descriptor after use
    close(fd);

    return 0;
}