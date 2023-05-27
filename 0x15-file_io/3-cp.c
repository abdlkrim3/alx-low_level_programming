#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFSIZE 1024
/**
* check_argc - Check number of arguments
* @argc: Number of arguments
*/
void check_argc(int argc)
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
}
/**
* open_files - Open files
* @argv: Array of arguments
* @fd_from: Pointer to file descriptor of source file
* @fd_to: Pointer to file descriptor of destination file
*/
void open_files(char **argv, int *fd_from, int *fd_to)
{
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
*fd_from = open(argv[1], O_RDONLY);
if (*fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
*fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (*fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(*fd_from);
exit(99);
}
}
/**
* copy_file - Copy file
* @fd_from: File descriptor of source file
* @fd_to: File descriptor of destination file
* @argv: Array of arguments
*/
void copy_file(int fd_from, int fd_to, char **argv)
{
ssize_t bytes_read, bytes_written;
char buffer[BUFSIZE];
while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
close(fd_to);
exit(99);
}
}
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(fd_from);
close(fd_to);
exit(98);
}
}
/**
* close_files - Close files
* @fd_from: File descriptor of source file
* @fd_to: File descriptor of destination file
*/
void close_files(int fd_from, int fd_to)
{
if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
close(fd_to);
exit(100);
}
if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}
}
/**
* main - Entry point
* @argc: Number of arguments
* @argv: Array of arguments
*
* Return: 0 on success, exit with code on failure
*/
int main(int argc, char **argv)
{
int fd_from, fd_to;
check_argc(argc);
open_files(argv, &fd_from, &fd_to);
copy_file(fd_from, fd_to, argv);
close_files(fd_from, fd_to);
return (0);
}
