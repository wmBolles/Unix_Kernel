#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open a file in read-only mode
    int fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    // Read and print the contents of the file
    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);  // Write to the standard output
    }

    if (bytes_read == -1) {
        perror("Error reading the file");
        close(fd);
        return 1;
    }

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("Error closing the file");
        return 1;
    }

    return 0;
}

