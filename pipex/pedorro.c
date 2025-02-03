#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int print_in_file()
{
    int fd;

	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	write(1,"a",1);

	return (0);
}

int    destroy_file(char *str)
{
    if (unlink(str) == 0)
		return(1);
	else
		return(0);
}

int has_access(char *str)
{
    if (access(str, R_OK) != -1)
	    return (1);
	else
		return (0);
}

int main()
{
    char *args[3];

	args[0] = "ls";
	args[1] = NULL;
	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");

	return (0);
}
