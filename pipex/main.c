/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:26 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/19 15:53:53 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes.h"

void	child_process(t_pipex *data, char *cmd, char **env)
{
	dup2(data->fd_file1, STDIN_FILENO);
	dup2(data->pipes[1], STDOUT_FILENO);
	close(data->pipes[0]);
	execute_command(cmd, env);
	write_error(1);
	exit(127);
}

void	parent_process(t_pipex *data, char *cmd, char **env)
{
	dup2(data->pipes[0], STDIN_FILENO);
	dup2(data->fd_file2, STDOUT_FILENO);
	close(data->pipes[1]);
	execute_command(cmd, env);
	write_error(1);
	exit(127);
}

int	check_infile(char *filename, int *fd)
{
	if (access(filename, R_OK) == -1)
	{
		perror("Error: Unable to read the input file");
		return (-1);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (*fd);
	return (*fd);
}

int	check_outfile(char *filename, int *fd)
{
	if (access(filename, W_OK) == -1 && access(filename, F_OK) != -1)
	{
		perror("Error: Unable to write to the output file");
		return (-1);
	}
	*fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*fd < 0)
		return (*fd);
	return (*fd);
}

int	main(int count, char **args, char **env)
{
	t_pipex	data;

	if (count != 5)
		return (write_error(0));
	if (ft_strlen(args[2]) == 0 || ft_strlen(args[3]) == 0)
		return (1);
	if (pipe(data.pipes) == -1)
		return (1);
	check_infile(args[1], &data.fd_file1);
	data.pid = fork();
	if (data.pid < 0)
		return (1);
	if (data.pid == 0)
		child_process(&data, args[2], env);
	else
	{
		//wait(&data.pid);
		waitpid(data.pid, NULL, WNOHANG);
		if (check_outfile(args[4], &data.fd_file2) < 0)
			return (1);
		parent_process(&data, args[3], env);
	}
	return (0);
}
