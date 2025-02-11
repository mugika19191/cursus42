#ifndef PIPES_H
# define PIPES_H
//# include <stdarg.h>
# include "lib_ft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd_file1;
	int		fd_file2;
	int		pipes[2];
	pid_t	pid;
}			t_pipex;

int			check_outfile(char *filename, int *fd);
int			check_infile(char *filename, int *fd);
// int	all_checks(char **args);

#endif