# File Descriptor Table Overview

The "fd table" refers to the file descriptor table in the context of operating systems. This table is a crucial component for managing open files and their associated information within a process.

## File Descriptor Concept

In Unix-like operating systems, everything is treated as a file. File descriptors are used to represent these files, serving as integers that uniquely identify open files in a process.

## File Descriptor Table

Each process has its own file descriptor table, an array where each entry corresponds to an open file. The file descriptor itself acts as an index into this table.

## How it Works

- **File Information:**
  - Entries in the file descriptor table contain information about open files, including file mode, current position, and references to the file in the file system.

- **Standard File Descriptors:**
  - Processes typically start with three standard file descriptors: 0 (stdin for input), 1 (stdout for output), and 2 (stderr for error output), associated with the console or terminal.

- **Opening and Closing Files:**
  - When a process opens a file (using functions like `open()`), the operating system assigns the process the lowest available file descriptor.
  - Closing a file (using `close()` system call) frees up the corresponding entry in the file descriptor table.

- **I/O Operations:**
  - System calls like `read()`, `write()`, `lseek()`, etc., use the file descriptor to identify the file for the I/O operation.

## Example Code

For a practical demonstration of the file descriptor table in C, refer to the provided [example code](src/main.c) that opens, writes to, and reads from a file.
