/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:31:34 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/18 11:14:45 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "lib_ft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
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
int			execute_command(char *args, char **env);
void		free_all_mem(char ***str2);

#endif
