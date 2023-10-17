# System Calls in Unix-like Operating Systems

In Unix-like operating systems, a system call is a fundamental interface through which user-level processes interact with the kernel, which is the core component of the operating system. System calls allow processes to request services or resources from the kernel, such as performing file operations, managing processes, and interacting with hardware devices. When a process needs to perform a privileged operation or access hardware resources, it cannot do so directly; instead, it must make a system call to the kernel.

## How System Calls Work in Unix

1. **User Process Request:** A user-level process running on the system requires a specific operation that necessitates kernel intervention, such as reading from a file, creating a new process, allocating memory, or accessing hardware devices.

2. **Process Context Switch:** The process makes a request for the desired operation by invoking a corresponding system call. At this point, the process transitions from user mode to kernel mode, involving a context switch where the CPU switches its execution context from user space to kernel space.

3. **Kernel Handling:** The kernel, running in privileged mode, receives the system call request, checks its validity and permissions, and verifies that the requested operation is allowed and that the process has the necessary privileges to perform it.

4. **Execution:** If the request is valid and authorized, the kernel performs the requested operation on behalf of the user process. This may involve accessing hardware, managing system resources, or performing other low-level tasks.

5. **Result and Return:** After executing the requested operation, the kernel returns control to the user process, typically providing the result of the system call to the process to continue its execution.

6. **Context Switch Back:** The process transitions back from kernel mode to user mode, and the CPU resumes executing the user-level code where it left off.

## Common Unix System Calls

Here are 10 common Unix system calls with simple descriptions:

- `fork()`: Creates a new process that is a copy of the calling process. It's often used for process creation.

- `exec()`: Replaces the current process with a new process image, typically used to run other programs from within a program.

- `open()`: Opens a file, returning a file descriptor that can be used for subsequent read or write operations on the file.

- `close()`: Closes a file descriptor, releasing associated resources.

- `read()`: Reads data from a file or input device into a buffer.

- `write()`: Writes data from a buffer to a file or output device.

- `kill()`: Sends a signal to a specified process or group of processes, allowing for inter-process communication and control.

- `wait()`: Suspends the calling process until one of its child processes terminates, allowing for process synchronization.

- `pipe()`: Creates an interprocess communication (IPC) pipe, allowing data to be passed between two processes.

- `malloc() / free()`: Functions for dynamic memory allocation and deallocation in C and C++ programs.

You can find an example of using the `open`, `read`, and `write` system calls in <a href="https://github.com/wmBolles/Unix_Kernel/blob/main/Docs/Core%20OS%20Concepts/syscalls/Example.c">Example.c</a>

These are just a few examples of the many system calls available in Unix-like operating systems. Each system call serves a specific purpose and provides an interface for user processes to interact with the kernel and the underlying hardware.
