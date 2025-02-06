/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:26 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/06 11:45:38 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes.h"

/*int	all_checks(char **args)
{
	if (access(args[4], R_OK) != -1)
		return (0);
	return (1);
}*/

int	check_infile(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (*fd); // return (error);
	return (*fd);
}

int	check_outfile(char *filename, int *fd)
{
	*fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*fd < 0)
		return (*fd); // return (error);
	return (*fd);
}

int	main(int count, char **args, char **env)
{
	t_pipex data;

	if (count != 5)
		return (0);
	if (pipe(data.pipes) == -1)
		return (0);
	if (check_infile(args[1],&data.fd_file1) < 0)
		return (0);
	if (check_outfile(args[4], &data.fd_file2) < 0)
		return (0);
	data.pid = fork();
	if (data.pid < 0)
		return (0);
	if (data.pid == 0)
		child();
	close(data.fd_file1);
	close(data.fd_file2);
	return (0);
}
