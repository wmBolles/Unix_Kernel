#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // Example using the open system call to open a file.
    int file_descriptor = open("example.txt", O_RDONLY);
    if (file_descriptor == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Example using the read system call to read from the opened file.
    char buffer[100];
    ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer to treat it as a string.
    buffer[bytes_read] = '\0';
    printf("Read from file: %s\n", buffer);

    // Example using the write system call to write to a new file.
    int new_file_descriptor = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (new_file_descriptor == -1) {
        perror("open");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    // Write data to the new file.
    const char *data_to_write = "This is data to write to the file.";
    ssize_t bytes_written = write(new_file_descriptor, data_to_write, strlen(data_to_write));
    if (bytes_written == -1) {
        perror("write");
        close(file_descriptor);
        close(new_file_descriptor);
        exit(EXIT_FAILURE);
    }

    printf("Wrote %zd bytes to the file.\n", bytes_written);

    // Close both file descriptors.
    close(file_descriptor);
    close(new_file_descriptor);

    return 0;
}

