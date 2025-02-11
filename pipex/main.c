/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:26 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/11 18:51:34 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes.h"

/*int	all_checks(char **args)
{
	if (access(args[4], R_OK) != -1)
		return (0);
	return (1);
}*/

int	execute_command(char *args, char **env)
{
	int		i;
	char	*str;
	char	**str2;
	char	*path;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		str = ft_strnstr(env[i], "PATH=", ft_strlen("PATH="));
		if (str)
		{
			str2 = ft_split(&str[5], ':');
			while (str2[j])
			{
				path = ft_strjoin(ft_strjoin(str2[j++], "/"), ft_split(args,
							' ')[0]);
				execve(path, ft_split(args, ' '), env);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}


void child_process(t_pipex *data, char *cmd, char **env)
{
    dup2(data->fd_file1, STDIN_FILENO);   // Read from infile
    dup2(data->pipes[1], STDOUT_FILENO);  // Write to pipe
    close(data->pipes[0]);  // Close unused read end of pipe
    execute_command(cmd, env);
}

void parent_process(t_pipex *data, char *cmd, char **env)
{
    wait(NULL);  // Wait for child process to finish
    dup2(data->pipes[0], STDIN_FILENO);  // Read from pipe
    dup2(data->fd_file2, STDOUT_FILENO); // Write to outfile
    close(data->pipes[1]);  // Close unused write end of pipe
    execute_command(cmd, env);
}

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
        child_process(&data, args[2], env); // Execute cmd1
    else
        parent_process(&data, args[3], env); // Execute cmd2
	close(data.fd_file1);
	close(data.fd_file2);
	return (0);
}
